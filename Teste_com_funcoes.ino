#include <Ultrasonic.h>
/*VARIAVEIS GLOBAIS*/
int sensor3  = 3;/*Sensor de presenca*/
int sensor4  = 4;/*Sensor indutivo*/
int RPM  = 5; /*Velocidade do motor*/
int sensor6  = 6;/*Vazio*/
int sensor7  = 7;/*Vazio*/
int sensor10  = 10;/*Vazio*/
int sensor11  = 11;/*Vazio*/
int IN1  = 12;
int IN2  = 13;
int RCP = 8;
int EMS = 9;
int POTENCIA = 120;
/*
  L298N    Arduino    Code
  IN1-------7-------pinD7
  IN2-------6-------pinD6
  IN1 IN2
  1   0    Motor A no sentido anti-horário
  0   1    Motor A sentido horário
  1   1    stop
*/

Ultrasonic ultrasonic(9, 8);
/*Configuracoes*/
void setup() {
}
/*Loop Principal*/
void loop() {
  detecta();
}


/*Detecta objetos de metais*/
void detecta() {
  while (ultrasonic.Ranging(CM) < 10) {
    Serial.println("Obstrucao da escotilha");
  }
  delay(3000);
  if (sensor3 ==  HIGH) { /*Verifica se há algum objeto na escotilha*/
    if (sensor4 == HIGH) { /*Verifica se o objeto é de metal*/
      aproveita();
    }
    else {
      descarte();
    }
  }
  else {
    detecta();
  }
}



/*aproveita objetos de metais*/
void aproveita() {
  delay(3000);
  while (sensor3 == HIGH) {
    analogWrite (RPM, POTENCIA); //ajusta o saida do Pino 9 para o novo PWM;
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
  }
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);
  delay(3000);
  detecta();
}



/*Descarta objetos de metais*/
void descarte() {
  delay(3000);
  while (sensor3 == HIGH) {
    analogWrite (RPM, POTENCIA); //ajusta o saida do Pino 9 para o novo PWM;
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
  }
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);
  delay(3000);
  detecta();
}

