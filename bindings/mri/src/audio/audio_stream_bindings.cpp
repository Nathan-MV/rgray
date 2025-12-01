#include "audio/audio_stream_bindings.h"

VALUE rb_cAudioStream;

// AudioStream management functions
// RLAPI AudioStream LoadAudioStream(unsigned int sampleRate, unsigned int sampleSize, unsigned int channels); // Load audio stream (to stream raw audio pcm data)
static auto rb_load_audio_stream(VALUE self, VALUE rb_sample_rate, VALUE rb_sample_size, VALUE rb_channels) {
  auto& audio_stream = rb::get<AudioStream>(self);
  auto sample_rate = NUM2INT(rb_sample_rate);
  auto sample_size = NUM2INT(rb_sample_size);
  auto channels = NUM2INT(rb_channels);

  audio_stream = LoadAudioStream(sample_rate, sample_size, channels);

  return self;
}
// RLAPI bool IsAudioStreamValid(AudioStream stream);                    // Checks if an audio stream is ready
static auto rb_is_audio_stream_ready(VALUE self) {
  auto& audio_stream = rb::get<AudioStream>(self);

  return IsAudioStreamValid(audio_stream) ? Qtrue : Qfalse;
}
// RLAPI void UnloadAudioStream(AudioStream stream);                     // Unload audio stream and free memory
static auto rb_unload_audio_stream(VALUE self) {
  auto& audio_stream = rb::get<AudioStream>(self);

  UnloadAudioStream(audio_stream);
  rb::raw_dispose<AudioStream>(self);

  return self;
}
// RLAPI void UpdateAudioStream(AudioStream stream, const void *data, int frameCount); // Update audio stream buffers with data
static auto rb_update_audio_stream(VALUE self, VALUE rb_data, VALUE rb_frame_count) {
  auto& audio_stream = rb::get<AudioStream>(self);
  const auto* data = RSTRING_PTR(rb_data);
  auto frame_count = NUM2INT(rb_frame_count);

  UpdateAudioStream(audio_stream, data, frame_count);

  return self;
}
// RLAPI bool IsAudioStreamProcessed(AudioStream stream);                // Check if any audio stream buffers requires refill
static auto rb_is_audio_stream_processed(VALUE self) {
  auto& audio_stream = rb::get<AudioStream>(self);

  return IsAudioStreamProcessed(audio_stream) ? Qtrue : Qfalse;
}
// RLAPI void PlayAudioStream(AudioStream stream);                       // Play audio stream
static auto rb_play_audio_stream(VALUE self) {
  auto& audio_stream = rb::get<AudioStream>(self);

  PlayAudioStream(audio_stream);

  return Qnil;
}
// RLAPI void PauseAudioStream(AudioStream stream);                      // Pause audio stream
static auto rb_pause_audio_stream(VALUE self) {
  auto& audio_stream = rb::get<AudioStream>(self);

  PauseAudioStream(audio_stream);

  return Qnil;
}
// RLAPI void ResumeAudioStream(AudioStream stream);                     // Resume audio stream
static auto rb_resume_audio_stream(VALUE self) {
  auto& audio_stream = rb::get<AudioStream>(self);

  ResumeAudioStream(audio_stream);

  return Qnil;
}
// RLAPI bool IsAudioStreamPlaying(AudioStream stream);                  // Check if audio stream is playing
static auto rb_is_audio_stream_playing(VALUE self) {
  auto& audio_stream = rb::get<AudioStream>(self);

  return IsAudioStreamPlaying(audio_stream) ? Qtrue : Qfalse;
}
// RLAPI void StopAudioStream(AudioStream stream);                       // Stop audio stream
static auto rb_stop_audio_stream(VALUE self) {
  auto& audio_stream = rb::get<AudioStream>(self);

  StopAudioStream(audio_stream);

  return Qnil;
}
// RLAPI void SetAudioStreamVolume(AudioStream stream, float volume);    // Set volume for audio stream (1.0 is max level)
static auto rb_set_audio_stream_volume(VALUE self, VALUE rb_volume) {
  auto& audio_stream = rb::get<AudioStream>(self);
  auto volume = NUM2FLT(rb_volume);

  SetAudioStreamVolume(audio_stream, volume);

  return Qnil;
}
// RLAPI void SetAudioStreamPitch(AudioStream stream, float pitch);      // Set pitch for audio stream (1.0 is base level)
static auto rb_set_audio_stream_pitch(VALUE self, VALUE rb_pitch) {
  auto& audio_stream = rb::get<AudioStream>(self);
  auto pitch = NUM2FLT(rb_pitch);

  SetAudioStreamPitch(audio_stream, pitch);

  return Qnil;
}
// RLAPI void SetAudioStreamPan(AudioStream stream, float pan);          // Set pan for audio stream (0.5 is centered)
static auto rb_set_audio_stream_pan(VALUE self, VALUE rb_pan) {
  auto& audio_stream = rb::get<AudioStream>(self);
  auto pan = NUM2FLT(rb_pan);

  SetAudioStreamPan(audio_stream, pan);

  return Qnil;
}
// RLAPI void SetAudioStreamBufferSizeDefault(int size);                 // Default size for new audio streams
static auto rb_set_audio_stream_buffer_size_default(VALUE self, VALUE rb_size) {
  auto size = NUM2INT(rb_size);

  SetAudioStreamBufferSizeDefault(size);

  return Qnil;
}
// RLAPI void SetAudioStreamCallback(AudioStream stream, AudioCallback callback); // Audio thread callback to request new data
static auto rb_set_audio_stream_callback(VALUE self, VALUE rb_callback) {
  // Note: Callbacks are not directly supported in this binding.
  rb_raise(rb_eNotImpError, "Audio stream callbacks are not supported in this binding.");

  return Qnil;
}

