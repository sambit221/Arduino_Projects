#include <Servo.h>    //servo library
Servo servo;     
int trigPin = 5;    //trig and echo pins connected to pwm pins
int echoPin = 6;   
int servoPin = 7;    //servo moter is connected at pin 7
long duration, dist;    // taken duration and distance as long data type


void setup() {       
    Serial.begin(9600);
    servo.attach(7);       //servo moter is connected at pin 7
    pinMode(trigPin, OUTPUT);  
    pinMode(echoPin, INPUT); 
    servo.write(0);         //close cap on power on  
   
} 

void loop() {  
digitalWrite(trigPin, LOW);
delayMicroseconds(10);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);   // it will store the data from the sensor 
dist = (duration/2) / 29.1;    //to obtain distance as speed of sound is 343m/s that is (in cm/microseconds) equal to 0.0343 or  1/29.1

 if ( dist<10 ) {            // it will sense object within 10 cm
 Serial.println("the distance is less than 10");   
 servo.write(90);            // the shaft of the motor will rotate by 90 degree when the above condition is satisfied so that it will create a pull force over the hand wash
 delay(1000);
 }     
else{
  servo.write(0);            // for all rest conditions the shaft will remain at rest position that is 0 degree
}
     
Serial.print(dist);     //it will print distance between sensor and object
}





/*

-----------Bibiliography-----------------

http://arduinodev.com/software/builder/

https://randomnerdtutorials.com/complete-guide-for-ultrasonic-sensor-hc-sr04/

https://www.techexult.com/

https://www.google.com/search?q=range+of+hc+sr04&oq=range+of+hc&aqs=chrome.2.69i57j0l3.7199j0j9&client=ms-android-xiaomi-rev1&sourceid=chrome-mobile&ie=UTF-8

https://howtomechatronics.com/tutorials/arduino/ultrasonic-sensor-hc-sr04/

https://youtu.be/ZySGP4AwGCY

https://youtu.be/Kjsknmfkgo0

https://youtu.be/TSqPHzt_w38

*/
