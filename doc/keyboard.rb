# @!method pressed?
#   Check if a key has been pressed once
#   @param key [Integer]
#   @return [Boolean]

# @!method repeat?
#   Check if a key has been pressed again (Only PLATFORM_DESKTOP)
#   @param key [Integer]
#   @return [Boolean]

# @!method down?
#   Check if a key is being pressed
#   @param key [Integer]
#   @return [Boolean]

# @!method released?
#   Check if a key has been released once
#   @param key [Integer]
#   @return [Boolean]

# @!method up?
#   Check if a key is NOT being pressed
#   @param key [Integer]
#   @return [Boolean]

# @!method pressed
#   Get key pressed (keycode), call it multiple times for keys queued, returns 0 when the queue is empty
#   @param void [void]
#   @return [Integer]

# @!method char_pressed
#   Get char pressed (unicode), call it multiple times for chars queued, returns 0 when the queue is empty
#   @param void [void]
#   @return [Integer]

# @!method key_name
#   Get name of a QWERTY key on the current keyboard layout (eg returns string 'q' for KEY_A on an AZERTY keyboard)
#   @param key [Integer]
#   @return [String]

# @!method clipboard_text=
#   Set clipboard text content
#   @param text [String]
#   @return [void]

# @!method clipboard_text
#   @return [void]

# @!method clipboard_image
#   Get clipboard image content
#   @param void [void]
#   @return [void]

# @!parse NULL = 0
#   @return [Integer]

# @!parse APOSTROPHE = 39
#   @return [Integer]

# @!parse COMMA = 44
#   @return [Integer]

# @!parse MINUS = 45
#   @return [Integer]

# @!parse PERIOD = 46
#   @return [Integer]

# @!parse SLASH = 47
#   @return [Integer]

# @!parse ZERO = 48
#   @return [Integer]

# @!parse ONE = 49
#   @return [Integer]

# @!parse TWO = 50
#   @return [Integer]

# @!parse THREE = 51
#   @return [Integer]

# @!parse FOUR = 52
#   @return [Integer]

# @!parse FIVE = 53
#   @return [Integer]

# @!parse SIX = 54
#   @return [Integer]

# @!parse SEVEN = 55
#   @return [Integer]

# @!parse EIGHT = 56
#   @return [Integer]

# @!parse NINE = 57
#   @return [Integer]

# @!parse SEMICOLON = 59
#   @return [Integer]

# @!parse EQUAL = 61
#   @return [Integer]

# @!parse A = 65
#   @return [Integer]

# @!parse B = 66
#   @return [Integer]

# @!parse C = 67
#   @return [Integer]

# @!parse D = 68
#   @return [Integer]

# @!parse E = 69
#   @return [Integer]

# @!parse F = 70
#   @return [Integer]

# @!parse G = 71
#   @return [Integer]

# @!parse H = 72
#   @return [Integer]

# @!parse I = 73
#   @return [Integer]

# @!parse J = 74
#   @return [Integer]

# @!parse K = 75
#   @return [Integer]

# @!parse L = 76
#   @return [Integer]

# @!parse M = 77
#   @return [Integer]

# @!parse N = 78
#   @return [Integer]

# @!parse O = 79
#   @return [Integer]

# @!parse P = 80
#   @return [Integer]

# @!parse Q = 81
#   @return [Integer]

# @!parse R = 82
#   @return [Integer]

# @!parse S = 83
#   @return [Integer]

# @!parse T = 84
#   @return [Integer]

# @!parse U = 85
#   @return [Integer]

# @!parse V = 86
#   @return [Integer]

# @!parse W = 87
#   @return [Integer]

# @!parse X = 88
#   @return [Integer]

# @!parse Y = 89
#   @return [Integer]

# @!parse Z = 90
#   @return [Integer]

# @!parse LEFT_BRACKET = 91
#   @return [Integer]

# @!parse BACKSLASH = 92
#   @return [Integer]

# @!parse RIGHT_BRACKET = 93
#   @return [Integer]

