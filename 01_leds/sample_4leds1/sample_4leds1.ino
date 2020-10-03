/*
Sample Program 1 for 4 LEDs.
For Lecture of "Embedded System"
in Department of Mechanical Systems Engineering,
Faculty of Systems Design,
Tokyo Metropolitan University.
Oct. 2020. N.Takesue
*/

const int LED_PIN[4] = {3, 5, 9, 11}; // LEDのピン番号
const int TIME_LED = 200;             // LEDの点灯時間[ms]

void setup()
{
  pinMode(LED_PIN[0], OUTPUT);        // LEDをつなげたピンを出力モードに設定
  pinMode(LED_PIN[1], OUTPUT);        // LEDをつなげたピンを出力モードに設定
  pinMode(LED_PIN[2], OUTPUT);        // LEDをつなげたピンを出力モードに設定
  pinMode(LED_PIN[3], OUTPUT);        // LEDをつなげたピンを出力モードに設定
}

void loop()
{
  digitalWrite(LED_PIN[0], HIGH);     // LEDを発光パターンで点灯・消灯
  digitalWrite(LED_PIN[1], LOW );     // LEDを発光パターンで点灯・消灯
  digitalWrite(LED_PIN[2], LOW );     // LEDを発光パターンで点灯・消灯
  digitalWrite(LED_PIN[3], LOW );     // LEDを発光パターンで点灯・消灯
  delay(TIME_LED);                    // TIME_LEDミリ秒待機
  digitalWrite(LED_PIN[0], LOW );     // LEDを発光パターンで点灯・消灯
  digitalWrite(LED_PIN[1], HIGH);     // LEDを発光パターンで点灯・消灯
  digitalWrite(LED_PIN[2], LOW );     // LEDを発光パターンで点灯・消灯
  digitalWrite(LED_PIN[3], LOW );     // LEDを発光パターンで点灯・消灯
  delay(TIME_LED);                    // TIME_LEDミリ秒待機
  digitalWrite(LED_PIN[0], LOW );     // LEDを発光パターンで点灯・消灯
  digitalWrite(LED_PIN[1], LOW );     // LEDを発光パターンで点灯・消灯
  digitalWrite(LED_PIN[2], HIGH);     // LEDを発光パターンで点灯・消灯
  digitalWrite(LED_PIN[3], LOW );     // LEDを発光パターンで点灯・消灯
  delay(TIME_LED);                    // TIME_LEDミリ秒待機
  digitalWrite(LED_PIN[0], LOW );     // LEDを発光パターンで点灯・消灯
  digitalWrite(LED_PIN[1], LOW );     // LEDを発光パターンで点灯・消灯
  digitalWrite(LED_PIN[2], LOW );     // LEDを発光パターンで点灯・消灯
  digitalWrite(LED_PIN[3], HIGH);     // LEDを発光パターンで点灯・消灯
  delay(TIME_LED);                    // TIME_LEDミリ秒待機
  digitalWrite(LED_PIN[0], LOW );     // LEDを発光パターンで点灯・消灯
  digitalWrite(LED_PIN[1], LOW );     // LEDを発光パターンで点灯・消灯
  digitalWrite(LED_PIN[2], HIGH);     // LEDを発光パターンで点灯・消灯
  digitalWrite(LED_PIN[3], LOW );     // LEDを発光パターンで点灯・消灯
  delay(TIME_LED);                    // TIME_LEDミリ秒待機
  digitalWrite(LED_PIN[0], LOW );     // LEDを発光パターンで点灯・消灯
  digitalWrite(LED_PIN[1], HIGH);     // LEDを発光パターンで点灯・消灯
  digitalWrite(LED_PIN[2], LOW );     // LEDを発光パターンで点灯・消灯
  digitalWrite(LED_PIN[3], LOW );     // LEDを発光パターンで点灯・消灯
  delay(TIME_LED);                    // TIME_LEDミリ秒待機
}
