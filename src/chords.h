#ifndef CHORDS_H
#define CHORDS_H

/*
//Notes (lowest MIDI)
#define NOTE_B 11
#define NOTE_B_FLAT 10
#define NOTE_A_SHARP 10
#define NOTE_A 9
#define NOTE_A_FLAT 8
#define NOTE_G_SHARP 8
#define NOTE_G 7
#define NOTE_G_FLAT 6
#define NOTE_F_SHARP 6
#define NOTE_F 5
#define NOTE_E 4
#define NOTE_E_FLAT 3
#define NOTE_D_SHARP 3
#define NOTE_D 2
#define NOTE_D_FLAT 1
#define NOTE_C_SHARP 1
#define NOTE_C 0
*/

//Chords (in button order)
#define CR_E_FLAT 0
#define CR_B_FLAT 1
#define CR_F 2
#define CR_C 3
#define CR_G 4
#define CR_D 5
#define CR_A 6
#define CR_E 7
#define CR_B 8
#define CR_F_SHARP 9

//Intervals
#define INTVL_UNISON 0
#define INTVL_MIN_SECOND 1
#define INTVL_MAJ_SECOND 2
#define INTVL_MIN_THIRD 3
#define INTVL_MAJ_THIRD 4
#define INTVL_PER_FOURTH 5
#define INTVL_AUG_FOURTH 6
#define INTVL_TRITONE 6
#define INTVL_DIM_FIFTH 6
#define INTVL_PER_FIFTH 7
#define INTVL_MIN_SIXTH 8
#define INTVL_MAJ_SIXTH 9
#define INTVL_MIN_SEVENTH 10
#define INTVL_MAJ_SEVENTH 11
#define INTVL_OCTAVE 12

//Button masks
#define BMASK_MAJ (1 << 0)
#define BMASK_MIN (1 << 1)
#define BMASK_SEV (1 << 2)

#endif
