# @!method initialize
#   Load music stream from file
#   @param fileName [String]
#   @return [void]

# @!method load=
#   Load music stream from file
#   @param fileName [String]
#   @return [void]

# @!method load_from_memory
#   Load music stream from data
#   @param fileType [String]
#   @param data [String]
#   @param dataSize [Integer]
#   @return [void]

# @!method ready?
#   Checks if a music stream is ready
#   @param music [void]
#   @return [Boolean]

# @!method unload
#   Unload music stream
#   @param music [void]
#   @return [void]

# @!method play
#   Start music playing
#   @param music [void]
#   @return [void]

# @!method playing?
#   Check if music is playing
#   @param music [void]
#   @return [Boolean]

# @!method update
#   Updates buffers for music streaming
#   @param music [void]
#   @return [void]

# @!method stop
#   Stop music playing
#   @param music [void]
#   @return [void]

# @!method pause
#   Pause music playing
#   @param music [void]
#   @return [void]

# @!method resume
#   Resume playing paused music
#   @param music [void]
#   @return [void]

# @!method seek
#   Seek music to a position (in seconds)
#   @param music [void]
#   @param position [Float]
#   @return [void]

# @!method volume=
#   Set volume for music (1.0 is max level)
#   @param music [void]
#   @param volume [Float]
#   @return [void]

# @!method pitch=
#   Set pitch for a music (1.0 is base level)
#   @param music [void]
#   @param pitch [Float]
#   @return [void]

# @!method pan=
#   Set pan for a music (0.5 is center)
#   @param music [void]
#   @param pan [Float]
#   @return [void]

# @!method time_length
#   Get music time length (in seconds)
#   @param music [void]
#   @return [Float]

# @!method time_played
#   Get current music time played (in seconds)
#   @param music [void]
#   @return [Float]
