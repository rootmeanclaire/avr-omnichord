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

	while (1) {
		keycode = getCurrKeyCode();

		if (keycode != keycodeLast) {
			if (keycode != KEYCODE_BREAK) {
				chordOn(keycodeToChord(keycode), getButtonMask(keycode));
			} else {
				lastChordOff();
			}
			keycodeLast = keycode;
		}
	}

	return 0;
}
