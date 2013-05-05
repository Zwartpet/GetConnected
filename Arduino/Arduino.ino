  long randNum = 0; //random nummer voor het dier
  long randNumPrev = 0; //welk dier was de vorige
  int guessed = 1; // 1 = geraden, 0 = nog niet geraden
  int wrong = 0; //hoeveel x fout
  int sensor = 0; //de knop die is ingedrukt, 1 2 3 of 4

void setup(){
  Serial.begin(9600); //begint de communicatie met de com poort
  randomSeed(analogRead(4)); //maak random echt random
  init_mp3(); //mp3 setup
  init_leds(); //leds setup
  init_sensors(); //sensoren setup
  init_switch(); //switch setup
  
  sendData(0x00, 0x00); //binair 00000000, 00000000
  //aansturen van de pinexpander
}

void loop(){
  if(read_switch() == 1){ //switch aan = game mode
    //Serial.print("5");
    if(guessed == 1){ //geraden? nieuw dier
    randNumPrev = randNum; //zet het vorige dier
    randNum = random(1, 5); //en dan het nieuwe dier
    while(randNum == randNumPrev){
      randNum = random(1, 5);
    }
    Serial.print(randNum); //stuurt het dier naar de com poort
    flash(randNum); //de juiste led aan
    geluid(randNum); //het juiste geluid 
    guessed = 0; //nog niet geraden, dus 0
    
    }else{ //nieuw dier moet geraden worden
      sensor = read_sensor(); //wordt er een knop ingedrukt?
      if(sensor == randNum){
        guessed = 1; //geraden
        wrong = 0;
      }else if(sensor != randNum && sensor > 0){
        wrong += 1;
        if(wrong == 2){ // na 2 fouten een hint
          Serial.print(randNum);
          flash(randNum);
        }else if(wrong == 4){ // na 4 fouten nog een hint
          wrong = 0;
          Serial.print(randNum);
          flash(randNum);
          geluid(randNum);
        }
        delay(100);
      }
    }
    
    
  }else{ //de switch niet aan dus free mode aan
    //Serial.print("6");
    sensor = read_sensor();
    if(sensor > 0){
      Serial.print(sensor);
      flash(sensor);
      geluid(sensor);
    }
  }
  delay(100);
}
