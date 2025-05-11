# @!method initialize
#   @return [void]

# @!method draw_sector
#   Draw a piece of a circle
#   @param center [Vec2]
#   @param radius [Float]
#   @param startAngle [Float]
#   @param endAngle [Float]
#   @param segments [Integer]
#   @param color [Color]
#   @return [void]

# @!method draw_sector_lines
#   Draw circle sector outline
#   @param center [Vec2]
#   @param radius [Float]
#   @param startAngle [Float]
#   @param endAngle [Float]
#   @param segments [Integer]
#   @param color [Color]
#   @return [void]

# @!method draw_gradient
#   Draw a gradient-filled circle
#   @param centerX [Integer]
#   @param centerY [Integer]
#   @param radius [Float]
#   @param inner [Color]
#   @param outer [Color]
#   @return [void]

# @!method draw
#   Draw a piece of a circle
#   @param center [Vec2]
#   @param radius [Float]
#   @param startAngle [Float]
#   @param endAngle [Float]
#   @param segments [Integer]
#   @param color [Color]
#   @return [void]

# @!method draw_lines
#   Draw circle outline (Vector version)
#   @param center [Vec2]
#   @param radius [Float]
#   @param color [Color]
#   @return [void]

# @!method collides?
#   Check collision between two circles
#   @param center1 [Vec2]
#   @param radius1 [Float]
#   @param center2 [Vec2]
#   @param radius2 [Float]
#   @return [Boolean]

# @!method collides_rec?
#   Check collision between circle and rectangle
#   @param center [Vec2]
#   @param radius [Float]
#   @param rec [Rect]
#   @return [Boolean]

# @!method collides_point?
#   Check if point is inside circle
#   @param point [Vec2]
#   @param center [Vec2]
#   @param radius [Float]
#   @return [Boolean]

# @!method collides_line?
#   Check if circle collides with a line created betweeen two points [p1] and [p2]
#   @param center [Vec2]
#   @param radius [Float]
#   @param p1 [Vec2]
#   @param p2 [Vec2]
#   @return [Boolean]
