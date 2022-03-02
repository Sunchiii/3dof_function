#include <Servo.h>
#define delays 10

Servo Q1;
Servo Q2;
Servo Q3;
float q1,q2,q3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Q1.attach(9);
  Q2.attach(10);
  Q3.attach(11);


  
   ToPosition(100,0,0);x,y,z
   
}

void loop() {
  // put your main code here, to run repeatedly:
}

void ToPosition(float x,float y,float z){
     float l1=105,l2=145,h=97;
     float gm1=1,gm2=-1;
     float r=gm1*sqrt(pow(x,2)+pow(y,2)),zh=z-h;
     if((l1-l2<=sqrt(pow(r,2)+pow(zh,2))) && (l1+l2>=sqrt(pow(r,2)+pow(zh,2)))){
         float c2 = (pow(r,2)+pow(zh,2)-pow(l1,2)-pow(l2,2))/(2*l1*l2);
         float s2 = gm2*sqrt(1-pow(c2,2));
         q1 = degrees(atan2(y/gm1,x/gm1));
         q2 = degrees(atan2(r,zh)-atan2(l2*s2,l1+l2*c2));
         q3 = degrees(atan2(s2,c2));

         Serial.println(q1+90);
         Serial.println(q2+30);
         Serial.println(q3+180);
      }
      else{
         Serial.println("not");
        }
  }

void smooth(float n1,float n2,float n3){
  float old1=Q1.read(),old2=Q2.read(),old3=Q3.read();
  float bet1=(n1-old1)/100,bet2=(n2-old2)/100,bet3=(n3-old3)/100;
  for(int i=0;i<100;i++){
       Q1.write(old1+=bet1);
       Q2.write(old2+=bet2);
       Q3.write(old3+=bet3);
       delay(delays);
    }
  }
