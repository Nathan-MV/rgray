#include "audio/wave_bindings.h"

VALUE rb_cWave;

// Wave/Sound loading/unloading functions
// RLAPI Wave LoadWave(const char *fileName);                            // Load wave data from file]
static auto rb_load_wave(VALUE self, VALUE rb_file_name) {
  auto& wave = rb::get<Wave>(self);
  auto file_name = StringValueCStr(rb_file_name);

  wave = LoadWave(file_name);

  return self;
}
// RLAPI Wave LoadWaveFromMemory(const char *fileType, const unsigned char *fileData, int dataSize); // Load wave from memory buffer, fileType refers to extension: i.e. '.wav'
static auto rb_load_wave_from_memory(VALUE self, VALUE rb_file_type, VALUE rb_data) {
  auto& wave = rb::get<Wave>(self);
  auto file_type = StringValueCStr(rb_file_type);
  const auto* data = reinterpret_cast<const unsigned char*>(RSTRING_PTR(rb_data));
  auto data_size = RSTRING_LEN(rb_data);

  wave = LoadWaveFromMemory(file_type, data, data_size);

  return self;
}
// RLAPI bool IsWaveValid(Wave wave);                                    // Checks if wave data is ready
static auto rb_is_wave_valid(VALUE self) {
  auto& wave = rb::get<Wave>(self);

  return IsWaveValid(wave) ? Qtrue : Qfalse;
}
// RLAPI void UnloadWave(Wave wave);                                     // Unload wave data
static auto rb_unload_wave(VALUE self) {
  auto& wave = rb::get<Wave>(self);

  UnloadWave(wave);
  rb::raw_dispose<Wave>(self);

  return self;
}
// RLAPI bool ExportWave(Wave wave, const char *fileName);               // Export wave data to file, returns true on success
static auto rb_export_wave(VALUE self, VALUE rb_file_name) {
  auto& wave = rb::get<Wave>(self);
  auto file_name = StringValueCStr(rb_file_name);

  auto result = ExportWave(wave, file_name);

  return result ? Qtrue : Qfalse;
}
// RLAPI bool ExportWaveAsCode(Wave wave, const char *fileName);         // Export wave sample data to code (.h), returns true on success
static auto rb_export_wave_as_code(VALUE self, VALUE rb_file_name) {
  auto& wave = rb::get<Wave>(self);
  auto file_name = StringValueCStr(rb_file_name);

  auto result = ExportWaveAsCode(wave, file_name);

  return result ? Qtrue : Qfalse;
}

// Wave/Sound management functions
// RLAPI Wave WaveCopy(Wave wave);                                       // Copy a wave to a new wave
static auto rb_wave_copy(VALUE self) {
  auto& wave = rb::get<Wave>(self);

  Wave new_wave = WaveCopy(wave);

  VALUE rb_new_wave = rb::alloc<Wave>(rb_cWave);
  rb::get<Wave>(rb_new_wave) = new_wave;

  return rb_new_wave;
}
// RLAPI void WaveCrop(Wave *wave, int initFrame, int finalFrame);       // Crop a wave to defined frames range
static auto rb_wave_crop(VALUE self, VALUE rb_init_frame, VALUE rb_final_frame) {
  auto& wave = rb::get<Wave>(self);
  auto init_frame = NUM2INT(rb_init_frame);
  auto final_frame = NUM2INT(rb_final_frame);

  WaveCrop(&wave, init_frame, final_frame);

  return Qnil;
}
// RLAPI void WaveFormat(Wave *wave, int sampleRate, int sampleSize, int channels); // Convert wave data to desired format
static auto rb_wave_format(VALUE self, VALUE rb_sample_rate, VALUE rb_sample_size, VALUE rb_channels) {
  auto& wave = rb::get<Wave>(self);
  auto sample_rate = NUM2INT(rb_sample_rate);
  auto sample_size = NUM2INT(rb_sample_size);
  auto channels = NUM2INT(rb_channels);

  WaveFormat(&wave, sample_rate, sample_size, channels);

  return Qnil;
}
// RLAPI float *LoadWaveSamples(Wave wave);                              // Load samples data from wave as a 32bit float data array
static auto rb_load_wave_samples(VALUE self) {
  auto& wave = rb::get<Wave>(self);

  float* samples = LoadWaveSamples(wave);

  VALUE rb_samples = rb_str_new(reinterpret_cast<const char*>(samples), wave.frameCount * wave.channels * sizeof(float));

  return rb_samples;
}
// RLAPI void UnloadWaveSamples(float *samples);                         // Unload samples data loaded with LoadWaveSamples()
static auto rb_unload_wave_samples(VALUE self, VALUE rb_samples) {
  auto* samples = reinterpret_cast<float*>(RSTRING_PTR(rb_samples));

  UnloadWaveSamples(samples);

  return Qnil;
}

extern "C" void Init_Wave() {
  rb_cWave = rb_define_class("Wave", rb_cObject);
  rb_define_alloc_func(rb_cWave, rb::alloc<Wave>);

  rb_define_method(rb_cWave, "initialize", rb_load_wave, 1);
  rb_define_method(rb_cWave, "load_from_memory", rb_load_wave_from_memory, 2);
  rb_define_method(rb_cWave, "ready?", rb_is_wave_valid, 0);
  rb_define_method(rb_cWave, "unload", rb_unload_wave, 0);
  rb_define_method(rb_cWave, "export", rb_export_wave, 1);
  rb_define_method(rb_cWave, "export_as_code", rb_export_wave_as_code, 1);
  rb_define_method(rb_cWave, "copy", rb_wave_copy, 0);
  rb_define_method(rb_cWave, "crop", rb_wave_crop, 2);
  rb_define_method(rb_cWave, "format", rb_wave_format, 3);
  rb_define_method(rb_cWave, "load_samples", rb_load_wave_samples, 0);
  rb_define_method(rb_cWave, "unload_samples", rb_unload_wave_samples, 1);
}