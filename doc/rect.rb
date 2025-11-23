# @!method initialize
#   @return [void]

# @!method x
#   @return [void]

# @!method y
#   @return [void]

# @!method width
#   @return [void]

# @!method height
#   @return [void]

# @!method x=
#   @return [void]

# @!method y=
#   @return [void]

# @!method width=
#   @return [void]

# @!method height=
#   @return [void]

# @!method draw
#   Draw a color-filled rectangle
#   @param posX [Integer]
#   @param posY [Integer]
#   @param width [Integer]
#   @param height [Integer]
#   @param color [Color]
#   @return [Rect]

# @!method draw_pro
#   Draw a color-filled rectangle with pro parameters
#   @param rec [Rect]
#   @param origin [Vec2]
#   @param rotation [Float]
#   @param color [Color]
#   @return [Rect]

# @!method draw_gradient_vertical
#   Draw a vertical-gradient-filled rectangle
#   @param posX [Integer]
#   @param posY [Integer]
#   @param width [Integer]
#   @param height [Integer]
#   @param top [Color]
#   @param bottom [Color]
#   @return [Rect]

# @!method draw_gradient_horizontal
#   Draw a horizontal-gradient-filled rectangle
#   @param posX [Integer]
#   @param posY [Integer]
#   @param width [Integer]
#   @param height [Integer]
#   @param left [Color]
#   @param right [Color]
#   @return [Rect]

# @!method draw_gradient_ex
#   Draw a gradient-filled rectangle with custom vertex colors
#   @param rec [Rect]
#   @param topLeft [Color]
#   @param bottomLeft [Color]
#   @param bottomRight [Color]
#   @param topRight [Color]
#   @return [Rect]

# @!method draw_lines
#   Draw rectangle outline
#   @param posX [Integer]
#   @param posY [Integer]
#   @param width [Integer]
#   @param height [Integer]
#   @param color [Color]
#   @return [Rect]

# @!method draw_lines_ex
#   Draw rectangle outline with extended parameters
#   @param rec [Rect]
#   @param lineThick [Float]
#   @param color [Color]
#   @return [Rect]

# @!method draw_rounded
#   Draw rectangle with rounded edges
#   @param rec [Rect]
#   @param roundness [Float]
#   @param segments [Integer]
#   @param color [Color]
#   @return [Rect]

# @!method draw_rounded_lines
#   Draw rectangle lines with rounded edges
#   @param rec [Rect]
#   @param roundness [Float]
#   @param segments [Integer]
#   @param color [Color]
#   @return [Rect]

# @!method draw_rounded_lines_ex
#   Draw rectangle with rounded edges outline
#   @param rec [Rect]
#   @param roundness [Float]
#   @param segments [Integer]
#   @param lineThick [Float]
#   @param color [Color]
#   @return [Rect]

# @!method collides?
#   Check collision between two rectangles
#   @param rec1 [Rect]
#   @param rec2 [Rect]
#   @return [Boolean]

# @!method point?
#   Check if point is inside rectangle
#   @param point [Vec2]
#   @param rec [Rect]
#   @return [Boolean]

# @!method collide_area
#   Get collision rectangle for two rectangles collision
#   @param rec1 [Rect]
#   @param rec2 [Rect]
#   @return [Rect]
