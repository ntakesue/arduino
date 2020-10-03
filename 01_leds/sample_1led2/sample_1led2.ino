/*
Sample Program 2 for LED.
For Lecture of "Embedded System"
in Department of Mechanical Systems Engineering,
Faculty of Systems Design,
Tokyo Metropolitan University.
Oct. 2020. N.Takesue
*/

const int LED_PIN = 11;         // LEDを接続したピン番号を定義

void setup()
{
  pinMode(LED_PIN, OUTPUT);     // LEDのピンを出力モードに設定
}

void loop()
{
  digitalWrite(LED_PIN, HIGH);  // LEDのピンからHIGHを出力
  delay(1000);                  // 1秒待機
  digitalWrite(LED_PIN, LOW);   // LEDのピンからLOWを出力
  delay(1000);                  // 1秒待機
}
