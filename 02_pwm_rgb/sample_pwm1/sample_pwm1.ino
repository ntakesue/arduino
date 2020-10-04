/*
  Sample Program 1 of PWM for 1 LED.
  For Lecture of "Embedded System"
  in Department of Mechanical Systems Engineering,
  Faculty of Systems Design,
  Tokyo Metropolitan University.
  Oct. 2020. N.Takesue
*/
const int LED_PIN = 11;         // LEDを接続したピン番号を定義
const int DUTY_CYCLE = 128;     // デューティ比128/255
int mode = 0;                   // LEDの光り方を選択

void setup()
{
  //analogWriteで出力する場合はpinModeの設定は不要
}

void loop()
{
  mode = millis() / 10000;
  // LEDのピンからPWM出力
  switch (mode) {
    case 0:
      // 一定の明るさ
      analogWrite(LED_PIN, DUTY_CYCLE);
      break;
    case 1:
      // 明るくなったり暗くなったり（その１）
      analogWrite(LED_PIN, DUTY_CYCLE * abs(sin(2.0 * PI * millis() / 1000.0))); // LEDのピンからPWM出力
      break;
    case 2:
    default:
      // 明るくなったり暗くなったり（その２）
      analogWrite(LED_PIN, DUTY_CYCLE * (sin(2.0 * PI * millis() / 1000.0) + 1) / 2.0); // LEDのピンからPWM出力
  }
}
