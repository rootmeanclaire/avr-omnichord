#include <stdint.h>
#include "midi.h"
#include "chords.h"

#define NUM_CHORD_VOICES 4

const uint8_t CHORD_MAJ_TRI[NUM_CHORD_VOICES] = {INTVL_UNISON, INTVL_MAJ_THIRD, INTVL_PER_FIFTH, INTVL_OCTAVE};
const uint8_t CHORD_MIN_TRI[NUM_CHORD_VOICES] = {INTVL_UNISON, INTVL_MIN_THIRD, INTVL_PER_FIFTH, INTVL_OCTAVE};
const uint8_t CHORD_DOM_SEV[NUM_CHORD_VOICES] = {INTVL_UNISON, INTVL_MAJ_THIRD, INTVL_PER_FIFTH, INTVL_MIN_SEVENTH};
const uint8_t CHORD_MAJ_SEV[NUM_CHORD_VOICES] = {INTVL_UNISON, INTVL_MAJ_THIRD, INTVL_PER_FIFTH, INTVL_MAJ_SEVENTH};
const uint8_t CHORD_MIN_SEV[NUM_CHORD_VOICES] = {INTVL_UNISON, INTVL_MIN_THIRD, INTVL_PER_FIFTH, INTVL_MIN_SEVENTH};

//List of chord notes that are currently on, -1 if no note is on
int8_t currHarmony[NUM_CHORD_VOICES] = {-1, -1, -1, -1};
int8_t currOctave = 4;

void lastChordOff() {
	for (uint8_t i = 0; i < NUM_CHORD_VOICES; ++i) {
		if (currHarmony > 0) {
			midiNoteOff(currHarmony[i]);
			currHarmony[i] = -1;
		}
	}
}

//chordRott = one of the CR_... defines
//buttonMask = bitwise or combo of BMASK_ defines
void chordOn(uint8_t chordRoot, uint8_t buttonMask) {
	uint8_t const *notes;
	int8_t root;

	//Determine chord quality from button mask
	if (buttonMask == BMASK_MAJ) {
		notes = CHORD_MAJ_TRI;
	} else if (buttonMask == BMASK_MIN) {
		notes = CHORD_MIN_TRI;
	} else if (buttonMask == BMASK_SEV) {
		notes = CHORD_DOM_SEV;
	} else if (buttonMask == (BMASK_MAJ | BMASK_SEV)) {
		notes = CHORD_MAJ_SEV;
	} else if (buttonMask == (BMASK_MIN | BMASK_SEV)) {
		notes = CHORD_MIN_SEV;
	} else {
		//Don't do anything if invalid button combination
		return;
	}

	root = ((chordRoot - CR_C) * INTVL_PER_FIFTH) + (2 * INTVL_OCTAVE);

	lastChordOff();

	for (uint8_t i = 0; i < NUM_CHORD_VOICES; ++i) {
		currHarmony[i] = (
			(
				(root + notes[i]) % INTVL_OCTAVE
			) + (
				(currOctave + 1) * INTVL_OCTAVE
			)
		);

		midiNoteOn(currHarmony[i]);
	}
}
