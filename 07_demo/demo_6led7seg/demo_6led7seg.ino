/*
  Sample Program 6 for 7segment LED and Temperature Sensor.
  For Lecture of "Embedded System"
  in Department of Mechanical Systems Engineering,
  Faculty of Systems Design,
  Tokyo Metropolitan University.
  Nov. 2020. N.Takesue
*/

const int DIG = 2;                                      // 桁数
const int SEG = 8;                                      // 7セグ，DPの数
const int DIG_PIN[DIG] = {10, 11};                      // 桁指定のピン番号
const int SEG_PIN[SEG] = {2, 3, 4, 5, 6, 7, 8, 9};      // 7セグa～g，DPのピン番号
const int TIME_DIG = 2;                                 // 各桁の表示時間を2msに
const int PAT[11] = {                                   // 7セグ表示のON/OFF発光パターン
  0b00111111,/*0*/  0b00000110,/*1*/  0b01011011,/*2*/  0b01001111,/*3*/  0b01100110,/*4*/
  0b01101101,/*5*/  0b01111101,/*6*/  0b00100111,/*7*/  0b01111111,/*8*/  0b01101111,/*9*/
  0b00000000,/*BLANK*/
};
const int TEMP_PIN = A0;
int ain, temp;

void setup()
{
  analogReference(INTERNAL);
  for (int i = 0; i < DIG; i++) {
    pinMode(DIG_PIN[i], OUTPUT);                        // 桁指定のピンを出力モードに設定
  }
  for (int i = 0; i < SEG; i++) {
    pinMode(SEG_PIN[i], OUTPUT);                        // 7セグa～g，DPのピンを出力モードに設定
  }
}

void tempRead()
{
  ain = analogRead(TEMP_PIN);
  temp = map(ain, 0, 1023, 0, 110);
}

void disp_dig(int num, int dp)
{
  for (int i = 0; i < SEG - 1; i++) {
    digitalWrite(SEG_PIN[i], !((PAT[num % 11] >> i) & 0x01)); // 各セグメントを発光パターンで点灯
  }
  digitalWrite(SEG_PIN[SEG - 1], !dp);                  // DPをON/OFF
}

void loop()
{
  tempRead();
  for (int i = 0; i < DIG; i++) {
    disp_dig(temp % 10, (i == 0));                      // 表示桁の数字を指定
    digitalWrite(DIG_PIN[i], !HIGH);                    // 指定桁を表示
    delay(TIME_DIG);                                    // TIME_DIG ms待機
    digitalWrite(DIG_PIN[i], !LOW);                     // 表示を消して，次の桁へ
    temp = (temp - temp % 10) / 10;                     // 表示した数値分を引いて，一桁減らす
  }
}
