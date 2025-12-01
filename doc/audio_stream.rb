# @!method initialize
#   Load audio stream (to stream raw audio pcm data)
#   @param sampleRate [Integer]
#   @param sampleSize [Integer]
#   @param channels [Integer]
#   @return [void]

# @!method load
#   Load audio stream (to stream raw audio pcm data)
#   @param sampleRate [Integer]
#   @param sampleSize [Integer]
#   @param channels [Integer]
#   @return [void]

# @!method ready?
#   Checks if an audio stream is ready
#   @param stream [void]
#   @return [Boolean]

# @!method unload
#   Unload audio stream and free memory
#   @param stream [void]
#   @return [void]

# @!method update
#   Update audio stream buffers with data
#   @param stream [void]
#   @param data [Array]
#   @param frameCount [Integer]
#   @return [void]

# @!method processed?
#   Check if any audio stream buffers requires refill
#   @param stream [void]
#   @return [Boolean]

# @!method play
#   Play audio stream
#   @param stream [void]
#   @return [void]

# @!method pause
#   Pause audio stream
#   @param stream [void]
#   @return [void]

# @!method resume
#   Resume audio stream
#   @param stream [void]
#   @return [void]

# @!method playing?
#   Check if audio stream is playing
#   @param stream [void]
#   @return [Boolean]

# @!method stop
#   Stop audio stream
#   @param stream [void]
#   @return [void]

# @!method volume=
#   Set volume for audio stream (1.0 is max level)
#   @param stream [void]
#   @param volume [Float]
#   @return [void]

# @!method pitch=
#   Set pitch for audio stream (1.0 is base level)
#   @param stream [void]
#   @param pitch [Float]
#   @return [void]

# @!method pan=
#   Set pan for audio stream (0.5 is centered)
#   @param stream [void]
#   @param pan [Float]
#   @return [void]

# @!method set_buffer_size_default
#   Default size for new audio streams
#   @param size [Integer]
#   @return [void]

# @!method set_callback
#   Audio thread callback to request new data
#   @param stream [void]
#   @param callback [void]
#   @return [void]

# @!method attach_processor
#   Attach audio stream processor to stream, receives the samples as 'float'
#   @param stream [void]
#   @param processor [void]
#   @return [void]

# @!method detach_processor
#   Detach audio stream processor from stream
#   @param stream [void]
#   @param processor [void]
#   @return [void]

# @!method attach_mixed_processor
#   Attach audio stream processor to the entire audio pipeline, receives the samples as 'float'
#   @param processor [void]
#   @return [void]

# @!method detach_mixed_processor
#   Detach audio stream processor from the entire audio pipeline
#   @param processor [void]
#   @return [void]
