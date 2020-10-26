/*
  Sample Program of Button Switch and Buzzer.
  For Lecture of "Embedded System"
  in Department of Mechanical Systems Engineering,
  Faculty of Systems Design,
  Tokyo Metropolitan University.
  Oct. 2020. N.Takesue
*/
#include "pitches.h"

const int BUTTON_PIN=12;                                // ボタンスイッチのピン
int button_pres=HIGH;                                   // 現在のボタン状態
int button_prev=HIGH;                                   // 一回前のボタン状態
int count=0;                                            // カウント，表示数字

const int BUZZER_PIN=13;                                // ブザーのピン
const int DURATION=1200;                                // 全音符の長さ[ms]
const int NUM_MELODY1=12;                               // 音符の数
int melody1[NUM_MELODY1][2]={                           // 音符（音の高さと長さ）
  {NOTE_E3, 8},  {NOTE_E3, 8},  {0,       8},  {NOTE_E3, 8},  {0,       8},  {NOTE_C3, 8},
  {NOTE_E3, 8},  {0,       8},  {NOTE_G3, 8},  {0,       8},  {0,       4},  {NOTE_G2, 8},
};

void button_check(void)
{
  button_pres = digitalRead(BUTTON_PIN);                // ボタンの読取
  if(button_pres == LOW && button_prev == HIGH){        // 押下されたら
    count = (++count)%100;                              // カウントアップ
    if(count!=10){                                      // カウントが10でなければ
      tone(BUZZER_PIN, 440, DURATION/16);               // ブザー音を少し鳴らす
      delay(DURATION/16);
    }
  }
  button_prev = button_pres;                            // 読み取ったボタン状態を記憶
}

void setup()
{
  pinMode(BUTTON_PIN, INPUT_PULLUP);                    // buttonのピンを入力モードに設定
  pinMode(BUZZER_PIN, OUTPUT);                          // buzzerのピンを出力モードに設定
}

void loop()
{
  button_check();                                       // ボタン状態のチェック
  if(count==10){                                        // カウントが10になったら
    for(int i=0; i<NUM_MELODY1; i++){                   // 音符の配列を順番に出力
      tone(BUZZER_PIN, melody1[i][0], DURATION/melody1[i][1]);
      delay(DURATION/melody1[i][1]);                    // 音の長さだけ待機
    }
    count=0;
  }
}

