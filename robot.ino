// 2,3- right
//4,5 -left

int sensor1 = 11; //left
int sensor2 = 12; //right
int rightmotor1 =2;
int rightmotor2 =3;
int leftmotor1 =4;
int leftmotor2 =5;

void setup() {
pinMode(sensor1,INPUT);
pinMode(sensor2,INPUT);
pinMode(rightmotor1, OUTPUT);
pinMode(rightmotor2, OUTPUT);
pinMode(leftmotor1, OUTPUT);
pinMode(leftmotor2, OUTPUT);


Serial.begin(9600);
digitalWrite(rightmotor1,LOW);
digitalWrite(rightmotor2,LOW);
digitalWrite(leftmotor1,LOW);
digitalWrite(leftmotor2,LOW);
}

void loop() {
  
  
Serial.print("left :");
Serial.print(digitalRead(sensor1));
Serial.print("\n");
Serial.print("right :");
Serial.print(digitalRead(sensor2));
Serial.print("\n");

forward();
while(digitalRead(sensor1) && digitalRead(sensor2));

 if(digitalRead(sensor2)){
  left();
  while(!digitalRead(sensor1));
  
  }else if(digitalRead(sensor1)){
    right();
  while(!digitalRead(sensor2));
    stopit();
    }

}
void forward(void){

digitalWrite(rightmotor1,HIGH);
digitalWrite(rightmotor2,LOW);
digitalWrite(leftmotor1,HIGH);
digitalWrite(leftmotor2,LOW);
}
void backward(void){

digitalWrite(rightmotor1,LOW);
digitalWrite(rightmotor2,HIGH);
digitalWrite(leftmotor1,LOW);
digitalWrite(leftmotor2,HIGH);
}
void right(void){

digitalWrite(rightmotor1,LOW);
digitalWrite(rightmotor2,LOW);
digitalWrite(leftmotor1,HIGH);
digitalWrite(leftmotor2,LOW);
}
void left(void){

digitalWrite(rightmotor1,HIGH);
digitalWrite(rightmotor2,LOW);
digitalWrite(leftmotor1,LOW);
digitalWrite(leftmotor2,LOW);
}
void stopit(void){
digitalWrite(rightmotor1,LOW);
digitalWrite(rightmotor2,LOW);
digitalWrite(leftmotor1, LOW);
digitalWrite(leftmotor2,LOW);
}

