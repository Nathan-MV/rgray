# @!method initialize
#   Load image from file into CPU memory (RAM)auto
#   @param fileName [String]
#   @return [void]

# @!method load_raw
#   Load image from RAW file data
#   @param fileName [String]
#   @param width [Integer]
#   @param height [Integer]
#   @param format [Integer]
#   @param headerSize [Integer]
#   @return [void]

# @!method load_anim
#   @param fileName [String]
#   @param frames [Integer]
#   @return [void]

# @!method load_anim_from_memory
#   @param fileType [String]
#   @param fileData [String]
#   @param dataSize [Integer]
#   @param frames [Integer]
#   @return [void]

# @!method from_memory
#   Load image from memory buffer, fileType refers to extension: i.e. '.png'
#   @param fileType [String]
#   @param fileData [String]
#   @param dataSize [Integer]
#   @return [void]

# @!method texture=
#   Load image from GPU texture data
#   @param texture [void]
#   @return [void]

# @!method ready?
#   Check if an image is ready
#   @param image [void]
#   @return [Boolean]

# @!method from_screen
#   Load image from screen buffer and (screenshot)
#   @param void [void]
#   @return [void]

# @!method unload
#   Unload image from CPU memory (RAM)
#   @param image [void]
#   @return [void]

# @!method dispose
#   Unload image from CPU memory (RAM)
#   @param image [void]
#   @return [void]

# @!method export
#   Export image data to file, returns true on success
#   @param image [void]
#   @param fileName [String]
#   @return [Boolean]

# @!method gen_color
#   Generate image: plain color
#   @param width [Integer]
#   @param height [Integer]
#   @param color [Color]
#   @return [Color]

# @!method gen_gradient_linear
#   Generate image: linear gradient, direction in degrees [0..360], 0=Vertical gradient
#   @param width [Integer]
#   @param height [Integer]
#   @param direction [Integer]
#   @param start [Color]
#   @param end [Color]
#   @return [void]

# @!method gen_gradient_radial
#   Generate image: radial gradient
#   @param width [Integer]
#   @param height [Integer]
#   @param density [Float]
#   @param inner [Color]
#   @param outer [Color]
#   @return [void]

# @!method gen_gradient_square
#   Generate image: square gradient
#   @param width [Integer]
#   @param height [Integer]
#   @param density [Float]
#   @param inner [Color]
#   @param outer [Color]
#   @return [void]

# @!method gen_checked
#   Generate image: checked
#   @param width [Integer]
#   @param height [Integer]
#   @param checksX [Integer]
#   @param checksY [Integer]
#   @param col1 [Color]
#   @param col2 [Color]
#   @return [void]

# @!method gen_white_noise
#   Generate image: white noise
#   @param width [Integer]
#   @param height [Integer]
#   @param factor [Float]
#   @return [void]

# @!method gen_perlin_noise
#   Generate image: perlin noise
#   @param width [Integer]
#   @param height [Integer]
#   @param offsetX [Integer]
#   @param offsetY [Integer]
#   @param scale [Float]
#   @return [void]

# @!method gen_cellular
#   Generate image: cellular algorithm, bigger tileSize means bigger cells
#   @param width [Integer]
#   @param height [Integer]
#   @param tileSize [Integer]
#   @return [void]

# @!method gen_text
#   Generate image: grayscale image from text data
#   @param width [Integer]
#   @param height [Integer]
#   @param text [String]
#   @return [void]

# @!method copy
#   Create an image duplicate (useful for transformations)
#   @param image [void]
#   @return [void]

# @!method from_image
#   Create an image from another image piece
#   @param image [void]
#   @param rec [Rect]
#   @return [void]

# @!method from_channel
#   Create an image from a selected channel of another image (GRAYSCALE)
#   @param image [void]
#   @param selectedChannel [Integer]
#   @return [void]

# @!method text_default
#   Create an image from text (default font)
#   @param text [String]
#   @param fontSize [Integer]
#   @param color [Color]
#   @return [void]

# @!method text_custom
#   Create an image from text (custom sprite font)
#   @param font [void]
#   @param text [String]
#   @param fontSize [Float]
#   @param spacing [Float]
#   @param tint [Color]
#   @return [void]

# @!method format
#   Convert image data to desired format
#   @param image [Array]
#   @param newFormat [Integer]
#   @return [void]

# @!method to_pot
#   Convert image to POT (power-of-two)
#   @param image [Array]
#   @param fill [Color]
#   @return [void]

# @!method crop
#   Crop an image to a defined rectangle
#   @param image [Array]
#   @param crop [Rect]
#   @return [void]