// RLAPI void AttachAudioStreamProcessor(AudioStream stream, AudioCallback processor); // Attach audio stream processor to stream, receives the samples as 'float'
static auto rb_attach_audio_stream_processor(VALUE self, VALUE rb_processor) {
  // Note: Processors are not directly supported in this binding.
  rb_raise(rb_eNotImpError, "Audio stream processors are not supported in this binding.");

  return Qnil;
}
// RLAPI void DetachAudioStreamProcessor(AudioStream stream, AudioCallback processor); // Detach audio stream processor from stream
static auto rb_detach_audio_stream_processor(VALUE self, VALUE rb_processor) {
  // Note: Processors are not directly supported in this binding.
  rb_raise(rb_eNotImpError, "Audio stream processors are not supported in this binding.");

  return Qnil;
}

// RLAPI void AttachAudioMixedProcessor(AudioCallback processor); // Attach audio stream processor to the entire audio pipeline, receives the samples as 'float'
static auto rb_attach_audio_mixed_processor(VALUE self, VALUE rb_processor) {
  // Note: Processors are not directly supported in this binding.
  rb_raise(rb_eNotImpError, "Audio mixed processors are not supported in this binding.");

  return Qnil;
}
// RLAPI void DetachAudioMixedProcessor(AudioCallback processor); // Detach audio stream processor from the entire audio pipeline
static auto rb_detach_audio_mixed_processor(VALUE self, VALUE rb_processor) {
  // Note: Processors are not directly supported in this binding.
  rb_raise(rb_eNotImpError, "Audio mixed processors are not supported in this binding.");

  return Qnil;
}

extern "C" void Init_AudioStream() {
  rb_cAudioStream = rb_define_class("AudioStream", rb_cObject);
  rb_define_alloc_func(rb_cAudioStream, rb::alloc<AudioStream>);

  rb_define_method(rb_cAudioStream, "initialize", rb_load_audio_stream, 3);
  rb_define_method(rb_cAudioStream, "load", rb_load_audio_stream, 3);
  rb_define_method(rb_cAudioStream, "ready?", rb_is_audio_stream_ready, 0);
  rb_define_method(rb_cAudioStream, "unload", rb_unload_audio_stream, 0);
  rb_define_method(rb_cAudioStream, "update", rb_update_audio_stream, 2);
  rb_define_method(rb_cAudioStream, "processed?", rb_is_audio_stream_processed, 0);
  rb_define_method(rb_cAudioStream, "play", rb_play_audio_stream, 0);
  rb_define_method(rb_cAudioStream, "pause", rb_pause_audio_stream, 0);
  rb_define_method(rb_cAudioStream, "resume", rb_resume_audio_stream, 0);
  rb_define_method(rb_cAudioStream, "playing?", rb_is_audio_stream_playing, 0);
  rb_define_method(rb_cAudioStream, "stop", rb_stop_audio_stream, 0);
  rb_define_method(rb_cAudioStream, "volume=", rb_set_audio_stream_volume, 1);
  rb_define_method(rb_cAudioStream, "pitch=", rb_set_audio_stream_pitch, 1);
  rb_define_method(rb_cAudioStream, "pan=", rb_set_audio_stream_pan, 1);
  rb_define_method(rb_cAudioStream, "set_buffer_size_default", rb_set_audio_stream_buffer_size_default, 1);
  rb_define_method(rb_cAudioStream, "set_callback", rb_set_audio_stream_callback, 1);
  rb_define_method(rb_cAudioStream, "attach_processor", rb_attach_audio_stream_processor, 1);
  rb_define_method(rb_cAudioStream, "detach_processor", rb_detach_audio_stream_processor, 1);
  rb_define_method(rb_cAudioStream, "attach_mixed_processor", rb_attach_audio_mixed_processor, 1);
  rb_define_method(rb_cAudioStream, "detach_mixed_processor", rb_detach_audio_mixed_processor, 1);
}