#define RM1 3
#define RM2 5
#define LM1 6
#define LM2 9
void setup() 
{
  pinMode(RM1,OUTPUT);
  pinMode(RM1,OUTPUT);  
  pinMode(LM1,OUTPUT);
  pinMode(LM2,OUTPUT);
  
  pinMode(13,OUTPUT);
  
  pinMode(4,INPUT);
  pinMode(7,INPUT);
  pinMode(8,INPUT);
  pinMode(12,INPUT); 
  pinMode(11,INPUT);
  pinMode(10,INPUT);
  Serial.begin(9600);
}
void loop()
{
  int s1=digitalRead(4);  
  Serial.print(s1="s1");
  int s2=digitalRead(7);
  Serial.print(s2="s2");
  int s3=digitalRead(8);
  Serial.print(s3="s3");
  int s4=digitalRead(12);
  Serial.print(s4="s4");
  int s5=digitalRead(11);
  Serial.print(s5="s5");
  int s6=digitalRead(10);
  Serial.print(s6="s6");
  if(s1==0 && s2==0&& s3==0 && s4==1 && s5==1 && s6==1)
forward();
  else if(s1==0 && s2==0 && s3==1 && s4==1 && s5==0 && s6==0)
forward();
  else if(s1==0 && s2==0 && s2==1 && s4==1 && s5==1 && s6==1)
turn_right();
  else if(s1==1 && s2==1 && s3==1 && s4==1 && s5==0 && s6==0)
turn_left();
  else if(s1==1 && s2==0 && s3==0 && s4==0 && s5==1 && s6==1)
turn_slightright();
  else if(s1==1 && s2==0 && s3==0 && s4==1 && s5==1 && s6==0)
turn_slightright();
  else if(s1==0 && s2==0 && s3==1 && s4==1 && s5==1 && s6==1)
slightleft();
  else if(s1==0 && s2==1 && s3==1 && s4==0 && s5==0 && s6==1);
slightleft();
  if(s1==1 && s2==1 && s3==1 && s4==1 && s5==1 && s6==1)
stop();
}
void forward()
{
  analogWrite(RM1,0);
  analogWrite(RM2,75);
  analogWrite(LM1,0);
  analogWrite(LM2,75);
}
void turn_right()
{  
  analogWrite(RM1,0);
  analogWrite(RM2,0);
  analogWrite(LM1,75);
  analogWrite(LM2,0);
}
void turn_left()
{
  analogWrite(RM1,75);
  analogWrite(RM2,0);
  analogWrite(LM1,0);
  analogWrite(LM2,0);
} 
void turn_slightright()
{
  analogWrite(RM1,0);
  analogWrite(RM2,25);
  analogWrite(LM1,50);
  analogWrite(LM2,100);
}
void slightleft()
{
  analogWrite(RM1,50);
  analogWrite(RM2,100);
  analogWrite(LM1,0);
  analogWrite(LM2,25);
}
void stop()
{
  analogWrite(RM1,0);
  analogWrite(RM2,0);
  analogWrite(LM1,0);
  analogWrite(LM2,0);
  }
