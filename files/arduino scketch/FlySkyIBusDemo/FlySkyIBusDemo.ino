//правое переднее   f11    r10
//правое заднее   f12    r9
//левое переднее   f4    r7
//левое заднее   f6    r5
#define rff 11
#define rfr 10
#define rrf 12
#define rrr 9
#define lff 7
#define lfr 4
#define lrf 6
#define lrr 5
#include "FlySkyIBus.h"
int x = 0;
int y = 0;
int b = 0;
int c = 0;
int r = 0;
int l = 0;
void setup()
{
  Serial.begin(9600);
  IBus.begin(Serial3);
  for (int i = 2; i < 14; i++) {
    pinMode(i, OUTPUT);
    digitalWrite(i, 0);
  }
  pinMode(22,OUTPUT);
  pinMode(24,OUTPUT);
  pinMode(26,OUTPUT);
  pinMode(28,OUTPUT);
  digitalWrite(22,0);
  digitalWrite(24,0);
  digitalWrite(26,0);
  digitalWrite(28,0);
  delay(2000);
}

void loop()
{
  IBus.loop();
  x = IBus.readChannel(0);
  y = IBus.readChannel(1);
  b = IBus.readChannel(6);
  c = IBus.readChannel(7);
  x = map(x, 1000, 2000, -255, 255);
  y = map(y, 1000, 2000, -255, 255);
  b = map(b, 1000, 2000, -255, 255);
  c = map(c, 1000, 2000, -255, 255);
  if ((x < 50) && (x > -50)) {
    x = 0;
  }
  if (x > 150) {
    x = 255;
  }
  if (x < -150) {
    x = -255;
  }


  if ((y < 50) && (y > -50)) {
    y = 0;
  }
  if (y > 150) {
    y = 255;
  }
  if (y < -150) {
    y = -255;
  }

  if ((b < 50) && (b > -50)) {
    b = 0;
  }
  if (b > 150) {
    b = 255;
  }
  if (b < -150) {
    b = -255;
  }


  if ((c < 50) && (c > -50)) {
    c = 0;
  }
  if (c > 150) {
    c = 255;
  }
  if (c < -150) {
    c = -255;
  }
  l = x + y;
  r = y - x;


  if ((r < 50) && (r > -50)) {
    r = 0;
  }
  if (r > 150) {
    r = 255;
  }
  if (r < -150) {
    r = -255;
  }
  if ((l < 50) && (l > -50)) {
    l = 0;
  }
  if (l > 150) {
    l = 255;
  }
  if (l < -150) {
    l = -255;
  }
  if(l>0){
    digitalWrite(lfr,0);
    digitalWrite(lrr,0);
    analogWrite(lff,l);
    analogWrite(lrf,l);
  } else{
    digitalWrite(lff,0);
    digitalWrite(lrf,0);
    analogWrite(lfr,-l);
    analogWrite(lrr,-l);
  }
  if(l==0){
    digitalWrite(lff,0);
    digitalWrite(lrf,0);
    digitalWrite(lfr,0);
    digitalWrite(lrr,0);
  }

    if(r>0){
    digitalWrite(rfr,0);
    digitalWrite(rrr,0);
    analogWrite(rff,r);
    analogWrite(rrf,r);
  } else{
    digitalWrite(rff,0);
    digitalWrite(rrf,0);
    analogWrite(rfr,-r);
    analogWrite(rrr,-r);
  }
  if(r==0){
    digitalWrite(rff,0);
    digitalWrite(rrf,0);
    digitalWrite(rfr,0);
    digitalWrite(rrr,0);
  }

  if(b>0){
    digitalWrite(22,0);
    digitalWrite(24,1);
  }else{
    digitalWrite(24,0);
    digitalWrite(22,1);
  }
  if(b==0){
    digitalWrite(24,0);
    digitalWrite(22,0);
  }
  
  if(c>0){
    digitalWrite(26,0);
    digitalWrite(28,1);
  }else{
    digitalWrite(28,0);
    digitalWrite(26,1);
  }
  if(c==0){
    digitalWrite(28,0);
    digitalWrite(26,0);
  }

  
  Serial.print("  x=");
  Serial.print(x);
  Serial.print("  y=");
  Serial.print(y);
  Serial.print("  b=");
  Serial.print(b);
  Serial.print("  c=");
  Serial.print(c);
  Serial.println();
  delay(300);

}
