// Define LED to refer to the RED LED.
#define LED GREEN_LED

String wordRead;
int wordLength;
char letter;
int pAvoid = 0; //used to avoid cases such as " . "

void setup() {
  // Configure the LED pin to be an output.
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

int dot() {
  digitalWrite (LED, HIGH);
  delay(1000);
  digitalWrite (LED, LOW);
  delay(1000);
}

int dash() {
  digitalWrite (LED, HIGH);
  delay(3000);
  digitalWrite (LED, LOW);
  delay(1000);
}

int letterEnd() {
  delay(2000);
}
  
int wordEnd() {
  delay(4000);
}

void loop() {
  if (Serial.available()) {
    wordRead = Serial.readString();
    wordRead.toLowerCase();
    wordLength = wordRead.length();
    
    for (int i = 0; i< wordLength ; i++) {
      letter = wordRead [i];
      //Prevents ill-formed input involving spaces.
      if (letter == ' ') {
        //prevent += 1;
        if (i == 0 || pAvoid == 0) {
          letter = '-';
        } 
      }
      
      pAvoid = 0;
      
      switch(letter) {
        case 'a' : dot(); dash(); letterEnd() /*Serial.print(". -   ")*/; pAvoid = 1; break;
        case 'b' : dash(); dot(); dot(); dot(); letterEnd() /*Serial.print("- . . .   "); */; pAvoid = 1; break;
        case 'c' : dash(); dot(); dash(); dot(); letterEnd()/*Serial.print("- . - .   ")*/; break;
        case 'd' : dash(); dot(); dot(); letterEnd()/*Serial.print("- . .   ")*/; pAvoid = 1; break;
        case 'e' : dot(); letterEnd() /*Serial.print(".   ")*/; pAvoid = 1; break;
        case 'f' : dot(); dot(); dash(); dot(); letterEnd()/*Serial.print(". . - .   ")*/; pAvoid = 1; break;
        case 'g' : dash(); dash(); dot(); letterEnd()/*Serial.print("- - .   ")*/; pAvoid = 1; break;
        case 'h' : dot(); dot(); dot(); dot(); letterEnd() /*Serial.print(". . . .   ")*/; pAvoid = 1; break;
        case 'i' : dot(); dot(); letterEnd()/*Serial.print(". .   ")*/; pAvoid = 1; break;
        case 'j' : dot(); dash(); dash(); dash(); letterEnd() /*Serial.print(". - - -   ")*/; pAvoid = 1; break;
        case 'k' : dash(); dot(); dash(); letterEnd() /*Serial.print("- . -   ")*/; pAvoid = 1; break;
        case 'l' : dot(); dash(); dot(); dot(); letterEnd() /*Serial.print(". - . .   ")*/; pAvoid = 1; break;
        case 'm' : dash(); dash(); letterEnd()/*Serial.print("- -   ")*/; pAvoid = 1; break;
        case 'n' : dash(); dot(); letterEnd()/*Serial.print("- .   ")*/; pAvoid = 1; break;
        case 'o' : dash(); dash(); dash(); letterEnd() /*Serial.print("- - -   ")*/; pAvoid = 1; break;
        case 'p' : dot(); dash(); dash(); dot(); letterEnd()/*Serial.print(". - - .   ")*/; pAvoid = 1; break;
        case 'q' : dash(); dash(); dot(); dash(); letterEnd()/*Serial.print("- - . -   ")*/; pAvoid = 1; break;
        case 'r' : dot(); dash(); dot(); letterEnd()/*Serial.print(". - .   ")*/; pAvoid = 1; break;
        case 's' : dot(); dot(); dot(); letterEnd()/*Serial.print(". . .   ")*/; pAvoid = 1; break;
        case 't' : dash(); letterEnd()/*Serial.print("-   ")*/; pAvoid = 1; break;
        case 'u' : dot(); dot(); dash(); letterEnd()/*Serial.print(". . -   ")*/; pAvoid = 1; break;
        case 'v' : dot(); dot(); dot(); dash(); letterEnd()/*Serial.print(". . . -   ")*/; pAvoid = 1; break;
        case 'w' : dot(); dash(); dash(); letterEnd()/*Serial.print(". - -   ")*/; pAvoid = 1; break;
        case 'x' : dash(); dot(); dot(); dash(); letterEnd()/*Serial.print("- . . -   ")*/; pAvoid = 1; break;
        case 'y' : dash(); dot(); dash(); dash(); letterEnd()/*Serial.print("- . - -   ")*/; pAvoid = 1; break;
        case 'z' : dash(); dash(); dot(); dot(); letterEnd() /*Serial.print("- - . .   ")*/; pAvoid = 1; break;
        case ' ' : wordEnd() /*Serial.print("    ")*/; pAvoid = 0; break;        
      }
    }     
  }
}



