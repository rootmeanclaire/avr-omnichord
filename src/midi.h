#include <stdint.h>

#ifndef MIDI_H
#define MIDI_H

void midiInitTx();
void midiNoteOn(int8_t midiPitch);
void midiNoteOff(int8_t midiPitch);

#endif
