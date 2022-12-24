#define SAMPLE_RATE 16000

void play_tune(const uint8_t *audio, uint32_t audio_length) {
  uint32_t t;
  uint32_t prior, usec = 1000000L / SAMPLE_RATE;

  for (uint32_t i=0; i<audio_length; i++) {
    while((t = micros()) - prior < usec);
    dacWrite(A0, audio[i]);
    prior = t;
  }
}
