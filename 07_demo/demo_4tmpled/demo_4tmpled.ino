/*
  Sample Program 4 for 4 LEDs and Temperature Sensor.
  For Lecture of "Embedded System"
  in Department of Mechanical Systems Engineering,
  Faculty of Systems Design,
  Tokyo Metropolitan University.
  Nov. 2020. N.Takesue
*/

const int NUM_LED = 4;                        // LEDの個数
const int LED_PIN[NUM_LED] = {3, 5, 9, 11};   // LEDのピン番号
const int DUTY[NUM_LED] = {8, 16, 32, 64};    // LEDのデューティ比
const int BUTTON_PIN = 2;                     // ボタンスイッチのピン番号
const int TEMP_PIN = A0;
int ain, temp;

void setup()
{
  analogReference(INTERNAL);
  pinMode(BUTTON_PIN, INPUT_PULLUP);          // ボタンスイッチのピンをプルアップ入力モードに設定
}

void tempRead()
{
  ain = analogRead(TEMP_PIN);
  temp = map(ain, 0, 1023, 0, 110);
}

void loop()
{
  tempRead();
  for (int j = 0; j < NUM_LED; j++) {
    if (digitalRead(BUTTON_PIN) == LOW) {     // ボタンスイッチを
      delay(100 * (temp % 10));               // 押下していたら早く
    } else {
      delay(300 * (temp % 10));               // 離していたらゆっくり
    }
    for (int i = 0; i < NUM_LED; i++) {
      analogWrite(LED_PIN[i], DUTY[(i + j) % 4]); // それぞれのLEDにそれぞれのデューティ比でPWM出力
    }
  }
}
