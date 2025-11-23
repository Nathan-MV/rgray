# @!method init
#   Initialize window and OpenGL context
#   @param width [Integer]
#   @param height [Integer]
#   @param title [String]
#   @return [void]

# @!method close
#   Close window and unload OpenGL context
#   @param void [void]
#   @return [void]

# @!method should_close?
#   Check if application should close (KEY_ESCAPE pressed or windows close icon clicked)
#   @param void [void]
#   @return [Boolean]

# @!method ready?
#   Check if window has been initialized successfully
#   @param void [void]
#   @return [Boolean]

# @!method fullscreen?
#   Check if window is currently fullscreen
#   @param void [void]
#   @return [Boolean]

# @!method hidden?
#   Check if window is currently hidden (only PLATFORM_DESKTOP)
#   @param void [void]
#   @return [Boolean]

# @!method minimized?
#   Check if window is currently minimized (only PLATFORM_DESKTOP)
#   @param void [void]
#   @return [Boolean]

# @!method maximized?
#   Check if window is currently maximized (only PLATFORM_DESKTOP)
#   @param void [void]
#   @return [Boolean]

# @!method focused?
#   Check if window is currently focused (only PLATFORM_DESKTOP)
#   @param void [void]
#   @return [Boolean]

# @!method resized?
#   Check if window has been resized last frame
#   @param void [void]
#   @return [Boolean]

# @!method state?
#   Check if one specific window flag is enabled
#   @param flag [Integer]
#   @return [Boolean]

# @!method state=
#   Set window configuration state using flags (only PLATFORM_DESKTOP)
#   @param flags [Integer]
#   @return [void]

# @!method clear_state
#   Clear window configuration state flags
#   @param flags [Integer]
#   @return [void]

# @!method fullscreen
#   Toggle window state: fullscreen/windowed (only PLATFORM_DESKTOP)
#   @param void [void]
#   @return [void]

# @!method borderless_windowed
#   Toggle window state: borderless windowed (only PLATFORM_DESKTOP)
#   @param void [void]
#   @return [void]

# @!method maximize
#   Set window state: maximized, if resizable (only PLATFORM_DESKTOP)
#   @param void [void]
#   @return [void]

# @!method minimize
#   Set window state: minimized, if resizable (only PLATFORM_DESKTOP)
#   @param void [void]
#   @return [void]

# @!method restore
#   Restore window from being minimized/maximized
#   @param void [void]
#   @return [void]

# @!method icon=
#   Set icon for window (single image, RGBA 32bit, only PLATFORM_DESKTOP)
#   @param image [void]
#   @return [void]

# @!method icons
#   Set icon for window (multiple images, RGBA 32bit, only PLATFORM_DESKTOP)
#   @param images [Array]
#   @param count [Integer]
#   @return [void]

# @!method title=
#   Set title for window (only PLATFORM_DESKTOP and PLATFORM_WEB)
#   @param title [String]
#   @return [void]

# @!method position
#   Set window position on screen (only PLATFORM_DESKTOP)
#   @param x [Integer]
#   @param y [Integer]
#   @return [void]

# @!method monitor=
#   Set monitor for the current window
#   @param monitor [Integer]
#   @return [void]

# @!method min_size
#   Set window minimum dimensions (for FLAG_WINDOW_RESIZABLE)
#   @param width [Integer]
#   @param height [Integer]
#   @return [void]

# @!method max_size
#   Set window maximum dimensions (for FLAG_WINDOW_RESIZABLE)
#   @param width [Integer]
#   @param height [Integer]
#   @return [void]

# @!method size
#   Set window dimensions
#   @param width [Integer]
#   @param height [Integer]
#   @return [void]

# @!method resize_screen
#   Set window dimensions
#   @param width [Integer]
#   @param height [Integer]
#   @return [void]

# @!method opacity=
#   Set window opacity [0.0f..1.0f] (only PLATFORM_DESKTOP)
#   @param opacity [Float]
#   @return [void]

# @!method focused
#   Set window focused (only PLATFORM_DESKTOP)
#   @param void [void]
#   @return [void]

# @!method handle
#   @return [void]

# @!method screen_width
#   Get current screen width
#   @param void [void]
#   @return [Integer]

# @!method screen_height
#   Get current screen height
#   @param void [void]
#   @return [Integer]

# @!method render_width
#   Get current render width (it considers HiDPI)
#   @param void [void]
#   @return [Integer]

# @!method render_height
#   Get current render height (it considers HiDPI)
#   @param void [void]
#   @return [Integer]

# @!method monitor_count
#   Get number of connected monitors
#   @param void [void]
#   @return [Integer]

# @!method current_monitor
#   Get current connected monitor
#   @param void [void]
#   @return [Integer]

# @!method monitor_position
#   Get specified monitor position
#   @param monitor [Integer]
#   @return [Vec2]

# @!method monitor_width
#   Get specified monitor width (current video mode used by monitor)
#   @param monitor [Integer]
#   @return [Integer]

# @!method monitor_height
#   Get specified monitor height (current video mode used by monitor)
#   @param monitor [Integer]
#   @return [Integer]

# @!method monitor_physical_width
#   Get specified monitor physical width in millimetres
#   @param monitor [Integer]
#   @return [Integer]

