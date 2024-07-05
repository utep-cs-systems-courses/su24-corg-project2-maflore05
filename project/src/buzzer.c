#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"

void buzzer_init()
{
  /* 
       Direct timer A output "TA0.1" to P2.6.  
        According to table 21 from data sheet:
          P2SEL2.6, P2SEL2.7, anmd P2SEL.7 must be zero
          P2SEL.6 must be 1
        Also: P2.6 direction must be output
  */

  timerAUpmode();           /* used to drive speaker */
  P2SEL2 &= ~(BIT6 | BIT7);
  P2SEL &= ~BIT7;
  P2SEL |= BIT6;
  P2DIR = BIT6;             /* enable output to speaker (P2.6) */
}

void buzzer_set_period(short cycles) // buzzer clock = 2MHz.  (period of 1k results in 2kHz tone)
{
  CCR0 = cycles;
  CCR1 = cycles >> 1;/* one half cycle */
}


void state_1()
{
  const int MAX = 6000;             // Max note frequency
  const int MIN = 200;              // Minimum note frequency
  static int increment = 200;       // Incrementer for current note
  static int current_note = 1000;   // Current note frequency

  // When current note reaches MAX, incrementer subtracts. When it reaches MIN, incrementer adds
  if (current_note == MAX) {
    increment = -200;
  } else if (current_note == MIN) {
    increment = 200;
  }
  buzzer_set_period(current_note);
  current_note += increment;
}

void state_2()
{
  int length = 42;
  static int index1 = 0;
  int notes[42] = {659, 659, 659, 523, 659, 784, 392, 523, 392, 330, 440, 494, 466, 440, 392, 659, 784, 880, 698, 784, 659, 523, 587, 494, 523, 392, 330, 440, 494, 466, 440, 392, 659, 784, 880, 698, 784, 659, 523, 587, 494}; // Angry Birds Theme
  if (index1 == length) {
    index1 = 0;
  } else {
    buzzer_set_period(notes[index1]);
    index1++;
  }
}

void state_3()
{
  int length = 32;
  static int index2 = 0;
  int notes[32] = {554, 554, 622, 554, 740, 622, 554, 622, 554, 740, 622, 554, 622, 554, 740, 622, 554, 622, 554, 740, 622, 554, 622, 554, 740, 622, 554, 622, 554, 740, 622, 554}; // Careless Whisper Saxophone Part
  if (index2 == length) {
    index2 = 0;
  } else {
    buzzer_set_period(notes[index2]);
    index2++;
  }
}

void state_4()
{
  int length = 52;
  static int index3 = 0;
  int notes[52] = {659, 659, 523, 659, 784, 392, 523, 392, 330, 440, 494, 466, 440, 392, 659, 784, 880, 698, 784, 659, 523, 587, 494, 523, 392, 330, 440, 494, 466, 440, 392, 659, 784, 880, 698, 784, 659, 523, 587, 494, 523, 392, 330, 440, 494, 466, 440, 392, 659, 784, 880, 698}; // Super Mario Bros Theme
  if (index3 == length) {
    index3 = 0;
  } else {
    buzzer_set_period(notes[index3]);
    index3++;
  }
}
