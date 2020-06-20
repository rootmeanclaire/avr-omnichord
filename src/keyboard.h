#include <stdint.h>
#include <avr/io.h>

#ifndef KEYBOARD_H
#define KEYBOARD_H

#define KEYCODE_BREAK 0xF0
#define KEYCODE_A 0x1C
#define KEYCODE_B 0x32
#define KEYCODE_C 0x21
#define KEYCODE_D 0x23
#define KEYCODE_E 0x24
#define KEYCODE_F 0x2B
#define KEYCODE_G 0x34
#define KEYCODE_H 0x33
#define KEYCODE_I 0x43
#define KEYCODE_J 0x3B
#define KEYCODE_K 0x42
#define KEYCODE_L 0x4B
#define KEYCODE_M 0x3A
#define KEYCODE_N 0x31
#define KEYCODE_O 0x44
#define KEYCODE_P 0x4D
#define KEYCODE_Q 0x15
#define KEYCODE_R 0x2D
#define KEYCODE_S 0x1B
#define KEYCODE_T 0x2C
#define KEYCODE_U 0x3C
#define KEYCODE_V 0x2A
#define KEYCODE_W 0x1D
#define KEYCODE_X 0x22
#define KEYCODE_Y 0x35
#define KEYCODE_Z 0x1A
#define KEYCODE_SEMICOLON 0x4C
#define KEYCODE_COMMA 0x41
#define KEYCODE_PERIOD 0x49
#define KEYCODE_SLASH 0x4A

void keyboardInitRx();
uint8_t getCurrKeyCode();
uint8_t keycodeToChord(uint8_t keycode);
uint8_t getButtonMask(uint8_t keycode);

#endif
