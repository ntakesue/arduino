/*
Sample Program 2 for 4 LEDs.
For Lecture of "Embedded System"
in Department of Mechanical Systems Engineering,
Faculty of Systems Design,
Tokyo Metropolitan University.
Oct. 2020. N.Takesue
*/

const int NUM_LED = 4;                      // LEDの個数
const int LED_PIN[NUM_LED] = {3, 5, 9, 11}; // LEDのピン番号
const int NUM_PATTERN = 6;                  // LEDの発光パターン数
const int PATTERN[NUM_PATTERN][NUM_LED]={   // LEDの発光パターン
  {HIGH, LOW, LOW, LOW},
  {LOW, HIGH, LOW, LOW},
  {LOW, LOW, HIGH, LOW},
  {LOW, LOW, LOW, HIGH},
  {LOW, LOW, HIGH, LOW},
  {LOW, HIGH, LOW, LOW},};
const int TIME_LED = 200;                   // LEDの点灯時間[ms]

void setup()
{
  for(int i=0; i<NUM_LED; i++){
    pinMode(LED_PIN[i], OUTPUT);    // LEDをつなげたピンを出力モードに設定
  }
}

void loop()
{
  for(int j=0; j<NUM_PATTERN; j++){
    for(int i=0; i<NUM_LED; i++){
      digitalWrite(LED_PIN[i], PATTERN[j][i]);  // LEDを発光パターンで点灯・消灯
    }
    delay(TIME_LED);            // TIME_LEDミリ秒待機
  }
}
