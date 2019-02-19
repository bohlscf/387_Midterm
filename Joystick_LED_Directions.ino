
int pin12 = 12;   //OUTPUT: show movement to the right
int pin11 = 11;   //OUTPUT: show movement upwards
int pin10 = 10;   //OUTPUT: show movement downwards
int pin8 = 8;     //OUTPUT: show movement to the left

int pin7 = 7;     //INPUT: test movement to the right
int pin6 = 6;     //INPUT: test movement upwards
int pin5 = 5;     //INPUT: test movement downwards
int pin4 = 4;     //INPUT: test movement to the left

void setup() {
  // put your setup code here, to run once:
  pinMode(pin12, OUTPUT);
  pinMode(pin11, OUTPUT);
  pinMode(pin10, OUTPUT);
  pinMode(pin8, OUTPUT); 
  
  pinMode(pin7, INPUT);
  pinMode(pin6, INPUT);
  pinMode(pin5, INPUT);
  pinMode(pin4, INPUT);
}

void loop() {
  if(digitalRead(pin7)){      //show right
    digitalWrite(pin12, LOW);
    //delay(100);
  }
  else{
    digitalWrite(pin12, HIGH);
    //delay(100);
  }

  if(digitalRead(pin6)){      //show up
    digitalWrite(pin11, LOW);
    //delay(100);
  }
  else{
    digitalWrite(pin11, HIGH);
    //delay(100);
  }

  if(digitalRead(pin5)){      //show down
    digitalWrite(pin10, LOW);
    //delay(100);
  }
  else{
    digitalWrite(pin10, HIGH);
    //delay(100);
  }

  if(digitalRead(pin4)){      //show left
    digitalWrite(pin8, LOW);
    //delay(100);
  }
  else{
    digitalWrite(pin8, HIGH);
    //delay(100);
  }
  
}
