/*
  Sample Program 3 of PWM for 4 LED.
  For Lecture of "Embedded System"
  in Department of Mechanical Systems Engineering,
  Faculty of Systems Design,
  Tokyo Metropolitan University.
  Oct. 2020. N.Takesue
*/
const int NUM_LED = 4;                // LEDの個数
const int LED_PIN[NUM_LED] = {3, 5, 9, 11}; // LEDのピン番号
const int DUTY[NUM_LED] = {8, 16, 32, 64};  // LEDのデューティ比(x/255)
int j = 0;                            // 順番をずらす値

void setup()
{
}

void loop()
{
  for (int i = 0; i < NUM_LED; i++) {
    // LEDにそれぞれのデューティ比でPWM出力
    analogWrite(LED_PIN[i], DUTY[(i + j) % NUM_LED]);
  }
  delay(2000);
  j++;                                // デューティ比の順番をずらす
}
