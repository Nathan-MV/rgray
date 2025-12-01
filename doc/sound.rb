# @!method initialize
#   @return [void]

# @!method load=
#   Load sound from file
#   @param fileName [String]
#   @return [void]

# @!method load_from_wave=
#   Load sound from wave data
#   @param wave [void]
#   @return [void]

# @!method load_alias
#   Create a new sound that shares the same sample data as the source sound, does not own the sound data
#   @param source [void]
#   @return [void]

# @!method valid?
#   Checks if a sound is ready
#   @param sound [void]
#   @return [Boolean]

# @!method update
#   Update sound buffer with new data
#   @param sound [void]
#   @param data [Array]
#   @param sampleCount [Integer]
#   @return [void]

# @!method unload
#   Unload sound
#   @param sound [void]
#   @return [void]

# @!method unload_alias
#   Unload a sound alias (does not deallocate sample data)
#   @param alias [void]
#   @return [void]

# @!method play
#   Play a sound
#   @param sound [void]
#   @return [void]

# @!method stop
#   Stop playing a sound
#   @param sound [void]
#   @return [void]

# @!method pause
#   Pause a sound
#   @param sound [void]
#   @return [void]

# @!method resume
#   Resume a paused sound
#   @param sound [void]
#   @return [void]

# @!method playing?
#   Check if a sound is currently playing
#   @param sound [void]
#   @return [Boolean]

# @!method volume=
#   Set volume for a sound (1.0 is max level)
#   @param sound [void]
#   @param volume [Float]
#   @return [void]

# @!method pitch=
#   Set pitch for a sound (1.0 is base level)
#   @param sound [void]
#   @param pitch [Float]
#   @return [void]

# @!method pan=
#   Set pan for a sound (0.5 is center)
#   @param sound [void]
#   @param pan [Float]
#   @return [void]