# @!method alpha_crop
#   Crop image depending on alpha value
#   @param image [Array]
#   @param threshold [Float]
#   @return [void]

# @!method alpha_clear
#   Clear alpha channel to desired color
#   @param image [Array]
#   @param color [Color]
#   @param threshold [Float]
#   @return [void]

# @!method alpha_mask
#   Apply alpha mask to image
#   @param image [Array]
#   @param alphaMask [void]
#   @return [void]

# @!method alpha_premultiply
#   Premultiply alpha channel
#   @param image [Array]
#   @return [void]

# @!method gaussian_blur
#   Apply Gaussian blur using a box blur approximation
#   @param image [Array]
#   @param blurSize [Integer]
#   @return [void]

# @!method kernel_convolution
#   Apply custom square convolution kernel to image
#   @param image [Array]
#   @param kernel [Float]
#   @param kernelSize [Integer]
#   @return [void]

# @!method resize
#   Resize image (Bicubic scaling algorithm)
#   @param image [Array]
#   @param newWidth [Integer]
#   @param newHeight [Integer]
#   @return [void]

# @!method resize_nearest
#   Resize image (Nearest-Neighbor scaling algorithm)
#   @param image [Array]
#   @param newWidth [Integer]
#   @param newHeight [Integer]
#   @return [void]

# @!method resize_canvas
#   Resize canvas and fill with color
#   @param image [Array]
#   @param newWidth [Integer]
#   @param newHeight [Integer]
#   @param offsetX [Integer]
#   @param offsetY [Integer]
#   @param fill [Color]
#   @return [void]

# @!method mipmaps
#   Compute all mipmap levels for a provided image
#   @param image [Array]
#   @return [void]

# @!method dither
#   Dither image data to 16bpp or lower (Floyd-Steinberg dithering)
#   @param image [Array]
#   @param rBpp [Integer]
#   @param gBpp [Integer]
#   @param bBpp [Integer]
#   @param aBpp [Integer]
#   @return [void]

# @!method flip_v
#   Flip image vertically
#   @param image [Array]
#   @return [void]

# @!method flip_h
#   Flip image horizontally
#   @param image [Array]
#   @return [void]

# @!method rotate
#   Rotate image by input angle in degrees (-359 to 359)
#   @param image [Array]
#   @param degrees [Integer]
#   @return [void]

# @!method rotate_cw
#   Rotate image clockwise 90deg
#   @param image [Array]
#   @return [void]

# @!method rotate_ccw
#   Rotate image counter-clockwise 90deg
#   @param image [Array]
#   @return [void]

# @!method tint
#   Modify image color: tint
#   @param image [Array]
#   @param color [Color]
#   @return [Color]

# @!method color_invert
#   Modify image color: invert
#   @param image [Array]
#   @return [Color]

# @!method grayscale
#   Modify image color: grayscale
#   @param image [Array]
#   @return [Color]

# @!method brightness
#   Modify image color: brightness (-255 to 255)
#   @param image [Array]
#   @param brightness [Integer]
#   @return [Color]

# @!method color_replace
#   Modify image color: replace color
#   @param image [Array]
#   @param color [Color]
#   @param replace [Color]
#   @return [Color]

# @!method load_colors
#   Load color data from image as a Color array (RGBA - 32bit)
#   @param image [void]
#   @return [Array]

# @!method load_palette
#   Load colors palette from image as a Color array (RGBA - 32bit)
#   @param image [void]
#   @param maxPaletteSize [Integer]
#   @param colorCount [Integer]
#   @return [Array]

# @!method unload_colors
#   Unload color data loaded with LoadImageColors()
#   @param colors [Array]
#   @return [Color]

# @!method unload_palette
#   Unload colors palette loaded with LoadImagePalette()
#   @param colors [Array]
#   @return [void]

# @!method alpha_border
#   Get image alpha border rectangle
#   @param image [void]
#   @param threshold [Float]
#   @return [Rect]

# @!method color
#   Get image pixel color at (x, y) position
#   @param image [void]
#   @param x [Integer]
#   @param y [Integer]
#   @return [Color]

# @!method clear_background
#   Clear image background with given color
#   @param dst [Array]
#   @param color [Color]
#   @return [void]

# @!method draw_pixel
#   Draw pixel within an image
#   @param dst [Array]
#   @param posX [Integer]
#   @param posY [Integer]
#   @param color [Color]
#   @return [void]

# @!method draw_pixel_v
#   Draw pixel within an image (Vector version)
#   @param dst [Array]
#   @param position [Vec2]
#   @param color [Color]
#   @return [void]