# @!method monitor_physical_height
#   Get specified monitor physical height in millimetres
#   @param monitor [Integer]
#   @return [Integer]

# @!method refresh_rate
#   Get specified monitor refresh rate
#   @param monitor [Integer]
#   @return [Integer]

# @!method position
#   Get window position XY on monitor
#   @param void [void]
#   @return [Vec2]

# @!method scale_dpi
#   Get window scale DPI factor
#   @param void [void]
#   @return [Vec2]

# @!method monitor_name
#   @return [void]

# @!method enable_event_waiting
#   Enable waiting for events on EndDrawing(), no automatic event polling
#   @param void [void]
#   @return [void]

# @!method freeze
#   Enable waiting for events on EndDrawing(), no automatic event polling
#   @param void [void]
#   @return [void]

# @!method disable_event_waiting
#   Disable waiting for events on EndDrawing(), automatic events polling
#   @param void [void]
#   @return [void]

# @!method unfreeze
#   Disable waiting for events on EndDrawing(), automatic events polling
#   @param void [void]
#   @return [void]

# @!method exit_key=
#   Set a custom key to exit program (default is ESC)
#   @param key [Integer]
#   @return [void]

# @!method show_cursor
#   Shows cursor
#   @param void [void]
#   @return [void]

# @!method hide_cursor
#   Hides cursor
#   @param void [void]
#   @return [void]

# @!method cursor_hidden?
#   Check if cursor is not visible
#   @param void [void]
#   @return [Boolean]

# @!method enable_cursor
#   Enables cursor (unlock cursor)
#   @param void [void]
#   @return [void]

# @!method disable_cursor
#   Disables cursor (lock cursor)
#   @param void [void]
#   @return [void]

# @!method cursor_on_screen?
#   Check if cursor is on the screen
#   @param void [void]
#   @return [Boolean]

# @!method target_fps=
#   Set target FPS (maximum)
#   @param fps [Integer]
#   @return [void]

# @!method fps=
#   Set target FPS (maximum)
#   @param fps [Integer]
#   @return [void]

# @!method frame_rate=
#   Set target FPS (maximum)
#   @param fps [Integer]
#   @return [void]

# @!method frame_time
#   Get time in seconds for last frame drawn (delta time)
#   @param void [void]
#   @return [Float]

# @!method delta_time
#   Get time in seconds for last frame drawn (delta time)
#   @param void [void]
#   @return [Float]

# @!method delta
#   Get time in seconds for last frame drawn (delta time)
#   @param void [void]
#   @return [Float]

# @!method time
#   Get elapsed time in seconds since InitWindow()
#   @param void [void]
#   @return [Float]

# @!method frame_count
#   Get elapsed time in seconds since InitWindow()
#   @param void [void]
#   @return [Float]

# @!method fps
#   Get current FPS
#   @param void [void]
#   @return [Integer]

# @!method frame_rate
#   Get current FPS
#   @param void [void]
#   @return [Integer]

# @!method draw_fps
#   Draw current FPS
#   @param posX [Integer]
#   @param posY [Integer]
#   @return [void]

# @!method swap_screen_buffer
#   Swap back buffer with front buffer (screen drawing)
#   @param void [void]
#   @return [void]

# @!method poll_input_events
#   Register all input events
#   @param void [void]
#   @return [void]

# @!method wait_time
#   Wait for some time (halt program execution)
#   @param seconds [Float]
#   @return [void]

# @!method wait
#   Wait for some time (halt program execution)
#   @param seconds [Float]
#   @return [void]

# @!method take_screenshot
#   Takes a screenshot of current screen
#   @param fileName [String]
#   @return [void]

# @!method config_flags=
#   Setup init configuration flags (view FLAGS)
#   @param flags [Integer]
#   @return [void]

# @!method open_url
#   Open URL with default system browser (if available)
#   @param url [String]
#   @return [void]

# @!method begin
#   Setup canvas (framebuffer) to start drawing
#   @param void [void]
#   @return [void]

# @!method clear
#   Set background color (framebuffer clear color)
#   @param color [Color]
#   @return [void]

# @!parse VSYNC = 0
#   @return [Integer]

# @!parse FULLSCREEN = 0
#   @return [Integer]

# @!parse RESIZABLE = 0
#   @return [Integer]

# @!parse UNDECORATED = 0
#   @return [Integer]

# @!parse HIDDEN = 0
#   @return [Integer]

# @!parse MINIMIZED = 0
#   @return [Integer]

# @!parse MAXIMIZED = 0
#   @return [Integer]

# @!parse UNFOCUSED = 0
#   @return [Integer]

# @!parse TOPMOST = 0
#   @return [Integer]

# @!parse ALWAYS_RUN = 0
#   @return [Integer]

# @!parse TRANSPARENT = 0
#   @return [Integer]

# @!parse HIGHDPI = 0
#   @return [Integer]

# @!parse MOUSE_PASSTHROUGH = 0
#   @return [Integer]

# @!parse BORDERLESS_WINDOWED = 0
#   @return [Integer]

# @!parse MSAA_4X = 0
#   @return [Integer]

# @!parse INTERLACED = 0
#   @return [Integer]
