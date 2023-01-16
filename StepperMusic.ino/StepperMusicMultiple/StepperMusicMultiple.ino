#include <Stepper.h>

//Set Variables and Pin Numbers
const int stepPin1 = 2;
const int stepPin2 = 3;
const int stepPin3 = 4;
const int stepPin4 = 5;

//values for timing
int tempo = 120;
int gap = 500;
int wait[] = {0,0,0,0};
bool currNote[] = {LOW,LOW,LOW,LOW};
unsigned int currRotation[] = {0,0,0,0};
unsigned long getPeriod(unsigned long period){return (period + micros());}
unsigned long getNote(unsigned long duration){return ((duration*tempo)+millis());}

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

//each motor contains the notes it should play and the duration of the note
//to create different sounds, these arrays should be changed to the desired notes
int M1[][2] = {{C[2], 4}, {Cs[2], 4}};
int M2[][2] = {{G[2], 4}, {Gs[2], 4}};
int M3[][2] = {{C[3], 4}, {Cs[3], 4}};
int M4[][2] = {{G[4], 2}, {Gs[4], 2}};

//get desired note lengths
unsigned long noteLength[] = {getPeriod(M1[0][0]), getPeriod(M2[0][0]), getPeriod(M3[0][0]), getPeriod(M4[0][0])};
unsigned long nextNote[] = {getNote(M1[0][1]), getNote(M2[0][1]), getNote(M3[0][1]), getNote(M4[0][1])};

//Running Functions
void setup() {
  //setup code: output pins for four motors
  pinMode(stepPin1, OUTPUT);
  pinMode(stepPin2, OUTPUT);
  pinMode(stepPin3, OUTPUT);
  pinMode(stepPin4, OUTPUT);
}

void loop() {
  //main code: runs music for song

}
