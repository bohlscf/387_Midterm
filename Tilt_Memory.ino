int pin12 = 12;   //OUTPUT: show tilted to the right
int pin11 = 11;   //OUTPUT: show tilted forward
int pin10 = 10;   //OUTPUT: show tilted backwards
int pin8 = 8;     //OUTPUT: show left to the left

int pin7 = 7;     //INPUT: test tilted to the right
int pin6 = 6;     //INPUT: test tilted forward
int pin5 = 5;     //INPUT: test tilted backwards
int pin4 = 4;     //INPUT: test tilted to the left

int pin2 = 2;     //INPUT: button to start runback

int wait = 0;     //Keeps track of whether a direction has been tilted
int right = 0;    //Counts the number of times tilted right
int left = 0;     //Counts the number of times tilted left
int up = 0;       //Counts the number of times tilted up
int down = 0;     //Counts the number of times tilted down
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

  pinMode(pin2, INPUT);
}
void loop() {
  
  //This sets the LEDs back to low and sets wait = 0 (meaning it is ready to read a new tilt direction)
  if(digitalRead(pin7) && digitalRead(pin6) && digitalRead(pin5)&& digitalRead(pin4)){
    wait = 0;
    digitalWrite(pin12,LOW);
    digitalWrite(pin11,LOW);
    digitalWrite(pin10,LOW);
    digitalWrite(pin8,LOW);
    delay(150);               //This delay prevents extra counting on the tilts
    }
  
  //This detects tilting to the right, only when the wait = 0. It also increases the 'right' counter
  if(digitalRead(pin7) == LOW && digitalRead(pin6) && digitalRead(pin5)&& digitalRead(pin4) && wait == 0){
    right++;
    digitalWrite(pin12,HIGH);
    wait = 1;
    delay(400);
  }

  //This detects tilting up, only when the wait = 0. It also increases the 'up' counter
  if(digitalRead(pin7) && digitalRead(pin6) == LOW && digitalRead(pin5) && digitalRead(pin4) && wait == 0){
    up++;
    digitalWrite(pin11,HIGH);
    wait = 1;
    delay(400);
  }  

  //This detects tilting down, only when the wait = 0. It also increases the 'down' counter
  if(digitalRead(pin7) && digitalRead(pin6)&& digitalRead(pin5) == LOW  && digitalRead(pin4) && wait == 0){
    down++;
    digitalWrite(pin10,HIGH);
    wait = 1;
    delay(400);
  }  

  //This detects tilting to the left, only when the wait = 0. It also increases the 'left' counter
  if(digitalRead(pin7) && digitalRead(pin6) && digitalRead(pin5) && digitalRead(pin4) == LOW  && wait == 0){
    left++;
    digitalWrite(pin8,HIGH);
    wait = 1;
    delay(400);
  }   

   //This enters the if statement when the button is pressed
   if(digitalRead(pin2)){
    //All the LEDs light up for half a second
    digitalWrite(pin12,HIGH);
    digitalWrite(pin11,HIGH);
    digitalWrite(pin10,HIGH);
    digitalWrite(pin8,HIGH);
    delay(500);
    digitalWrite(pin12,LOW);
    digitalWrite(pin11,LOW);
    digitalWrite(pin10,LOW);
    digitalWrite(pin8,LOW);
    delay(300);
    
    //Each LED lights up the specific amount of times, according to the direction counter
    while(right > 0){
      digitalWrite(pin12,HIGH);
      delay(400);
      digitalWrite(pin12,LOW);
      delay(300);
      right--;                  //The counter decreases until it is back to zero
    }
    while(up > 0){
      digitalWrite(pin11,HIGH);
      delay(400);
      digitalWrite(pin11,LOW);
      delay(300);
      up--;                     //The counter decreases until it is back to zero
    }
     while(down > 0){
      digitalWrite(pin10,HIGH);
      delay(400);
      digitalWrite(pin10,LOW);
      delay(300);
      down--;                  //The counter decreases until it is back to zero
    }
     while(left > 0){
      digitalWrite(pin8,HIGH);
      delay(400);
      digitalWrite(pin8,LOW);
      delay(300);
      left--;                  //The counter decreases until it is back to zero
    }
 
    //The LEDs light up in order from right, to up, to down, and then to left
    digitalWrite(pin12,HIGH);
    delay(75);
    digitalWrite(pin11,HIGH);
    delay(75);
    digitalWrite(pin10,HIGH);
    delay(75);
    digitalWrite(pin8,HIGH);
    delay(250);
    digitalWrite(pin12,LOW);
    digitalWrite(pin11,LOW);
    digitalWrite(pin10,LOW);
    digitalWrite(pin8,LOW);
    delay(200);
  }
  
}
