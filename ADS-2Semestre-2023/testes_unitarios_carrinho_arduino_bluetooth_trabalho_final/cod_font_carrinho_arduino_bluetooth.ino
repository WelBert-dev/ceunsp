// Dependencia para dos testes unitários, 
// passo-a-passo no último commit ou indo aqui: 
// https://github.com/mmurdoch/arduinounit
#include <ArduinoUnit.h>


#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#define INCLUDE_TERMINAL_MODULE

#include <Dabble.h>
   
#define INT1 2
#define INT2 3
#define INT3 4
#define INT4 5

int count = 0;
int qtde_execution_all_tests_cases = 1;


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
        case 't': // Execute All Test
          run_all_unit_test();
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


void run_all_unit_test() {
  while (count <= qtde_execution_all_tests_cases){

    Serial.print(F("Teste Número: "+String(count+1)));  
    Serial.print(F("Iniciando bateria de testes..."));  

    Test::run();

    Serial.print(F("Finalizando bateria de testes..."));  
    count++;
  }
  Serial.print(F("Generating Summary..."));  

  count = 0;
}

// Units Tests cases for LEFT FUNCTION (PARA ESQUERDA) HARDWARE LEVEL 
test(ok) {
  // Para FRENTE em cenário de sucesso
  Serial.print(F("- WHEN forward is successful THEN returns OK"));
  forward();
  assertEqual(digitalRead(INT1), HIGH);
  assertEqual(digitalRead(INT2), HIGH);
  assertEqual(digitalRead(INT3), LOW);
  assertEqual(digitalRead(INT4), LOW);
  Serial.print(F("- Finalizou teste SUCCESSFUL no forward..."));
  delay(800); 

  // Para TRÁS em cenário de sucesso
  Serial.print(F("- WHEN backward is successful THEN returns OK"));
  backward();
  assertEqual(digitalRead(INT1), LOW);
  assertEqual(digitalRead(INT2), LOW);
  assertEqual(digitalRead(INT3), HIGH);
  assertEqual(digitalRead(INT4), HIGH);
  Serial.print(F("- Finalizou teste SUCCESSFUL no backward..."));
  delay(800); 

  // Para ESQUERDA em cenário de sucesso
  Serial.print(F("- WHEN left is successful THEN returns OK"));
  left();
  assertEqual(digitalRead(INT1), LOW);
  assertEqual(digitalRead(INT2), HIGH);
  assertEqual(digitalRead(INT3), HIGH);
  assertEqual(digitalRead(INT4), LOW);
  Serial.print(F("- Finalizou teste SUCCESSFUL no left..."));
  delay(800); 

  // Para DIREITA em cenário de sucesso
  Serial.print(F("- WHEN right is successful THEN returns OK"));
  right();
  assertEqual(digitalRead(INT1), HIGH);
  assertEqual(digitalRead(INT2), LOW);
  assertEqual(digitalRead(INT3), LOW);
  assertEqual(digitalRead(INT4), HIGH);
  Serial.print(F("- Finalizou teste SUCCESSFUL no right..."));
  delay(800); 

  stop();
}

test(bad) {
  // Para FRENTE, não pode ser igual a nenhuma outras direções
  Serial.print(F("- WHEN forward is error THEN returns BAD"));
  forward();
  // Não pode ser igual aos setters para trás
  assertNotEqual(digitalRead(INT1), LOW);
  assertNotEqual(digitalRead(INT2), LOW);
  assertNotEqual(digitalRead(INT3), HIGH);
  assertNotEqual(digitalRead(INT4), HIGH);

  // Também Não pode ser igual aos setters para esquerda e direita, mas TESTAR ESSES CASOS estava sobrecarregando o arduino...
  Serial.print(F("- Finalizou teste ERROR no forward...")); 
  delay(800); 

  // =========================================================
  // Para TRÁS, não pode ser igual a nenhuma outras direções
  Serial.print(F("- WHEN backward is error THEN returns BAD"));  
  backward();
  // Não pode ser igual aos setters para frente
  assertNotEqual(digitalRead(INT1), HIGH);
  assertNotEqual(digitalRead(INT2), HIGH);
  assertNotEqual(digitalRead(INT3), LOW);
  assertNotEqual(digitalRead(INT4), LOW);

  // Também Não pode ser igual aos setters para esquerda e direita, mas TESTAR ESSES CASOS estava sobrecarregando o arduino...
  Serial.print(F("- Finalizou teste ERROR no backward..."));
  delay(800); 

  // =========================================================
  // Para ESQUERDA, não pode ser igual a nenhuma outras direções
  Serial.print(F("- WHEN left is error THEN returns BAD")); 
  left();
  // Não pode ser igual aos setters para direita
  assertNotEqual(digitalRead(INT1), HIGH);
  assertNotEqual(digitalRead(INT2), LOW);
  assertNotEqual(digitalRead(INT3), LOW);
  assertNotEqual(digitalRead(INT4), HIGH);

  // Também Não pode ser igual aos setters para frente e trás, mas TESTAR ESSES CASOS estava sobrecarregando o arduino...
  Serial.print(F("- Finalizou teste ERROR no left...")); 
  delay(800);

  // =========================================================
  // Para DIREITA, não pode ser igual a nenhuma outras direções
  Serial.print(F("- WHEN right is error THEN returns BAD")); 
  right();
  // Não pode ser igual aos setters para esquerda
  assertNotEqual(digitalRead(INT1), LOW);
  assertNotEqual(digitalRead(INT2), HIGH);
  assertNotEqual(digitalRead(INT3), HIGH);
  assertNotEqual(digitalRead(INT4), LOW);

  // Também Não pode ser igual aos setters para frente e para trás, mas TESTAR ESSES CASOS estava sobrecarregando o arduino...
  Serial.print(F("- Finalizou teste ERROR no right...")); 
  delay(800);

  stop();
}