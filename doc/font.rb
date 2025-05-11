# @!method initialize
#   Get the default Font
#   @param void [void]
#   @return [void]

# @!method draw
#   Draw text (using default font)
#   @param text [String]
#   @param posX [Integer]
#   @param posY [Integer]
#   @param fontSize [Integer]
#   @param color [Color]
#   @return [void]

# @!method draw_ex
#   Draw text using font and additional parameters
#   @param font [void]
#   @param text [String]
#   @param position [Vec2]
#   @param fontSize [Float]
#   @param spacing [Float]
#   @param tint [Color]
#   @return [void]

# @!method draw_pro
#   Draw text using Font and pro parameters (rotation)
#   @param font [void]
#   @param text [String]
#   @param position [Vec2]
#   @param origin [Vec2]
#   @param rotation [Float]
#   @param fontSize [Float]
#   @param spacing [Float]
#   @param tint [Color]
#   @return [void]

# @!method draw_codepoint
#   Draw one character (codepoint)
#   @param font [void]
#   @param codepoint [Integer]
#   @param position [Vec2]
#   @param fontSize [Float]
#   @param tint [Color]
#   @return [void]

# @!method draw_codepoints
#   Draw multiple character (codepoint)
#   @param font [void]
#   @param codepoints [Integer]
#   @param codepointCount [Integer]
#   @param position [Vec2]
#   @param fontSize [Float]
#   @param spacing [Float]
#   @param tint [Color]
#   @return [void]

# @!method unload
#   Unload font from GPU memory (VRAM)
#   @param font [void]
#   @return [void]

# @!method dispose
#   Unload font from GPU memory (VRAM)
#   @param font [void]
#   @return [void]

# @!method measure
#   Set vertical line spacing when drawing with line-breaks
#   @param spacing [Integer]
#   @return [void]

# @!method measure_ex
#   Measure string size for Font
#   @param font [void]
#   @param text [String]
#   @param fontSize [Float]
#   @param spacing [Float]
#   @return [Vec2]
