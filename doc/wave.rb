# @!method initialize
#   Load wave data from file]
#   @param fileName [String]
#   @return [void]

# @!method load_from_memory
#   Load wave from memory buffer, fileType refers to extension: i.e. '.wav'
#   @param fileType [String]
#   @param fileData [String]
#   @param dataSize [Integer]
#   @return [void]

# @!method ready?
#   Checks if wave data is ready
#   @param wave [void]
#   @return [Boolean]

# @!method unload
#   Unload wave data
#   @param wave [void]
#   @return [void]

# @!method export
#   Export wave data to file, returns true on success
#   @param wave [void]
#   @param fileName [String]
#   @return [Boolean]

# @!method export_as_code
#   Export wave sample data to code (.h), returns true on success
#   @param wave [void]
#   @param fileName [String]
#   @return [Boolean]

# @!method copy
#   Copy a wave to a new wave
#   @param wave [void]
#   @return [void]

# @!method crop
#   Crop a wave to defined frames range
#   @param wave [Array]
#   @param initFrame [Integer]
#   @param finalFrame [Integer]
#   @return [void]

# @!method format
#   Convert wave data to desired format
#   @param wave [Array]
#   @param sampleRate [Integer]
#   @param sampleSize [Integer]
#   @param channels [Integer]
#   @return [void]

# @!method load_samples
#   @return [void]

# @!method unload_samples
#   Unload samples data loaded with LoadWaveSamples()
#   @param samples [Float]
#   @return [void]
