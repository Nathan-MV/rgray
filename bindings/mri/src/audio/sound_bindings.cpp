#include "audio/sound_bindings.h"

VALUE rb_cSound;

static auto rb_initialize_sound(int argc, VALUE* argv, VALUE self) {
  auto& sound = rb::get<Sound>(self);

  if (RTEST(rb_obj_is_kind_of(argv[0], rb_cWave))) {
    auto* wave = rb::get_safe<Wave>(argv[0], rb_cWave);
    sound = LoadSoundFromWave(*wave);
  } else {
    auto rb_file_name = StringValueCStr(argv[0]);
    sound = LoadSound(rb_file_name);
  }

  return self;
}

// Wave/Sound loading/unloading functions
// RLAPI Sound LoadSound(const char *fileName);                          // Load sound from file
static auto rb_load_sound(VALUE self, VALUE rb_file_name) {
  auto& sound = rb::get<Sound>(self);
  auto file_name = StringValueCStr(rb_file_name);

  sound = LoadSound(file_name);

  return self;
}
// RLAPI Sound LoadSoundFromWave(Wave wave);                             // Load sound from wave data
static auto rb_load_sound_from_wave(VALUE self, VALUE rb_wave) {
  auto& sound = rb::get<Sound>(self);
  auto* wave = rb::get_safe<Wave>(rb_wave, rb_cWave);

  sound = LoadSoundFromWave(*wave);

  return self;
}
// RLAPI Sound LoadSoundAlias(Sound source);                             // Create a new sound that shares the same sample data as the source sound, does not own the sound data
static auto rb_load_sound_alias(VALUE self, VALUE rb_source) {
  auto& sound = rb::get<Sound>(self);
  auto* source = rb::get_safe<Sound>(rb_source, rb_cSound);

  sound = LoadSoundAlias(*source);

  return self;
}
// RLAPI bool IsSoundValid(Sound sound);                                 // Checks if a sound is ready
static auto rb_is_sound_valid(VALUE self) {
  auto& sound = rb::get<Sound>(self);

  return IsSoundValid(sound) ? Qtrue : Qfalse;
}
// RLAPI void UpdateSound(Sound sound, const void *data, int sampleCount); // Update sound buffer with new data
static auto rb_update_sound(VALUE self, VALUE rb_data, VALUE rb_sample_count) {
  auto& sound = rb::get<Sound>(self);
  const auto* data = RSTRING_PTR(rb_data);
  auto sample_count = NUM2INT(rb_sample_count);

  UpdateSound(sound, data, sample_count);

  return self;
}
// RLAPI void UnloadSound(Sound sound);                                  // Unload sound
static auto rb_unload_sound(VALUE self) {
  auto& sound = rb::get<Sound>(self);

  UnloadSound(sound);
  rb::raw_dispose<Sound>(self);

  return self;
}
// RLAPI void UnloadSoundAlias(Sound alias);                             // Unload a sound alias (does not deallocate sample data)
static auto rb_unload_sound_alias(VALUE self) {
  auto& sound = rb::get<Sound>(self);

  UnloadSoundAlias(sound);
  rb::raw_dispose<Sound>(self);

  return self;
}

// Wave/Sound management functions
// RLAPI void PlaySound(Sound sound);                                    // Play a sound
static auto rb_play_sound(VALUE self) {
  auto& sound = rb::get<Sound>(self);

  PlaySound(sound);

  return Qnil;
}
// RLAPI void StopSound(Sound sound);                                    // Stop playing a sound
static auto rb_stop_sound(VALUE self) {
  auto& sound = rb::get<Sound>(self);

  StopSound(sound);

  return Qnil;
}
// RLAPI void PauseSound(Sound sound);                                   // Pause a sound
static auto rb_pause_sound(VALUE self) {
  auto& sound = rb::get<Sound>(self);

  PauseSound(sound);

  return Qnil;
}
// RLAPI void ResumeSound(Sound sound);                                  // Resume a paused sound
static auto rb_resume_sound(VALUE self) {
  auto& sound = rb::get<Sound>(self);

  ResumeSound(sound);

  return Qnil;
}
// RLAPI bool IsSoundPlaying(Sound sound);                               // Check if a sound is currently playing
static auto rb_is_sound_playing(VALUE self) {
  auto& sound = rb::get<Sound>(self);

  return IsSoundPlaying(sound) ? Qtrue : Qfalse;
}
// RLAPI void SetSoundVolume(Sound sound, float volume);                 // Set volume for a sound (1.0 is max level)
static auto rb_set_sound_volume(VALUE self, VALUE rb_volume) {
  auto& sound = rb::get<Sound>(self);
  auto volume = NUM2FLT(rb_volume);

  SetSoundVolume(sound, volume);

  return Qnil;
}
// RLAPI void SetSoundPitch(Sound sound, float pitch);                   // Set pitch for a sound (1.0 is base level)
static auto rb_set_sound_pitch(VALUE self, VALUE rb_pitch) {
  auto& sound = rb::get<Sound>(self);
  auto pitch = NUM2FLT(rb_pitch);

  SetSoundPitch(sound, pitch);

  return Qnil;
}
// RLAPI void SetSoundPan(Sound sound, float pan);                       // Set pan for a sound (0.5 is center)
static auto rb_set_sound_pan(VALUE self, VALUE rb_pan) {
  auto& sound = rb::get<Sound>(self);
  auto pan = NUM2FLT(rb_pan);

  SetSoundPan(sound, pan);

  return Qnil;
}

extern "C" void Init_Sound() {
  rb_cSound = rb_define_class("Sound", rb_cObject);
  rb_define_alloc_func(rb_cSound, rb::alloc<Sound>);

  rb_define_method(rb_cSound, "initialize", rb_initialize_sound, -1);
  rb_define_method(rb_cSound, "load=", rb_load_sound, 1);
  rb_define_method(rb_cSound, "load_from_wave=", rb_load_sound_from_wave, 1);
  rb_define_method(rb_cSound, "load_alias", rb_load_sound_alias, 1);
  rb_define_method(rb_cSound, "valid?", rb_is_sound_valid, 0);
  rb_define_method(rb_cSound, "update", rb_update_sound, 2);
  rb_define_method(rb_cSound, "unload", rb_unload_sound, 0);
  rb_define_method(rb_cSound, "unload_alias", rb_unload_sound_alias, 0);
  rb_define_method(rb_cSound, "play", rb_play_sound, 0);
  rb_define_method(rb_cSound, "stop", rb_stop_sound, 0);
  rb_define_method(rb_cSound, "pause", rb_pause_sound, 0);
  rb_define_method(rb_cSound, "resume", rb_resume_sound, 0);
  rb_define_method(rb_cSound, "playing?", rb_is_sound_playing, 0);
  rb_define_method(rb_cSound, "volume=", rb_set_sound_volume, 1);
  rb_define_method(rb_cSound, "pitch=", rb_set_sound_pitch, 1);
  rb_define_method(rb_cSound, "pan=", rb_set_sound_pan, 1);
}