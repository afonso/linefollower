#include <Servo.h>
#include <NewPing.h>

#define PING_PIN  7
#define MAX_DISTANCE 50
NewPing sonar(PING_PIN, PING_PIN, MAX_DISTANCE);

Servo servo_0;
Servo servo_1;

int st = 0;
int dinimigo = 0;
int led = 13;
int modo_pin = 5;
int modo_func = 0;

void setup() {
  servo_0.attach(9);
  servo_1.attach(10);
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(modo_pin, INPUT);
  modo_func = digitalRead(modo_pin);
  if(modo_func == 1){
    digitalWrite(led, HIGH);
  }else{
    digitalWrite(led, LOW);
  }
}

void loop() {
  if(modo_func == 1){
    //modo sumo
    unsigned int uS = sonar.ping_median();
    dinimigo = (uS / US_ROUNDTRIP_CM);
    Serial.println(dinimigo);
    int seg1 = analogRead(A0); // 400
    int seg2 = analogRead(A1); // 400
    int seg3 = analogRead(A2); // 400
    if(seg1 > 400 || seg2 > 400 || seg3 > 400){ //fundo preto borda branca
      atras();
    }else{
      if(dinimigo == 0){
        esquerda_suave_sumo();
      }else{
        frente_sumo();
      }
    }
  }
  if(modo_func == 0){
    //modo seguidor de linha
    int seg1 = analogRead(A0); // 400
    int seg2 = analogRead(A1); // 400
    int seg3 = analogRead(A2); // 400
    /*
    Serial.print(seg1);
    Serial.print(":");
    Serial.print(seg2);
    Serial.print(":");
    Serial.println(seg3);
    */
    /*
    if(seg2 > 400 || (seg1 > 400 && seg3 > 400)) {
      frente();
    }else if(seg1 > 400 && seg2 > 400){
      esquerda_suave();
    }else if(seg2 > 400 && seg3 > 400){
      direita_suave();
    }else{
     if(seg1 > 400) {
       direita();
     }else if(seg3 > 400) {
       esquerda();
     }else{
      esquerda_suave_sumo();
     } 
    */
    if(seg3 > 400 && seg2 < 400 && seg1 < 400){
        direita();
        //Serial.println("direita");
      }else
      if(seg1 > 400 && seg2 < 400 && seg3 < 400){
        esquerda();
        //Serial.println("esquerda");
      }else{
    if(seg1 > 400 && seg3 > 400){
      frente();
      st = 1;
      //Serial.println("frente");
    }else{
      if(seg1 > 400 && seg2 > 400){
        esquerda();
        st = 1;
        //Serial.println("esquerda suave");
      }else
      if(seg3 > 400 && seg2 > 400){
        direita();
        //Serial.println("direita suave");
      }else
      if(seg1 > 400 && seg2 < 400 && seg3 < 400){
        esquerda();
        //Serial.println("esquerda");
      }else
      if(seg3 > 400 && seg2 < 400 && seg1 < 400){
        direita();
        //Serial.println("direita");
      }else
      if((seg2 > 400 && seg1 < 400 && seg3 < 400) || (seg2 > 400 && seg1 > 400 && seg3 > 400)){
        frente_slow();
        delay(50);
        st = 1;
        //Serial.println("frente");
      }else
      if(seg2 < 400 && seg1 < 400 && seg3 < 400){
        if (st == 1){
          frente_slow();
          st = 0;
        }else{
          frente();
        }
      }else{
        ultra_slow();
        //Serial.println("frente");
      }
    }
      }
    
  }

  
  delay(10);
}

void frente_sumo() {
  /*
  servo_0.write(130);
  servo_1.write(50);8
  */
  servo_0.write(180);
  servo_1.write(0);
}

void frente() {
  /*
  servo_0.write(130);
  servo_1.write(50);
  */
  servo_0.write(110);
  servo_1.write(68);
}

void frente_slow() {
  servo_0.write(90);
  servo_1.write(78);
}

void direita() {
  servo_0.write(150);
  servo_1.write(150);
}

void esquerda() {
  servo_0.write(30);
  servo_1.write(30);
}

void direita_suave() {
  servo_0.write(130);
  servo_1.write(83);
}

void esquerda_suave() {
  servo_0.write(83);
  servo_1.write(30);
}

void esquerda_suave_sumo() {
  servo_0.write(78);
  servo_1.write(70);
}

void ultra_slow() {
  servo_0.write(90);
  servo_1.write(90);
}

void atras() {
  servo_0.write(50);
  servo_1.write(120);
}
