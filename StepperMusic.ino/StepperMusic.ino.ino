//Set Variables and Pin Numbers
const int stepPin1 = 2;
const int stepPin2 = 3;
const int stepPin3 = 4;
const int stepPin4 = 5;

//values for timing
int tempo = 100;
int gap = 500;
int wait[] = {0,0,0,0};
bool currNote[] = {LOW,LOW,LOW,LOW};
unsigned int currRotation[] = {0,0,0,0};
unsigned long getPeriod(unsigned long period){return (period + micros());}
unsigned long getNote(unsigned long duration){return ((duration*tempo)+millis());}

//period for notes is given by 1/frequency, to allow for better periods I multiplied by 10^6 to obtain the values
//the notes are arrays where the indices represent the note period at each octive
unsigned long C[] = {61156, 30578, 15289, 7644, 3822, 1911, 955, 477, 238};
unsigned long Cs[] = {0, 0, 0, 0, 0, 0, 0, 451, 225};
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
  unsigned long currentMillis = millis();
  unsigned long currentMicros = micros();
  //find the note durations and set end time
  isDone(currentMillis, M1, 0);
  isDone(currentMillis, M2, 1);
  isDone(currentMillis, M3, 2);
  isDone(currentMillis, M4, 3);
  //find period lengths and play notes
  changeNote(currentMillis, M1, 0);
  changeNote(currentMillis, M2, 1);
  changeNote(currentMillis, M3, 2);
  changeNote(currentMillis, M4, 3);
}

//Helper Functions
void isDone(unsigned long current, int motor, int num){
  if (current >= nextNote[num]){
    currRotation[num]++;
    nextNote[num] = getNote(motor[currRotation[num]][1]);
    wait[0] = 1;
  }
}

void changeNote(unsigned long current, int motor, int num){
  String pin = stepPin + String(num)
  if (current >= noteLength[num]){
      if (wait[num] > 0){
        if (wait[num] == gap) 
          wait[num] = 0;
        else
          wait[num]++;
      }
      else{
        currNote[num] = !currNote[num];
        digitalWrite(pin, currNote[num]);
        noteLength[num] = getPeriod(motor[currRotation[num]][0]); 
     }
   }
}
