/*
  Sample Program 1 of Practice (Traffic Signal).
  For Lecture of "Embedded System"
  in Department of Mechanical Systems Engineering,
  Faculty of Systems Design,
  Tokyo Metropolitan University.
  Oct. 2020. N.Takesue
*/

void setup() {
  pinMode(3, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(11, OUTPUT);
  digitalWrite(3, LOW);
  digitalWrite(9, LOW);
  digitalWrite(11, LOW);
}

void loop() {
  digitalWrite(3, HIGH);
  delay(3000);
  digitalWrite(3, LOW);
  digitalWrite(9, HIGH);
  delay(1000);
  digitalWrite(9, LOW);
  digitalWrite(11, HIGH);
  delay(4000);
  digitalWrite(11, LOW);
}
