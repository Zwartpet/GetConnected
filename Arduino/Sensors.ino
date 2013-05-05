int analogPin1;
int analogPin2;
int analogPin3;
int analogPin4;
int sensorValue1;
int sensorValue2;
int sensorValue3;
int sensorValue4;
int gevoeligheid;

int pressed;

void init_sensors() {
 analogPin1 = 0;
 analogPin2 = 1;
 analogPin3 = 2;
 analogPin4 = 3;
 sensorValue1 = 0;
 sensorValue2 = 0;
 sensorValue3 = 0;
 sensorValue4 = 0;
 pressed = 0;
 gevoeligheid = 850;
}

int read_sensor(){
  pressed = 0;
  sensorValue1 = analogRead(analogPin1);
  sensorValue2 = analogRead(analogPin2);
  sensorValue3 = analogRead(analogPin3);
  sensorValue4 = analogRead(analogPin4);
  if(sensorValue1 > gevoeligheid){
   pressed = 1;
  }
  if(sensorValue2 > gevoeligheid){
   pressed = 2; 
  }
  if(sensorValue3 > gevoeligheid){
   pressed = 3; 
  }
  if(sensorValue4 > gevoeligheid){
   pressed = 4; 
  }
  return pressed;
}
