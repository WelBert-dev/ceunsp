#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#define INCLUDE_TERMINAL_MODULE

#include <Dabble.h>
   
#define INT1 2
#define INT2 3
#define INT3 4
#define INT4 5


String Serialdata = "";
bool dataflag = 0;
   
void setup()
{
  Serial.begin(250000);
  Dabble.begin(9600,7,6); 
  
  pinMode(INT1,OUTPUT);
  pinMode(INT2,OUTPUT);
  pinMode(INT3,OUTPUT);                                                                    
  pinMode(INT4,OUTPUT);
  stop();

}
   
   
void loop() {
  Dabble.processInput();  

  while (Serial.available() != 0) {
    Serialdata = String(Serialdata + char(Serial.read()));
    dataflag = 1;
  }

  if (dataflag == 1){
    Terminal.print(Serialdata);
    Serialdata = "";
    dataflag = 0;
  } 

  if(Terminal.available()){
    while (Terminal.available() != 0)
    {
      char command = (char) Terminal.read(); 

      switch ((char) command) {
        case 'f': // FRENTE
          forward();
          break;
        case 't': // TRÁS
          backward();
          break;
        case 'e': // ESQUERDA
          left();
          break;
        case 'd': // DIREITA
          right();
          break;
        default:
          stop();
      }
    }
  }       
     
  if(GamePad.isUpPressed())
  {
    forward();
  }
  else if(GamePad.isDownPressed())
  {
    backward();
  }
  else if(GamePad.isLeftPressed())
  {
    left();
  }
  else if(GamePad.isRightPressed())
  {
    right();  
  }
  else
  {  
   stop(); 
  }
}

void forward() {
  digitalWrite(INT1,HIGH);
  digitalWrite(INT2,HIGH);
  digitalWrite(INT3,LOW);
  digitalWrite(INT4,LOW); 
}

void backward() {
  digitalWrite(INT1,LOW);
  digitalWrite(INT2,LOW);
  digitalWrite(INT3,HIGH);
  digitalWrite(INT4,HIGH);
}

void left() {
  digitalWrite(INT1,LOW);
  digitalWrite(INT2,HIGH);
  digitalWrite(INT3,HIGH);
  digitalWrite(INT4,LOW);  
}

void right() {
  digitalWrite(INT1,HIGH);
  digitalWrite(INT2,LOW);
  digitalWrite(INT3,LOW);
  digitalWrite(INT4,HIGH);
}

void stop() {
  digitalWrite(INT1,LOW);
  digitalWrite(INT2,LOW);
  digitalWrite(INT3,LOW);
  digitalWrite(INT4,LOW);  
}