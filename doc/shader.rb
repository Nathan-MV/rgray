# @!method initialize
#   Load shader from files and bind default locations
#   @param vsFileName [String]
#   @param fsFileName [String]
#   @return [void]

# @!method load
#   Load shader from files and bind default locations
#   @param vsFileName [String]
#   @param fsFileName [String]
#   @return [void]

# @!method ready?
#   Check if a shader is ready
#   @param shader [void]
#   @return [Boolean]

# @!method location
#   Get shader uniform location
#   @param shader [void]
#   @param uniformName [String]
#   @return [Integer]

# @!method location_attrib
#   Get shader attribute location
#   @param shader [void]
#   @param attribName [String]
#   @return [Integer]

# @!method set_value
#   Set shader uniform value
#   @param shader [void]
#   @param locIndex [Integer]
#   @param value [Array]
#   @param uniformType [Integer]
#   @return [void]

# @!method set_uniform
#   Set shader uniform value
#   @param shader [void]
#   @param locIndex [Integer]
#   @param value [Array]
#   @param uniformType [Integer]
#   @return [void]

# @!method set_value_v
#   Set shader uniform value vector
#   @param shader [void]
#   @param locIndex [Integer]
#   @param value [Array]
#   @param uniformType [Integer]
#   @param count [Integer]
#   @return [void]

# @!method set_uniform_v
#   Set shader uniform value vector
#   @param shader [void]
#   @param locIndex [Integer]
#   @param value [Array]
#   @param uniformType [Integer]
#   @param count [Integer]
#   @return [void]

# @!method set_texture
#   Set shader uniform value (matrix 4x4)
#   @param shader [void]
#   @param locIndex [Integer]
#   @param mat [void]
#   @return [void]

# @!method unload
#   Unload shader from GPU memory (VRAM)
#   @param shader [void]
#   @return [void]

# @!method dispose
#   Unload shader from GPU memory (VRAM)
#   @param shader [void]
#   @return [void]

# @!method begin
#   Begin custom shader drawing
#   @param shader [void]
#   @return [void]

# @!method set
#   Set shader uniform value
#   @param shader [void]
#   @param locIndex [Integer]
#   @param value [Array]
#   @param uniformType [Integer]
#   @return [void]

# @!parse LOC_VERTEX_POSITION = 0
#   @return [Integer]

# @!parse LOC_VERTEX_TEXCOORD01 = 1
#   @return [Integer]

# @!parse LOC_VERTEX_TEXCOORD02 = 2
#   @return [Integer]

# @!parse LOC_VERTEX_NORMAL = 3
#   @return [Integer]

# @!parse LOC_VERTEX_TANGENT = 4
#   @return [Integer]

# @!parse LOC_VERTEX_COLOR = 5
#   @return [Integer]

# @!parse LOC_MATRIX_MVP = 6
#   @return [Integer]

# @!parse LOC_MATRIX_VIEW = 7
#   @return [Integer]

# @!parse LOC_MATRIX_PROJECTION = 8
#   @return [Integer]

# @!parse LOC_MATRIX_MODEL = 9
#   @return [Integer]

# @!parse LOC_MATRIX_NORMAL = 10
#   @return [Integer]

# @!parse LOC_VECTOR_VIEW = 11
#   @return [Integer]

# @!parse LOC_COLOR_DIFFUSE = 12
#   @return [Integer]

# @!parse LOC_COLOR_SPECULAR = 13
#   @return [Integer]

# @!parse LOC_COLOR_AMBIENT = 14
#   @return [Integer]

# @!parse LOC_MAP_ALBEDO = 15
#   @return [Integer]

# @!parse LOC_MAP_DIFFUSE = 15
#   @return [Integer]

# @!parse LOC_MAP_METALNESS = 16
#   @return [Integer]

# @!parse LOC_MAP_SPECULAR = 16
#   @return [Integer]

# @!parse LOC_MAP_NORMAL = 17
#   @return [Integer]

# @!parse LOC_MAP_ROUGHNESS = 18
#   @return [Integer]

# @!parse LOC_MAP_OCCLUSION = 19
#   @return [Integer]

# @!parse LOC_MAP_EMISSION = 20
#   @return [Integer]

# @!parse LOC_MAP_HEIGHT = 21
#   @return [Integer]

# @!parse LOC_MAP_CUBEMAP = 22
#   @return [Integer]

# @!parse LOC_MAP_IRRADIANCE = 23
#   @return [Integer]

# @!parse LOC_MAP_PREFILTER = 24
#   @return [Integer]

# @!parse LOC_MAP_BRDF = 25
#   @return [Integer]

# @!parse LOC_VERTEX_BONEIDS = 26
#   @return [Integer]

# @!parse LOC_VERTEX_BONEWEIGHTS = 27
#   @return [Integer]

# @!parse LOC_BONE_MATRICES = 28
#   @return [Integer]

# @!parse LOC_VERTEX_INSTANCE_TX = 29
#   @return [Integer]

# @!parse UNIFORM_FLOAT = 0
#   @return [Integer]

# @!parse UNIFORM_VEC2 = 1
#   @return [Integer]

# @!parse UNIFORM_VEC3 = 2
#   @return [Integer]

# @!parse UNIFORM_VEC4 = 3
#   @return [Integer]

# @!parse UNIFORM_INT = 4
#   @return [Integer]

# @!parse UNIFORM_IVEC2 = 5
#   @return [Integer]

# @!parse UNIFORM_IVEC3 = 6
#   @return [Integer]

# @!parse UNIFORM_IVEC4 = 7
#   @return [Integer]

# @!parse UNIFORM_UINT = 8
#   @return [Integer]

# @!parse UNIFORM_UIVEC2 = 9
#   @return [Integer]

# @!parse UNIFORM_UIVEC3 = 10
#   @return [Integer]

# @!parse UNIFORM_UIVEC4 = 11
#   @return [Integer]

# @!parse UNIFORM_SAMPLER2D = 12
#   @return [Integer]

# @!parse ATTRIB_FLOAT = 0
#   @return [Integer]

# @!parse ATTRIB_VEC2 = 1
#   @return [Integer]

# @!parse ATTRIB_VEC3 = 2
#   @return [Integer]

# @!parse ATTRIB_VEC4 = 3
#   @return [Integer]
