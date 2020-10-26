/*
  Sample Program 3 of Practice (Knight2000).
  For Lecture of "Embedded System"
  in Department of Mechanical Systems Engineering,
  Faculty of Systems Design,
  Tokyo Metropolitan University.
  Oct. 2020. N.Takesue
*/

const int TIME_SAMPLE=25;           // 目標のデューティ比まで徐々に変える時間[ms]
const int TIME_CHANGE=400;          // 目標のデューティ比を変える時間[ms]
const int STEP=8;                   // デューティ比を変えるステップ値
const int NUM_LED=4;                // LEDの個数
const int led_pin[NUM_LED]={3, 5, 9, 11}; // LEDのピン番号
int led_duty[NUM_LED]={0, 0, 0, 0}; // LEDのデューティ比（最初はゼロで初期化）
const int NUM_PATTERN=6;            // LEDの発光パターン数
const int pattern[NUM_PATTERN][NUM_LED]={ // LEDの発光パターン
  {127, 0, 0, 0},  {0, 127, 0, 0},  {0, 0, 127, 0},
  {0, 0, 0, 127},  {0, 0, 127, 0},  {0, 127, 0, 0},};

void setup(){}

void loop()
{
  for(int j=0; j<NUM_PATTERN; j++){
    for(int k=0; k<TIME_CHANGE/TIME_SAMPLE; k++){
      for(int i=0; i<NUM_LED; i++){
        if(led_duty[i]<pattern[j][i]){          // 目標のデューティ比が大きかったら
          led_duty[i] = led_duty[i] + STEP;     // STEPを足す
          if(led_duty[i]>pattern[j][i]){        // 足しすぎたら
            led_duty[i] = pattern[j][i];        // 補正しておく
          }
        }else if(led_duty[i]>pattern[j][i]){    // 目標のデューティ比が小さかったら
          led_duty[i] = led_duty[i] - STEP;     // STEPを引く
          if(led_duty[i]<pattern[j][i]){        // 引きすぎたら
            led_duty[i] = pattern[j][i];        // 補正しておく
          }
        }
        analogWrite(led_pin[i], led_duty[i]);   // LEDをPWMで点灯
      }
      delay(TIME_SAMPLE);                // デューティ比の更新を待機
    }
  }
}

