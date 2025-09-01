#define SENSOR 11 

#include "SoftwareSerial.h"
 

#include "DFRobotDFPlayerMini.h"
 int state = 0;

#define FPSerial Serial

int  SensorValue = digitalRead(SENSOR);
DFRobotDFPlayerMini myDFPlayer;


 
void setup() {
  
  Serial.begin(115200);
  pinMode(SENSOR, INPUT);
 if (!myDFPlayer.begin(FPSerial, /*isACK = */true, /*doReset = */true)) {  //Use serial to communicate with mp3.
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while(true);
  }
  Serial.println(F("DFPlayer Mini online."));
  
  myDFPlayer.setTimeOut(500); //Set serial communictaion time out 500ms
  //void(* reset) (void) = 0; 
  
FPSerial.begin(9600);
myDFPlayer.volume(10);
 myDFPlayer.setTimeOut(500);
 myDFPlayer.outputDevice(DFPLAYER_DEVICE_SD);

  
 delay(2000);
}

void loop() {;

  if((SensorValue) == 1){
       
    if(state == 0){
          
       myDFPlayer.play(2);
      delay(500);
          

        }

          
        }
      

    
   
 
    else{
     if(state == 1){
      
      delay(50);
      state = 0;
      myDFPlayer.pause();
     
     }
    }

  

}
