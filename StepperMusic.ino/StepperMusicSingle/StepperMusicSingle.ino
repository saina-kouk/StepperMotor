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
unsigned long D[] = {54484, 27242, 13621, 6810, 3405, 1703, 851, 426, 213};
unsigned long Ds[] = {51426, 25712, 12856, 6428, 3214, 1607, 804, 402, 201};
unsigned long E[] = {48540, 24270, 12134, 6067, 3034, 1517, 758, 379, 190};
unsigned long F[] = {45815, 22907, 11453, 5726, 2863, 1431, 715, 357, 178};
unsigned long Fs[] = {43244, 21622, 10810, 5405, 2703, 1351, 676, 338, 169};
unsigned long G[] = {40817, 20408, 10204, 5102, 2551, 1275, 637, 318, 159};
unsigned long Gs[] = {38526, 19263, 9631, 4816, 2408, 1204, 602, 301, 150};
unsigned long A[] = {36364, 18182, 9091, 4545, 2272, 1136, 568, 284, 142};
unsigned long As[] = {34323, 17161, 8581, 4290, 2145, 1072, 536, 268, 134};
unsigned long B[] = {32396, 16198, 8099, 4050, 2024, 1012, 506, 253, 127};

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
