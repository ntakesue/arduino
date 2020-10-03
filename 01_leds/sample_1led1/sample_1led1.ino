/*
Sample Program 1 for LED.
For Lecture of "Embedded System"
in Department of Mechanical Systems Engineering,
Faculty of Systems Design,
Tokyo Metropolitan University.
Oct. 2020. N.Takesue
*/

void setup()
{
  pinMode(11, OUTPUT);          // 11ピンを出力モードに設定
}

void loop()
{
  digitalWrite(11, HIGH);       // 11ピンからHIGHを出力
  delay(1000);                  // 1秒待機
  digitalWrite(11, LOW);        // 11ピンからLOWを出力
  delay(1000);                  // 1秒待機
}
