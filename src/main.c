#include <avr/io.h>
#include <avr/interrupt.h>
#include "keyboard.h"
#include "midi.h"
#include "chords.h"

int main() {
	uint8_t keycode = 0;
	uint8_t keycodeLast = 0;

	keyboardInitRx();
	midiInitTx();

	sei();

	DDRD |= (1 << 7);

	while (1) {
		keycode = getCurrKeyCode();

		if (keycode != keycodeLast) {
			if (keycode != KEYCODE_BREAK) {
				chordOn(keycodeToChord(keycode), BMASK_MAJ);
			} else {
				lastChordOff();
			}
			keycodeLast = keycode;
		}
	}

	return 0;
}
