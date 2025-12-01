#include "audio/music_bindings.h"

VALUE rb_cMusic;

// Music management functions
// RLAPI Music LoadMusicStream(const char *fileName);                    // Load music stream from file
static auto rb_load_music_stream(VALUE self, VALUE rb_file_name) {
  auto& music = rb::get<Music>(self);
  auto file_name = StringValueCStr(rb_file_name);

  music = LoadMusicStream(file_name);

  return self;
}
// RLAPI Music LoadMusicStreamFromMemory(const char *fileType, const unsigned char *data, int dataSize); // Load music stream from data
static auto rb_load_music_stream_from_memory(VALUE self, VALUE rb_file_type, VALUE rb_data) {
  auto& music = rb::get<Music>(self);
  auto file_type = StringValueCStr(rb_file_type);
  const auto* data = reinterpret_cast<const unsigned char*>(RSTRING_PTR(rb_data));
  auto data_size = RSTRING_LEN(rb_data);

  music = LoadMusicStreamFromMemory(file_type, data, data_size);

  return self;
}
// RLAPI bool IsMusicValid(Music music);                                 // Checks if a music stream is ready
static auto rb_is_music_ready(VALUE self) {
  auto& music = rb::get<Music>(self);

  return IsMusicValid(music) ? Qtrue : Qfalse;
}
// RLAPI void UnloadMusicStream(Music music);                            // Unload music stream
static auto rb_unload_music_stream(VALUE self) {
  auto& music = rb::get<Music>(self);

  UnloadMusicStream(music);
  rb::raw_dispose<Music>(self);

  return self;
}
// RLAPI void PlayMusicStream(Music music);                              // Start music playing
static auto rb_play_music_stream(VALUE self) {
  auto& music = rb::get<Music>(self);

  PlayMusicStream(music);

  return Qnil;
}
// RLAPI bool IsMusicStreamPlaying(Music music);                         // Check if music is playing
static auto rb_is_music_stream_playing(VALUE self) {
  auto& music = rb::get<Music>(self);

  return IsMusicStreamPlaying(music) ? Qtrue : Qfalse;
}
// RLAPI void UpdateMusicStream(Music music);                            // Updates buffers for music streaming
static auto rb_update_music_stream(VALUE self) {
  auto& music = rb::get<Music>(self);

  UpdateMusicStream(music);

  return Qnil;
}
// RLAPI void StopMusicStream(Music music);                              // Stop music playing
static auto rb_stop_music_stream(VALUE self) {
  auto& music = rb::get<Music>(self);

  StopMusicStream(music);

  return Qnil;
}
// RLAPI void PauseMusicStream(Music music);                             // Pause music playing
static auto rb_pause_music_stream(VALUE self) {
  auto& music = rb::get<Music>(self);

  PauseMusicStream(music);

  return Qnil;
}
// RLAPI void ResumeMusicStream(Music music);                            // Resume playing paused music
static auto rb_resume_music_stream(VALUE self) {
  auto& music = rb::get<Music>(self);

  ResumeMusicStream(music);

  return Qnil;
}
// RLAPI void SeekMusicStream(Music music, float position);              // Seek music to a position (in seconds)
static auto rb_seek_music_stream(VALUE self, VALUE rb_position) {
  auto& music = rb::get<Music>(self);
  auto position = NUM2FLT(rb_position);

  SeekMusicStream(music, position);

  return Qnil;
}
// RLAPI void SetMusicVolume(Music music, float volume);                 // Set volume for music (1.0 is max level)
static auto rb_set_music_volume(VALUE self, VALUE rb_volume) {
  auto& music = rb::get<Music>(self);
  auto volume = NUM2FLT(rb_volume);

  SetMusicVolume(music, volume);

  return Qnil;
}
// RLAPI void SetMusicPitch(Music music, float pitch);                   // Set pitch for a music (1.0 is base level)
static auto rb_set_music_pitch(VALUE self, VALUE rb_pitch) {
  auto& music = rb::get<Music>(self);
  auto pitch = NUM2FLT(rb_pitch);

  SetMusicPitch(music, pitch);

  return Qnil;
}
// RLAPI void SetMusicPan(Music music, float pan);                       // Set pan for a music (0.5 is center)
static auto rb_set_music_pan(VALUE self, VALUE rb_pan) {
  auto& music = rb::get<Music>(self);
  auto pan = NUM2FLT(rb_pan);

  SetMusicPan(music, pan);

  return Qnil;
}
// RLAPI float GetMusicTimeLength(Music music);                          // Get music time length (in seconds)
static auto rb_get_music_time_length(VALUE self) {
  auto& music = rb::get<Music>(self);

  auto time_length = GetMusicTimeLength(music);

  return DBL2NUM(time_length);
}
// RLAPI float GetMusicTimePlayed(Music music);                          // Get current music time played (in seconds)
static auto rb_get_music_time_played(VALUE self) {
  auto& music = rb::get<Music>(self);

  auto time_played = GetMusicTimePlayed(music);

  return DBL2NUM(time_played);
}

extern "C" void Init_Music() {
  rb_cMusic = rb_define_class("AudioStream", rb_cObject);
  rb_define_alloc_func(rb_cMusic, rb::alloc<Music>);

  rb_define_method(rb_cMusic, "initialize", rb_load_music_stream, 1);
  rb_define_method(rb_cMusic, "load=", rb_load_music_stream, 1);
  rb_define_method(rb_cMusic, "load_from_memory", rb_load_music_stream_from_memory, 2);
  rb_define_method(rb_cMusic, "ready?", rb_is_music_ready, 0);
  rb_define_method(rb_cMusic, "unload", rb_unload_music_stream, 0);
  rb_define_method(rb_cMusic, "play", rb_play_music_stream, 0);
  rb_define_method(rb_cMusic, "playing?", rb_is_music_stream_playing, 0);
  rb_define_method(rb_cMusic, "update", rb_update_music_stream, 0);
  rb_define_method(rb_cMusic, "stop", rb_stop_music_stream, 0);
  rb_define_method(rb_cMusic, "pause", rb_pause_music_stream, 0);
  rb_define_method(rb_cMusic, "resume", rb_resume_music_stream, 0);
  rb_define_method(rb_cMusic, "seek", rb_seek_music_stream, 1);
  rb_define_method(rb_cMusic, "volume=", rb_set_music_volume, 1);
  rb_define_method(rb_cMusic, "pitch=", rb_set_music_pitch, 1);
  rb_define_method(rb_cMusic, "pan=", rb_set_music_pan, 1);
  rb_define_method(rb_cMusic, "time_length", rb_get_music_time_length, 0);
  rb_define_method(rb_cMusic, "time_played", rb_get_music_time_played, 0);
}
