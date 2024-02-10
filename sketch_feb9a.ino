#define B 21
#define button 34 

hw_timer_t *My_timer = NULL;
int note[] = {319,379,477,436};
int s = 500;
int c;
int x = 5;
int mode =5;

void IRAM_ATTR onTimer()
{
  // Toggle The LED
  digitalWrite(B, !digitalRead(B));
  
}
void IRAM_ATTR MODE()
{

  mode = mode-1;
  if(mode == 0){
    mode = 5;
  }
  s = 100*mode;
  x = mode;

}
void setup() {

  pinMode(B,OUTPUT);
  My_timer = timerBegin(0, 80, true);  // use tiemr 0 and set prescale to 80 so 1 tick is 1 uSec
  timerAttachInterrupt(My_timer, &onTimer, true); // point to the ISR
    // set alarm every 1 sec
  timerAlarmEnable(My_timer);
  attachInterrupt(button, MODE, FALLING);
}
void G (){
  c = note[0]*x;
  timerAlarmWrite(My_timer, note[0], true);
  timerAlarmEnable(My_timer);
  delay(c);
  timerAlarmDisable(My_timer);

}

void E(){
  c = note[1]*x;
  timerAlarmWrite(My_timer, note[1], true);
  timerAlarmEnable(My_timer);
  delay(c);
  timerAlarmDisable(My_timer);

}
void C(){
  c = note[2]*x;
  timerAlarmWrite(My_timer, note[2], true);
  timerAlarmEnable(My_timer);
  delay(c);
  timerAlarmDisable(My_timer);

}
void D(){
  c = note[3]*x;
  timerAlarmWrite(My_timer, note[3], true);
  timerAlarmEnable(My_timer);
  delay(c);
  timerAlarmDisable(My_timer);

}





void loop() {
  
  E();
  delay(s);
  D();
  delay(s);
  C();
  delay(s);
  D();
  delay(s);
  for(int i=0;i<3;i++){
  E();
  delay(s);
  if(i==2)delay(s);
  }
 for(int i=0;i<3;i++){
  D();
  delay(s);
  if(i==2)delay(s);
  }
  E();
  delay(s);
  for(int i=0;i<2;i++){
  G();
  delay(s);
  }
  E();
  delay(s);
  D();
  delay(s);
  C();
  delay(s);
  D();
  delay(s);
  for(int i=0;i<3;i++){
  E();
  delay(s);
  }
  for(int i=0;i<2;i++){
  D();
  delay(s);
  }
  E();
  delay(2*s);
  D();
  delay(s);
  C();
  delay(3*s);
  
}
