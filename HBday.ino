
#define buzzPin 8

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzPin, OUTPUT);
  Serial.begin(9600);

}
String letterNotes[] = {"C4","C4","D4","C4","F4","E4","C4","C4","D4","C4","G4","F4","C4","C4","C5","A4","F4","E4","D4","Bflat4","A4","F4","G4","F4"}
int notes[] = {262, 262, 294, 262, 349, 330, 262, 262, 294, 262, 392, 349, 262, 262, 524, 440, 349, 330, 294, 466, 466, 440, 349, 392, 349};

int duration[] = {1, 1, 2, 2, 2, 3, 1, 1, 2, 2, 2, 3, 1, 1, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 3};

double delays[] = {0.75,1,1,1,1,1,0.75,1,1,1,1,1,0.75,1,1,1,1,1,1,0.75,1,1,1,1,1};

// Defining functions for notes

void Do(int t) {
  tone(buzzPin, 440, t); 
}
void Re(int t) {
  tone(buzzPin, 494, t); 
}
void Mi(int t) {
  tone(buzzPin, 554, t); 
}
void Fa(int t) {
  tone(buzzPin, 587, t); 
}
void So(int t) {
  tone(buzzPin, 659, t); 
}
void La(int t) {
  tone(buzzPin, 740, t); 
}
void Ti(int t) {
  tone(buzzPin, 831, t); 
}
void Do2(int t) {
  tone(buzzPin, 880, t); 
}


void loop() {
  // put your main code here, to run repeatedly:
  
  for (int i = 0; i < sizeof(notes) / 2; i++) {
    Serial.println(notes[i]);
    tone(buzzPin, notes[i], 400 * duration[i]);
    delay(1000*delays[i]);
  }
  Serial.println("***********");
  delay(3000);

  

}
