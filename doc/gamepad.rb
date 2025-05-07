# @!method available?
#   Check if a gamepad is available
#   @param gamepad [Integer]
#   @return [Boolean]

# @!method name
#   @return [void]

# @!method button_pressed?
#   Check if a gamepad button has been pressed once
#   @param gamepad [Integer]
#   @param button [Integer]
#   @return [Boolean]

# @!method button_down?
#   Check if a gamepad button is being pressed
#   @param gamepad [Integer]
#   @param button [Integer]
#   @return [Boolean]

# @!method button_released?
#   Check if a gamepad button has been released once
#   @param gamepad [Integer]
#   @param button [Integer]
#   @return [Boolean]

# @!method button_up?
#   Check if a gamepad button is NOT being pressed
#   @param gamepad [Integer]
#   @param button [Integer]
#   @return [Boolean]

# @!method button_pressed
#   Get the last gamepad button pressed
#   @param void [void]
#   @return [Integer]

# @!method axis_count
#   Get gamepad axis count for a gamepad
#   @param gamepad [Integer]
#   @return [Integer]

# @!method axis_movement
#   Get axis movement value for a gamepad axis
#   @param gamepad [Integer]
#   @param axis [Integer]
#   @return [Float]

# @!method mappings=
#   Set internal gamepad mappings (SDL_GameControllerDB)
#   @param mappings [String]
#   @return [Integer]

# @!method vibration=
#   Set gamepad vibration for both motors (duration in seconds)
#   @param gamepad [Integer]
#   @param leftMotor [Float]
#   @param rightMotor [Float]
#   @param duration [Float]
#   @return [void]

# @!parse BUTTON_UNKNOWN = 0
#   @return [Integer]

# @!parse BUTTON_LEFT_FACE_UP = 1
#   @return [Integer]

# @!parse BUTTON_LEFT_FACE_RIGHT = 2
#   @return [Integer]

# @!parse BUTTON_LEFT_FACE_DOWN = 3
#   @return [Integer]

# @!parse BUTTON_LEFT_FACE_LEFT = 4
#   @return [Integer]

# @!parse BUTTON_RIGHT_FACE_UP = 5
#   @return [Integer]

# @!parse BUTTON_RIGHT_FACE_RIGHT = 6
#   @return [Integer]

# @!parse BUTTON_RIGHT_FACE_DOWN = 7
#   @return [Integer]

# @!parse BUTTON_RIGHT_FACE_LEFT = 8
#   @return [Integer]

# @!parse BUTTON_LEFT_TRIGGER_1 = 9
#   @return [Integer]

# @!parse BUTTON_LEFT_TRIGGER_2 = 10
#   @return [Integer]

# @!parse BUTTON_RIGHT_TRIGGER_1 = 11
#   @return [Integer]

# @!parse BUTTON_RIGHT_TRIGGER_2 = 12
#   @return [Integer]

# @!parse BUTTON_MIDDLE_LEFT = 13
#   @return [Integer]

# @!parse BUTTON_MIDDLE = 14
#   @return [Integer]

# @!parse BUTTON_MIDDLE_RIGHT = 15
#   @return [Integer]

# @!parse BUTTON_LEFT_THUMB = 16
#   @return [Integer]

# @!parse BUTTON_RIGHT_THUMB = 17
#   @return [Integer]

# @!parse AXIS_LEFT_X = 0
#   @return [Integer]

# @!parse AXIS_LEFT_Y = 1
#   @return [Integer]

# @!parse AXIS_RIGHT_X = 2
#   @return [Integer]

# @!parse AXIS_RIGHT_Y = 3
#   @return [Integer]

# @!parse AXIS_LEFT_TRIGGER = 4
#   @return [Integer]

# @!parse AXIS_RIGHT_TRIGGER = 5
#   @return [Integer]
