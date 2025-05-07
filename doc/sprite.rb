# @!method initialize
#   @param VRAM [void]
#   @return [void]

# @!method width
#   @return [void]

# @!method height
#   @return [void]

# @!method mipmaps
#   @return [void]

# @!method format
#   @return [void]

# @!method bitmap=
#   Load texture from image data
#   @param image [void]
#   @return [void]

# @!method load_cubemap
#   Load cubemap from image, multiple image cubemap layouts supported
#   @param image [void]
#   @param layout [Integer]
#   @return [void]

# @!method ready?
#   Check if a texture is ready
#   @param texture [void]
#   @return [Boolean]

# @!method unload
#   @param VRAM [void]
#   @return [void]

# @!method dispose
#   @param VRAM [void]
#   @return [void]

# @!method update
#   Update GPU texture with new data
#   @param texture [void]
#   @param pixels [Array]
#   @return [void]

# @!method update_rect
#   Update GPU texture rectangle with new data
#   @param texture [void]
#   @param rec [Rect]
#   @param pixels [Array]
#   @return [void]

# @!method gen_mipmaps
#   Generate GPU mipmaps for a texture
#   @param texture [void]
#   @return [void]

# @!method filter=
#   Set texture scaling filter mode
#   @param texture [void]
#   @param filter [Integer]
#   @return [void]

# @!method wrap=
#   Set texture wrapping mode
#   @param texture [void]
#   @param wrap [Integer]
#   @return [void]

# @!method draw
#   Draw a Texture2D with extended parameters
#   @param texture [void]
#   @param position [Vec2]
#   @param rotation [Float]
#   @param scale [Float]
#   @param tint [Color]
#   @return [void]

# @!method draw_rect
#   @return [void]

# @!method draw_pro
#   @return [void]

# @!method scale=
#   @return [void]

# @!method load=
#   Load texture from image data
#   @param image [void]
#   @return [void]
