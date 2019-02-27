/* This code uses tilt switches to light up four different
   LEDs depending on which way it is tilted    */

int pin12 = 12;   //OUTPUT: show tilted to the right
int pin11 = 11;   //OUTPUT: show tilted forward
int pin10 = 10;   //OUTPUT: show tilted backwards
int pin8 = 8;     //OUTPUT: show left to the left

int pin7 = 7;     //INPUT: test tilted to the right
int pin6 = 6;     //INPUT: test tilted forward
int pin5 = 5;     //INPUT: test tilted backwards
int pin4 = 4;     //INPUT: test tilted to the left

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
  if(digitalRead(pin7)){        //if tilt switch that tests right is reading high
    digitalWrite(pin12, LOW);   //not tilted right
  }
  else{
    digitalWrite(pin12, HIGH);  //tilted the right
  }

  if(digitalRead(pin6)){       //if tilt switch that tests forward is reading high
    digitalWrite(pin11, LOW);   //not tilted forward
  }
  else{
    digitalWrite(pin11, HIGH);  //if tilt switch that tests backward is reading high
  }

  if(digitalRead(pin5)){      //show down
    digitalWrite(pin10, LOW); //not tilted backward
  }
  else{
    digitalWrite(pin10, HIGH); //tilted backward
  }

  if(digitalRead(pin4)){       //if tilt switch that tests left is reading high
    digitalWrite(pin8, LOW);   //not tilted left
  }
  else{
    digitalWrite(pin8, HIGH); //tilted left
  }
  
}
