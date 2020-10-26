/*
  Sample Program 2 of Practice (RGB-LED).
  For Lecture of "Embedded System"
  in Department of Mechanical Systems Engineering,
  Faculty of Systems Design,
  Tokyo Metropolitan University.
  Oct. 2020. N.Takesue
*/

const int TIME_LED=50;            // デューティ比を変える時間[ms]
const float CYCLE_TIME=5000.0;    // 周期[ms]
const int NUM_LED=3;              // LEDの個数
const int LED_PIN[NUM_LED]={11, 9, 3}; // LEDのピン番号(RGB)
const int BRIGHTNESS=255;

void setup(){}

void loop()
{
  for(int i=0; i<NUM_LED; i++){
    analogWrite(LED_PIN[i], 
      BRIGHTNESS*0.5*(1+sin(2.0*PI*((float)millis()/CYCLE_TIME-(float)i/3.0))));
  }
  delay(TIME_LED);                // デューティ比の更新を待機
}

