/*
  Sample Program 2 of PWM for 4 LED.
  For Lecture of "Embedded System"
  in Department of Mechanical Systems Engineering,
  Faculty of Systems Design,
  Tokyo Metropolitan University.
  Oct. 2020. N.Takesue
*/
const int LED_PIN = 11;    // LEDを接続したピン番号を定義
const int PERIOD = 10;     // スイッチング周期
const int PULSE = 5;       // パルス幅

void setup()
{
  pinMode(LED_PIN, OUTPUT);
}

void loop()
{
  digitalWrite(LED_PIN, HIGH);
  delay(PULSE);
  digitalWrite(LED_PIN, LOW);
  delay(PERIOD - PULSE);
}
