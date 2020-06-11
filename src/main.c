#include <util/delay.h>
#include "midi.h"

int main() {
	midiInitTx();

	while (1) {
		midiNoteOn(69);
		_delay_ms(1000);
		midiNoteOff(69);
		_delay_ms(100);
	}

	return 0;
}
