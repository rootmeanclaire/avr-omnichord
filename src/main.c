#include <util/delay.h>
#include "chords.h"

int main() {
	midiInitTx();

	while (1) {
		chordOn(CR_C, BMASK_MAJ);
		_delay_ms(2000);
		chordOn(CR_G, BMASK_MAJ);
		_delay_ms(2000);
		chordOn(CR_A, BMASK_MIN);
		_delay_ms(2000);
		chordOn(CR_F, BMASK_MAJ);
		_delay_ms(2000);
	}

	return 0;
}
