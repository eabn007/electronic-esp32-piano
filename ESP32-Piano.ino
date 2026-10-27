
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


//Led pins
const int ledSi = 2;
const int ledDo1 = 15;
const int ledRe = 16;
const int ledMi = 21;
const int ledFa = 23;
const int ledSol = 5;
const int ledLa = 4;
const int ledDo2 = 17;

//Button pins
const int do1Button = 34;
const int reButton = 27;
const int miButton = 35;
const int faButton = 32;
const int solButton = 33;
const int laButton = 14;
const int siButton = 12;
const int do2Button = 13;

//Oled screen

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

#define I2C_SDA 26
#define I2C_SCL 25

//Buzzer
const int buzzPin = 22;



void setup() {
  // put your setup code here, to run once:

Serial.begin(115200);
Wire.begin(I2C_SDA, I2C_SCL);

if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)){
  Serial.println(F("SSD1306 allocation failed"));
  for(;;);
}

display.clearDisplay();
display.setTextSize(3);
display.setTextColor(SSD1306_WHITE);
display.setCursor(60, 30);
display.println(":)");
display.display();

//Pins setup
pinMode(ledDo1, OUTPUT);
pinMode(ledRe, OUTPUT);
pinMode(ledMi, OUTPUT);
pinMode(ledFa, OUTPUT);
pinMode(ledSol, OUTPUT);
pinMode(ledLa, OUTPUT);
pinMode(ledSi, OUTPUT);
pinMode(ledDo2, OUTPUT);

pinMode(do1Button, INPUT);
pinMode(reButton, INPUT);
pinMode(miButton, INPUT);
pinMode(faButton, INPUT);
pinMode(solButton, INPUT);
pinMode(laButton, INPUT);
pinMode(siButton, INPUT);
pinMode(do2Button, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  int do1State = digitalRead(do1Button);
  int reState = digitalRead(reButton);
  int miState = digitalRead(miButton);
  int faState = digitalRead(faButton);
  int solState = digitalRead(solButton);
  int laState = digitalRead(laButton);
  int siState = digitalRead(siButton);
  int do2State = digitalRead(do2Button);


  if(do1State == HIGH){
    digitalWrite(ledDo1, HIGH);
    tone(buzzPin, 262);
    display.clearDisplay();
    display.setTextSize(3);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(60, 30);
    display.println("DO-");
    display.display();
  } else if (reState == HIGH){
    digitalWrite(ledRe, HIGH);
    tone(buzzPin, 294);
    display.clearDisplay();
    display.setTextSize(3);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(60, 30);
    display.println("RE");
    display.display();
  } else if (miState == HIGH){
    digitalWrite(ledMi, HIGH);
    tone(buzzPin, 330);
    display.clearDisplay();
    display.setTextSize(3);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(60, 30);
    display.println("MI");
    display.display();
  } else if (faState == HIGH){
    digitalWrite(ledFa, HIGH);
    tone(buzzPin, 349);
    display.clearDisplay();
    display.setTextSize(3);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(60, 30);
    display.println("FA");
    display.display();
  } else if (solState == HIGH){
    digitalWrite(ledSol, HIGH);
    tone(buzzPin, 392);
    display.clearDisplay();
    display.setTextSize(3);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(60, 30);
    display.println("SOL");
    display.display();
  } else if (laState == HIGH){
    digitalWrite(ledLa, HIGH);
    tone(buzzPin, 440);
    display.clearDisplay();
    display.setTextSize(3);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(60, 30);
    display.println("LA");
    display.display();
  }else if (siState == HIGH){
    digitalWrite(ledSi, HIGH);
    tone(buzzPin, 494);
    display.clearDisplay();
    display.setTextSize(3);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(60, 30);
    display.println("SI");
    display.display();
  }else if (do2State == HIGH){
    digitalWrite(ledDo2, HIGH);
    tone(buzzPin, 523);
    display.clearDisplay();
    display.setTextSize(3);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(60, 30);
    display.println("DO+");
    display.display();
  } else {
    digitalWrite(ledDo1, LOW);
    digitalWrite(ledRe, LOW);
    digitalWrite(ledMi, LOW);
    digitalWrite(ledFa, LOW);
    digitalWrite(ledSol, LOW);
    digitalWrite(ledLa, LOW);
    digitalWrite(ledSi, LOW);
    digitalWrite(ledDo2, LOW);

    display.clearDisplay();
    display.setTextSize(3);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(45, 15);
    display.println("<--");
    display.display();

    noTone(buzzPin);
  }
  
}
