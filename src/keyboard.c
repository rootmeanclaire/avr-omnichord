#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay_basic.h>
#include "chords.h"
#include "keyboard.h"

//From port D
#define PIN_DATA 3
#define PIN_CLK 4
#define PIN_INT_CLK PCINT20 

//Set to 1 if data is in the middle of being read
volatile uint8_t reading = 0;
//Last fully received byte of data
volatile uint8_t lastData = KEYCODE_BREAK;
//Temp variable to store data as it is being read
volatile uint8_t tmpData = 0;
//Bit mask for the current bit of tmpData that is being written
volatile uint8_t currBitMask = (1 << 0);
//Set to 1 if the parity bit of the current packet has been received
volatile uint8_t parityReceived = 0;
//Set to 1 if next key should be treated as key up
volatile uint8_t nextKeyUp = 0;

uint8_t getParity(uint8_t data) {
	uint8_t numOnes = 0;

	for (uint8_t currBitMask = (1 << 0); currBitMask != 0; currBitMask = currBitMask << 1) {
		if (data & currBitMask) {
			numOnes++;
		}
	}

	return numOnes % 2 == 0;
}

void keyboardInitRx() {
	//Set pins to input
	DDRD &= ~((1 << PIN_DATA) | (1 << PIN_CLK));
	//Enable pullup on clock pin
	PORTD |= (1 << PIN_CLK);
	//Set clock pin for interrupt
	PCMSK2 |= (1 << PIN_INT_CLK);
	//Enable interrupt on clock pin
	PCICR |= (1 << PCIE2);
}

ISR(PCINT2_vect) {
	//If data ready
	if ((PIND & (1 << PIN_CLK)) == 0) {
		//If start bit
		if (!reading) {
			reading = 1;
		}
		//If data bit
		else if (currBitMask != 0) {
			if (PIND & (1 << PIN_DATA)) {
				tmpData |= currBitMask;
			}
			currBitMask = currBitMask << 1;
		}
		//If parity bit
		else if (!parityReceived) {
			parityReceived = 1;
		}
		//If stop bit
		else {
			if (nextKeyUp) {
				nextKeyUp = 0;
			} else {
				lastData = tmpData;
				if (tmpData == KEYCODE_BREAK) {
					nextKeyUp = 1;
				}
			}

			reading = 0;

			//Clear temp variables to prepare for next read
			tmpData = 0;
			currBitMask = (1 << 0);
			parityReceived = 0;
		}
	}
}

uint8_t getCurrKeyCode() {
	return lastData;
}

uint8_t keycodeToChord(uint8_t keycode) {
	if (keycode == KEYCODE_Q || keycode == KEYCODE_A || keycode == KEYCODE_Z) {
		return CR_E_FLAT;
	} else if (keycode == KEYCODE_W || keycode == KEYCODE_S || keycode == KEYCODE_X) {
		return CR_B_FLAT;
	} else if (keycode == KEYCODE_E || keycode == KEYCODE_D || keycode == KEYCODE_C) {
		return CR_F;
	} else if (keycode == KEYCODE_R || keycode == KEYCODE_F || keycode == KEYCODE_V) {
		return CR_C;
	} else if (keycode == KEYCODE_T || keycode == KEYCODE_G || keycode == KEYCODE_B) {
		return CR_G;
	} else if (keycode == KEYCODE_Y || keycode == KEYCODE_H || keycode == KEYCODE_N) {
		return CR_D;
	} else if (keycode == KEYCODE_U || keycode == KEYCODE_J || keycode == KEYCODE_M) {
		return CR_A;
	} else if (keycode == KEYCODE_I || keycode == KEYCODE_K || keycode == KEYCODE_COMMA) {
		return CR_E;
	} else if (keycode == KEYCODE_O || keycode == KEYCODE_L || keycode == KEYCODE_PERIOD) {
		return CR_B;
	} else if (keycode == KEYCODE_P || keycode == KEYCODE_SEMICOLON || keycode == KEYCODE_SLASH) {
		return CR_F_SHARP;
	} else {
		return CR_NULL;
	}
}

uint8_t getButtonMask(uint8_t keycode) {
	if (keycode == KEYCODE_Q || keycode == KEYCODE_W || keycode == KEYCODE_E || keycode == KEYCODE_R || keycode == KEYCODE_T || keycode == KEYCODE_Y || keycode == KEYCODE_U || keycode == KEYCODE_I || keycode == KEYCODE_O) {
		return BMASK_MAJ;
	} else if (keycode == KEYCODE_A || keycode == KEYCODE_S || keycode == KEYCODE_D || keycode == KEYCODE_F || keycode == KEYCODE_G || keycode == KEYCODE_H || keycode == KEYCODE_J || keycode == KEYCODE_K || keycode == KEYCODE_L) {
		return BMASK_MIN;
	} else if (keycode == KEYCODE_Z || keycode == KEYCODE_X || keycode == KEYCODE_C || keycode == KEYCODE_V || keycode == KEYCODE_B || keycode == KEYCODE_N || keycode == KEYCODE_M || keycode == KEYCODE_COMMA || keycode == KEYCODE_PERIOD) {
		return BMASK_SEV;
	} else {
		return 0;
	}
}
