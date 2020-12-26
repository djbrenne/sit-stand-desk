
//Limit switch pin allocation
const int L1H=A0;
const int L1L=A1;
const int L2H=A2;
const int L2L=A3;
const int L3H=A4;
const int L3L=A5;
const int L4H=A6;
const int L4L=A7;

//Up, Down, Program switch pin allocation
const int up_pin = 7;
const int dwn_pin = 8;
const int prg_pin = 9;

//Buzzer pin allocation and constants
const int bzz_pin = 10;
const float c_note = 523.25; // Hz
const float d_note = 587.22; // Hz
const float e_note = 659.25; // Hz
const float f_note = 698.46; // Hz
const float g_note = 783.99; // Hz
const float b_note = 987.77; // Hz
const float C_note = 1046.5; // Hz
const int quarter = 150; // ms
const int eighth = quarter/2; //ms

//Relay pin allocations
const int dir_pin = 2;
const int leg1_pin = 3;
const int leg2_pin = 4;
const int leg3_pin = 5;
const int leg4_pin = 6;

void setup() {
  //Up, down, program switch setup
  pinMode(up_pin, INPUT);
  pinMode(dwn_pin, INPUT);
  pinMode(prg_pin, INPUT);

  //Relay pin setup
  pinMode(dir_pin, OUTPUT);
  pinMode(leg1_pin, OUTPUT);
  pinMode(leg2_pin, OUTPUT);
  pinMode(leg3_pin, OUTPUT);
  pinMode(leg4_pin, OUTPUT);

  digitalWrite(dir_pin, LOW);
  digitalWrite(leg1_pin, HIGH);
  digitalWrite(leg2_pin, HIGH);
  digitalWrite(leg3_pin, HIGH);
  digitalWrite(leg4_pin, HIGH);

  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(up_pin)) {
    announceUpward();
    digitalWrite(dir_pin, HIGH);
  }
  if (digitalRead(dwn_pin)) {
    announceDownward();
    digitalWrite(dir_pin, LOW);
  }
}

bool readLimit(int lim_switch){
  // convert analog limit switch reading to boolean value
  return analogRead(lim_switch) > 512;
}

void announceUpward(){
  // buzzer tone to annouce upward movement (upward inverted C-major chord)
  tone(bzz_pin, e_note);
  delay(quarter);
  delay(eighth);
  noTone(bzz_pin);
  tone(bzz_pin, g_note);
  delay(quarter);
  noTone(bzz_pin);
  tone(bzz_pin, C_note);
  delay(quarter);
  noTone(bzz_pin);
}

void announceDownward(){
  // buzzer tone to annouce upward movement (upward inverted C-major chord)
  tone(bzz_pin, g_note);
  delay(quarter);
  delay(eighth);
  noTone(bzz_pin);
  tone(bzz_pin, e_note);
  delay(quarter);
  noTone(bzz_pin);
  tone(bzz_pin, c_note);
  delay(quarter);
  noTone(bzz_pin);
}
