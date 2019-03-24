#include "pitches.h"

int buzzerPin = 4; 
int durationShort = 4; //4 = quarter note
int durationlong = 8; //8 = eighth note

int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3//, 0, NOTE_B3, NOTE_C4
};
// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  durationShort, durationlong, durationlong, durationShort, durationShort//, durationShort, durationShort, durationShort
};

class Buzzer {
  public:
    void wellcomeSong(){
      // iterate over the notes of the melody:
      for (int thisNote = 0; thisNote < 5; thisNote++) {
        playTone(melody[thisNote], noteDurations[thisNote]);
      }
    }
    void eatSound(){
      playTone(NOTE_C5, durationShort);
    }
    void gameOver(){
      playTone(NOTE_C4, 4);
      playTone(NOTE_C3, 4);
    }
    void playTone(int thisNote, int noteDuration1){
     // to calculate the note duration, take one second
      // divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / noteDuration1;
      tone(buzzerPin, thisNote, noteDuration);

      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      // stop the tone playing:
      noTone(buzzerPin);
    }
};