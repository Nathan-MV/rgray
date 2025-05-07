# @!method button_pressed?
#   Check if a mouse button has been pressed once
#   @param button [Integer]
#   @return [Boolean]

# @!method button_down?
#   Check if a mouse button is being pressed
#   @param button [Integer]
#   @return [Boolean]

# @!method button_released?
#   Check if a mouse button has been released once
#   @param button [Integer]
#   @return [Boolean]

# @!method button_up?
#   Check if a mouse button is NOT being pressed
#   @param button [Integer]
#   @return [Boolean]

# @!method x
#   Get mouse position X
#   @param void [void]
#   @return [Integer]

# @!method y
#   Get mouse position Y
#   @param void [void]
#   @return [Integer]

# @!method position
#   Get mouse position XY
#   @param void [void]
#   @return [Vec2]

# @!method delta
#   Get mouse delta between frames
#   @param void [void]
#   @return [Vec2]

# @!method position=
#   Set mouse position XY
#   @param x [Integer]
#   @param y [Integer]
#   @return [void]

# @!method offset=
#   Set mouse offset
#   @param offsetX [Integer]
#   @param offsetY [Integer]
#   @return [void]

# @!method scale=
#   Set mouse scaling
#   @param scaleX [Float]
#   @param scaleY [Float]
#   @return [void]

# @!method wheel_move
#   Get mouse wheel movement for X or Y, whichever is larger
#   @param void [void]
#   @return [Float]

# @!method wheel_move_v
#   Get mouse wheel movement for X or Y, whichever is larger
#   @param void [void]
#   @return [Float]

# @!method cursor=
#   Set mouse cursor
#   @param cursor [Integer]
#   @return [void]

# @!parse BUTTON_LEFT = 0
#   @return [Integer]

# @!parse BUTTON_RIGHT = 1
#   @return [Integer]

# @!parse BUTTON_MIDDLE = 2
#   @return [Integer]

# @!parse BUTTON_SIDE = 3
#   @return [Integer]

# @!parse BUTTON_EXTRA = 4
#   @return [Integer]

# @!parse BUTTON_FORWARD = 5
#   @return [Integer]

# @!parse BUTTON_BACK = 6
#   @return [Integer]

# @!parse CURSOR_DEFAULT = 0
#   @return [Integer]

# @!parse CURSOR_ARROW = 1
#   @return [Integer]

# @!parse CURSOR_IBEAM = 2
#   @return [Integer]

# @!parse CURSOR_CROSSHAIR = 3
#   @return [Integer]

# @!parse CURSOR_POINTING_HAND = 4
#   @return [Integer]

# @!parse CURSOR_RESIZE_EW = 5
#   @return [Integer]

# @!parse CURSOR_RESIZE_NS = 6
#   @return [Integer]

# @!parse CURSOR_RESIZE_NWSE = 7
#   @return [Integer]

# @!parse CURSOR_RESIZE_NESW = 8
#   @return [Integer]

# @!parse CURSOR_RESIZE_ALL = 9
#   @return [Integer]

# @!parse CURSOR_NOT_ALLOWED = 10
#   @return [Integer]
