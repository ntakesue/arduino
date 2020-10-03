/*
Sample Program 3 for LED.
For Lecture of "Embedded System"
in Department of Mechanical Systems Engineering,
Faculty of Systems Design,
Tokyo Metropolitan University.
Oct. 2020. N.Takesue
*/

const int LED_PIN = 11;         // LEDを接続したピン番号を定義
const int TIME_LED_ON = 200;    // LEDの点灯時間[ms]
const int TIME_LED_OFF = 200;   // LEDの消灯時間[ms]

void setup()
{
  pinMode(LED_PIN, OUTPUT);     // LEDのピンを出力モードに設定
}

void loop()
{
  digitalWrite(LED_PIN, HIGH);  // LEDのピンからHIGHを出力
  delay(TIME_LED_ON);           // TIME_LED_ONミリ秒待機
  digitalWrite(LED_PIN, LOW);   // LEDのピンからLOWを出力
  delay(TIME_LED_OFF);          // TIME_LED_OFFミリ秒待機
}
