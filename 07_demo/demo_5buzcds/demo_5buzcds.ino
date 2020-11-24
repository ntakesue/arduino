/*
  Sample Program 5 for Buzzer and CdS Light Sensor.
  For Lecture of "Embedded System"
  in Department of Mechanical Systems Engineering,
  Faculty of Systems Design,
  Tokyo Metropolitan University.
  Nov. 2020. N.Takesue
*/

const int BUZZER_PIN = 2;               // ブザーのピン番号
const int DURATION = 1200;              // 全音符の長さ[ms]
const int CdS_pin = A0;                  // 光センサのピン
int CdS;                                // 光センサの値

void setup()
{
  pinMode(BUZZER_PIN, OUTPUT);          // ブザーのピンを出力モードに設定
}

void loop()
{
  CdS = analogRead(CdS_pin);            // 光センサの値の読取
  tone(BUZZER_PIN, CdS, DURATION / 4);  // ブザー
  delay(DURATION / 4);
}
