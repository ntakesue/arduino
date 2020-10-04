/*
  Sample Program for RGB-LED.
  For Lecture of "Embedded System"
  in Department of Mechanical Systems Engineering,
  Faculty of Systems Design,
  Tokyo Metropolitan University.
  Oct. 2020. N.Takesue
*/
const int NUM_LED = 3;            // LEDの個数
const int LED_PIN[NUM_LED] = {9, 10, 11}; // LEDのピン番号(RGB)
const int BRIGHTNESS = 128;       // 最大のデューティ比(x/255)
const float PERIOD = 5000.0;      // 明るさ（デューティ比）を変化する周期[ms]
const int UPDATE_TIME = 50;       // 明るさ（デューティ比）を更新する周期[ms]

void setup() {}

void loop()
{
  for (int i = 0; i < NUM_LED; i++) {
    analogWrite(LED_PIN[i], BRIGHTNESS * 
    (sin(2.0 * PI * ((float)millis() / PERIOD - (float)i / 3.0)) + 1) * 0.5);
  }
  delay(UPDATE_TIME);                // デューティ比の更新を待機
}
