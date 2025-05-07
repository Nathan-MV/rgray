require 'fileutils'

input_files = ARGV
output_dir = File.join(__dir__, '..', 'doc')
FileUtils.mkdir_p(output_dir)

def infer_type(param)
  case param
  when /char\s*\*|const\s+char\s*\*/i then 'String'
  when /\bint\b|\bunsigned\s+int\b|\bINT2NUM\b|\bFIX2INT\b|\bUINT2NUM\b|\bNUM2INT\b/   then 'Integer'
  when /\bfloat\b|\bdouble\b|\bDBL2NUM\b|\bNUM2FLT\b/         then 'Float'
  when /\bbool\b|\bTRUE\b|\bFALSE\b|\bQtrue\b|\bQfalse\b/                     then 'Boolean'
  when /\bconst\s+\w+\s*\*\*/         then 'Array'
  when /\b\w+\[\]|\b\w+\s*\*/         then 'Array'
  when /Color/ then 'Color'
  when /Vector2/ then 'Vec2'
  when /Vector3/ then 'Vec3'
  when /Vector4/ then 'Vec4'
  when /Rect/ then 'Rect'
  else 'void'
  end
end

def extract_params(signature)
  return [] unless signature && (match = signature.match(/\((.*?)\)/))
  match[1].split(',').map(&:strip).reject { |p| p =~ /\bself\b/ }.map do |p|
    name = p.split.last.sub(/^\*/, '')
    { name: name, type: infer_type(p) }
  end
end

def extract_description(line)
  return "" unless line
  line.split('//').drop(2).join('//').strip
end

BINDING_REGEX = %r{
  (?<comment_block>(?:\s*//[^\n]*\n)*)
  \s*rb_define_(?<type>\w+)\s*\(
    \s*(?<class>[^,]+),\s*
    "(?<ruby_name>[^"]+)",\s*
    (?<c_wrapper>\w+),\s*
    (?<argc>[^)]+)
  \)
}x

CONST_REGEX = /
  rb_define_const\s*\(
    \s*(?<klass>[^,]+),\s*
    "(?<const_name>[^"]+)",\s*
    (?<const_value>[^)]+)
  \)
/x

MACRO_REGEX = /RB_METHOD.*\(\s*(?<wrapper>\w+)\s*,\s*(?<real_func>\w+)\s*,.*\)/

input_files.each do |input_file|
  output = []
  c_code = File.read(input_file)

  c_code.scan(BINDING_REGEX) do |comment_block, type, klass, ruby_name, c_wrapper, argc|
    macro_line = c_code.lines.find { |l| (l.include?("RB_METHOD") || l.include?("static")) && l.include?(c_wrapper) }
    next unless macro_line

    idx = c_code.lines.find_index(macro_line)
    comments = c_code.lines[0...idx].reverse.take_while { |l| l =~ /^\s*\/\// }.reverse
    sig_line = comments.find { |l| l =~ /\/\/\s*(?:\w+\s+)*\w+\s+\w+\s*\(.*\)/ }

    params = extract_params(sig_line)
    description = extract_description(sig_line)

    inferred_type = sig_line ? infer_type(sig_line.split('(').first.strip) : 'void'

    output << "# @!method #{ruby_name}"
    output << "#   #{description}" unless description.empty?
    params.each { |p| output << "#   @param #{p[:name]} [#{p[:type]}]" }
    output << "#   @return [#{inferred_type}]\n"
  end

  c_code.scan(CONST_REGEX) do |klass, const_name, const_value|
    match = const_value.match(/\w\((\d+)/)
    literal = match ? match[1] : const_value
    inferred_type = infer_type(const_value)

    output << "# @!parse #{const_name} = #{literal}"
    output << "#   @return [#{inferred_type}]\n"
  end

  base_name = File.basename(input_file, File.extname(input_file)).sub(/_bindings$/, '')
  out_file = File.join(output_dir, "#{base_name}.rb")
  File.write(out_file, output.join("\n"))
end
