const int buttonPin = 5;
int buttonState = 0; //high of low, high = aan
int active = 0; //aan of uit, aan = 1

void init_switch(){
  pinMode(buttonPin, INPUT);
}

int read_switch(){
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {     
    active = 1;    
  } 
  else {
    active = 0;
  }
  return active;
}