# @!method draw_line
#   Draw line within an image
#   @param dst [Array]
#   @param startPosX [Integer]
#   @param startPosY [Integer]
#   @param endPosX [Integer]
#   @param endPosY [Integer]
#   @param color [Color]
#   @return [void]

# @!method draw_line_v
#   Draw line within an image (Vector version)
#   @param dst [Array]
#   @param start [Vec2]
#   @param end [Vec2]
#   @param color [Color]
#   @return [void]

# @!method draw_line_ex
#   Draw a line defining thickness within an image
#   @param dst [Array]
#   @param start [Vec2]
#   @param end [Vec2]
#   @param thick [Integer]
#   @param color [Color]
#   @return [void]

# @!method draw_circle
#   Draw a filled circle within an image
#   @param dst [Array]
#   @param centerX [Integer]
#   @param centerY [Integer]
#   @param radius [Integer]
#   @param color [Color]
#   @return [void]

# @!method draw_circle_v
#   Draw a filled circle within an image (Vector version)
#   @param dst [Array]
#   @param center [Vec2]
#   @param radius [Integer]
#   @param color [Color]
#   @return [void]

# @!method draw_circle_lines
#   Draw circle outline within an image
#   @param dst [Array]
#   @param centerX [Integer]
#   @param centerY [Integer]
#   @param radius [Integer]
#   @param color [Color]
#   @return [void]

# @!method draw_circle_lines_v
#   Draw circle outline within an image (Vector version)
#   @param dst [Array]
#   @param center [Vec2]
#   @param radius [Integer]
#   @param color [Color]
#   @return [void]

# @!method draw_rectangle
#   Draw rectangle within an image
#   @param dst [Array]
#   @param posX [Integer]
#   @param posY [Integer]
#   @param width [Integer]
#   @param height [Integer]
#   @param color [Color]
#   @return [Rect]

# @!method draw_rectangle_v
#   Draw rectangle within an image (Vector version)
#   @param dst [Array]
#   @param position [Vec2]
#   @param size [Vec2]
#   @param color [Color]
#   @return [Rect]

# @!method draw_rectangle_rec
#   Draw rectangle within an image
#   @param dst [Array]
#   @param rec [Rect]
#   @param color [Color]
#   @return [Rect]

# @!method draw_rectangle_lines
#   Draw rectangle lines within an image
#   @param dst [Array]
#   @param rec [Rect]
#   @param thick [Integer]
#   @param color [Color]
#   @return [Rect]

# @!method draw_triangle
#   Draw triangle within an image
#   @param dst [Array]
#   @param v1 [Vec2]
#   @param v2 [Vec2]
#   @param v3 [Vec2]
#   @param color [Color]
#   @return [void]

# @!method draw_triangle_ex
#   Draw triangle with interpolated colors within an image
#   @param dst [Array]
#   @param v1 [Vec2]
#   @param v2 [Vec2]
#   @param v3 [Vec2]
#   @param c1 [Color]
#   @param c2 [Color]
#   @param c3 [Color]
#   @return [void]

# @!method draw_triangle_lines
#   Draw triangle outline within an image
#   @param dst [Array]
#   @param v1 [Vec2]
#   @param v2 [Vec2]
#   @param v3 [Vec2]
#   @param color [Color]
#   @return [void]

# @!method draw_triangle_fan
#   Draw a triangle fan defined by points within an image (first vertex is the center)
#   @param dst [Array]
#   @param points [Array]
#   @param pointCount [Integer]
#   @param color [Color]
#   @return [void]

# @!method draw_triangle_strip
#   Draw a triangle strip defined by points within an image
#   @param dst [Array]
#   @param points [Array]
#   @param pointCount [Integer]
#   @param color [Color]
#   @return [void]

# @!method draw
#   Draw pixel within an image
#   @param dst [Array]
#   @param posX [Integer]
#   @param posY [Integer]
#   @param color [Color]
#   @return [void]

# @!method draw_text
#   Draw text (using default font) within an image (destination)
#   @param dst [Array]
#   @param text [String]
#   @param posX [Integer]
#   @param posY [Integer]
#   @param fontSize [Integer]
#   @param color [Color]
#   @return [void]

# @!method draw_text_ex
#   Draw text (custom sprite font) within an image (destination)
#   @param dst [Array]
#   @param font [void]
#   @param text [String]
#   @param position [Vec2]
#   @param fontSize [Float]
#   @param spacing [Float]
#   @param tint [Color]
#   @return [void]
