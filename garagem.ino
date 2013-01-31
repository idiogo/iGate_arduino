// Initialize an empty string and the nameEntered variable
String msg = "";
boolean fim = false;
int led = 13;
int out = 11;
 
void setup() {
  // Start a serial connection @ 9.6kbps
  Serial.begin(9600);  
  pinMode(led, OUTPUT);
  pinMode(out, OUTPUT);
}
 
void loop() {
    while (Serial.available()) {
      char readChar = (char)Serial.read(); 
   
      // If the next character is a linefeed (enter)
      // the name is complete. Exit the while() loop.
      if (readChar == '\n') {
        fim = true;
        continue;
      }
      // If the character wasn't enter, add it to the name string.
      msg += readChar;
    }
    
    if(fim){
      if(msg == "on"){
        digitalWrite(led, HIGH);
        digitalWrite(out, HIGH);
      }else if(msg == "off"){
        digitalWrite(led, LOW);
        digitalWrite(out, LOW);
      }
      
      msg = "";
      fim = false;
    }
}