# @!parse GRAVE = 96
#   @return [Integer]

# @!parse SPACE = 32
#   @return [Integer]

# @!parse ESCAPE = 256
#   @return [Integer]

# @!parse ENTER = 257
#   @return [Integer]

# @!parse TAB = 258
#   @return [Integer]

# @!parse BACKSPACE = 259
#   @return [Integer]

# @!parse INSERT = 260
#   @return [Integer]

# @!parse DELETE = 261
#   @return [Integer]

# @!parse RIGHT = 262
#   @return [Integer]

# @!parse LEFT = 263
#   @return [Integer]

# @!parse DOWN = 264
#   @return [Integer]

# @!parse UP = 265
#   @return [Integer]

# @!parse PAGE_UP = 266
#   @return [Integer]

# @!parse PAGE_DOWN = 267
#   @return [Integer]

# @!parse HOME = 268
#   @return [Integer]

# @!parse END = 269
#   @return [Integer]

# @!parse CAPS_LOCK = 280
#   @return [Integer]

# @!parse SCROLL_LOCK = 281
#   @return [Integer]

# @!parse NUM_LOCK = 282
#   @return [Integer]

# @!parse PRINT_SCREEN = 283
#   @return [Integer]

# @!parse PAUSE = 284
#   @return [Integer]

# @!parse F1 = 290
#   @return [Integer]

# @!parse F2 = 291
#   @return [Integer]

# @!parse F3 = 292
#   @return [Integer]

# @!parse F4 = 293
#   @return [Integer]

# @!parse F5 = 294
#   @return [Integer]

# @!parse F6 = 295
#   @return [Integer]

# @!parse F7 = 296
#   @return [Integer]

# @!parse F8 = 297
#   @return [Integer]

# @!parse F9 = 298
#   @return [Integer]

# @!parse F10 = 299
#   @return [Integer]

# @!parse F11 = 300
#   @return [Integer]

# @!parse F12 = 301
#   @return [Integer]

# @!parse LEFT_SHIFT = 340
#   @return [Integer]

# @!parse LEFT_CONTROL = 341
#   @return [Integer]

# @!parse LEFT_ALT = 342
#   @return [Integer]

# @!parse LEFT_SUPER = 343
#   @return [Integer]

# @!parse RIGHT_SHIFT = 344
#   @return [Integer]

# @!parse RIGHT_CONTROL = 345
#   @return [Integer]

# @!parse RIGHT_ALT = 346
#   @return [Integer]

# @!parse RIGHT_SUPER = 347
#   @return [Integer]

# @!parse KB_MENU = 348
#   @return [Integer]

# @!parse KP_0 = 320
#   @return [Integer]

# @!parse KP_1 = 321
#   @return [Integer]

# @!parse KP_2 = 322
#   @return [Integer]

# @!parse KP_3 = 323
#   @return [Integer]

# @!parse KP_4 = 324
#   @return [Integer]

# @!parse KP_5 = 325
#   @return [Integer]

# @!parse KP_6 = 326
#   @return [Integer]

# @!parse KP_7 = 327
#   @return [Integer]

# @!parse KP_8 = 328
#   @return [Integer]

# @!parse KP_9 = 329
#   @return [Integer]

# @!parse KP_DECIMAL = 330
#   @return [Integer]

# @!parse KP_DIVIDE = 331
#   @return [Integer]

# @!parse KP_MULTIPLY = 332
#   @return [Integer]

# @!parse KP_SUBTRACT = 333
#   @return [Integer]

# @!parse KP_ADD = 334
#   @return [Integer]

# @!parse KP_ENTER = 335
#   @return [Integer]

# @!parse KP_EQUAL = 336
#   @return [Integer]

# @!parse BACK = 4
#   @return [Integer]

# @!parse MENU = 5
#   @return [Integer]

# @!parse VOLUME_UP = 24
#   @return [Integer]

# @!parse VOLUME_DOWN = 25
#   @return [Integer]
