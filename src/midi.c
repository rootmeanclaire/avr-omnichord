#include <stdint.h>
#include <avr/io.h>
#include "midi.h"

#define BAUD_MIDI 31250
#define UBRR_MIDI (((F_CPU / 16) / BAUD_MIDI) - 1)
#define VEL_NOTE_ON 100

void midiInitTx() {
	//Set baud rate
	UBRR0H = UBRR_MIDI >> 8;
	UBRR0L = UBRR_MIDI & 0xFF;

	//Enable for transmission
	UCSR0B = (1 << TXEN0);

	//8 data bits
	UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}

void midiNoteOn(int8_t midiPitch) {
	//Wait for buffer to empty
	while (!(UCSR0A & (1 << UDRE0)));
	//Write Channel/Note On
	UDR0 = 0x90;

	//Wait for buffer to empty
	while (!(UCSR0A & (1 << UDRE0)));
	//Write Ptich
	UDR0 = midiPitch;

	//Wait for buffer to empty
	while (!(UCSR0A & (1 << UDRE0)));
	//Write Ptich
	UDR0 = VEL_NOTE_ON;
}

void midiNoteOff(int8_t midiPitch) {
	//Wait for buffer to empty
	while (!(UCSR0A & (1 << UDRE0)));
	//Write Channel/Note On
	UDR0 = 0x90;

	//Wait for buffer to empty
	while (!(UCSR0A & (1 << UDRE0)));
	//Write Ptich
	UDR0 = midiPitch;

	//Wait for buffer to empty
	while (!(UCSR0A & (1 << UDRE0)));
	//Write Ptich
	UDR0 = 0;
}
