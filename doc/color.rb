# @!method initialize
#   @return [void]

# @!method r
#   @return [void]

# @!method red
#   @return [void]

# @!method g
#   @return [void]

# @!method green
#   @return [void]

# @!method b
#   @return [void]

# @!method blue
#   @return [void]

# @!method a
#   @return [void]

# @!method alpha
#   @return [void]

# @!method r=
#   @return [void]

# @!method red=
#   @return [void]

# @!method g=
#   @return [void]

# @!method green=
#   @return [void]

# @!method b=
#   @return [void]

# @!method blue=
#   @return [void]

# @!method a=
#   @return [void]

# @!method alpha=
#   @return [void]

# @!method eql?
#   Check if two colors are equal
#   @param col1 [Color]
#   @param col2 [Color]
#   @return [Boolean]

# @!method fade
#   Get color with alpha applied, alpha goes from 0.0f to 1.0f
#   @param color [Color]
#   @param alpha [Float]
#   @return [Color]

# @!method to_int
#   Get hexadecimal value for a Color (0xRRGGBBAA)
#   @param color [Color]
#   @return [Integer]

# @!method normalize
#   Get Color from normalized values [0..1]
#   @param normalized [Vec4]
#   @return [Color]

# @!method to_hsv
#   Get HSV values for a Color, hue [0..360], saturation/value [0..1]
#   @param color [Color]
#   @return [Color]

# @!method tint
#   Get color multiplied with another color
#   @param color [Color]
#   @param tint [Color]
#   @return [Color]

# @!method brightness
#   Get color with brightness correction, brightness factor goes from -1.0f to 1.0f
#   @param color [Color]
#   @param factor [Float]
#   @return [Color]

# @!method contrast
#   Get color with contrast correction, contrast values between -1.0f and 1.0f
#   @param color [Color]
#   @param contrast [Float]
#   @return [Color]

# @!method alpha_blend
#   Get src alpha-blended into dst color with tint
#   @param dst [Color]
#   @param src [Color]
#   @param tint [Color]
#   @return [Color]

# @!method blend
#   Get src alpha-blended into dst color with tint
#   @param dst [Color]
#   @param src [Color]
#   @param tint [Color]
#   @return [Color]

# @!method lerp
#   Mix 2 Colors Together
#   @param color1 [Color]
#   @param color2 [Color]
#   @param d [Float]
#   @return [Color]

# @!method pixel_color
#   Get Color from a source pixel pointer of certain format
#   @param srcPtr [Array]
#   @param format [Integer]
#   @return [Color]

# @!method set_pixel_color
#   Set color formatted into destination pixel pointer
#   @param dstPtr [Array]
#   @param color [Color]
#   @param format [Integer]
#   @return [Color]

# @!method pixel_data_size
#   Get pixel data size in bytes for certain format
#   @param width [Integer]
#   @param height [Integer]
#   @param format [Integer]
#   @return [Integer]

# @!method luminance
#   @return [void]
