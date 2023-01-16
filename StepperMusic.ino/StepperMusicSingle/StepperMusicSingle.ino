#include <Stepper.h>

//Set Variables and Pin Numbers
const int stepPin = 2;
const int dirPin = 5;

//values for timing
bool current = LOW;
int duration = 100;
int tempo = 120;

//period for notes is given by 1/frequency, to allow for better periods I multiplied by 10^6 to obtain the values
//the notes are arrays where the indices represent the note period at each octive
unsigned long C[] = {61156, 30578, 15289, 7644, 3822, 1911, 955, 477, 238};
unsigned long Cs[] = {57723, 28861, 14431, 7215, 3608, 1804, 902, 451, 225};
unsigned long D[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
unsigned long Ds[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
unsigned long E[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
unsigned long F[] = {45815, 22907, 11453, 5726, 2863, 1431, 715, 357, 178};
unsigned long Fs[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
unsigned long G[] = {0, 0, 0, 0, 0, 0, 637, 318, 159};
unsigned long Gs[] = {0, 0, 0, 0, 0, 0, 602, 301, 150};
unsigned long A[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
unsigned long As[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
unsigned long B[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

void setup(){
  //setup code: output pins for motor
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
}

void loop(){
  //main code: runs music for song
  int gap = floor(duration/100)*tempo;
  getNote(G[2], 500);
  delay(gap);
  getNote(C[2], 500);
  delay(gap);
  getNote(G[3], 500);
  delay(gap);
  getNote(Gs[2], 500);
  delay(gap);
  getNote(Cs[2], 500);
  delay(gap);
  getNote(Gs[3], 500);
  delay(gap);
}

//Helper Functions
//Write note to motor
void getNote(int note, long duration){
  current = !current;
  digitalWrite(dirPin,current);
  for(int i = 0; i < floor(duration); i++) {
    digitalWrite(stepPin,HIGH);
    delayMicroseconds(note);
    digitalWrite(stepPin,LOW);
    delayMicroseconds(note);
  }
}
