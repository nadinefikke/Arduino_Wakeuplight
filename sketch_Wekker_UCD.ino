#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int switchState = 0;

int randomNr;

void setup() {
  // put your setup code here, to run once:
lcd.begin(16,2);
pinMode(13, INPUT);
tone(8, 600, 6000);
delay (100);
tone(8, 700, 6000);
delay(100);
tone(8, 600);
randomSeed(analogRead(A0));
randomNr = random(1,17);
} 

void loop() {
  switchState = digitalRead(13);
  if(switchState == HIGH){
    randomNr = randomNr - 1;
    }
  displayEggs();
  
  delay(100);
  if (randomNr == -1) {
    noTone(8);
  }
  if(randomNr <= -2) {
    tone(8, 600);
    if(switchState == HIGH){
      noTone(8);
  }
}
 }

void displayEggs(){
    
  String Eggs;
  for(int i= 0; i<= randomNr; i++){
    Eggs = Eggs+"o";
 
  }
  lcd.clear();
  lcd.print(Eggs);
}
