#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>

// RX, TX
SoftwareSerial mySerial(10, 11); 

LiquidCrystal_I2C lcd(0x27, 16, 2);

int packetCount = 0;
int val = 0;   // store last received value
int analogPin = A0;

void setup() {
  Serial.begin(9600);   // For Serial Plotter
  mySerial.begin(9600);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("System Online");
  delay(2000);
  lcd.clear();
}

void loop() {

  // 📡 RECEIVE DATA (only updates val)
  if (mySerial.available()) {

    if (mySerial.read() == 0xFF) {

      while (mySerial.available() < 2);

      byte high = mySerial.read();
      byte low = mySerial.read();

      val = (high << 8) | low;
      analogWrite(9, val / 4); 

      packetCount++;

      // LCD update
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("D:");
      lcd.print(val);
      lcd.print(" P:");
      lcd.print(packetCount);

      lcd.setCursor(0, 1);
      lcd.print("V:");
      lcd.print((val * 5.0) / 1023.0);
      lcd.print("V");
    }
  }

  // 🔥 ALWAYS read reconstructed signal
  int reconstructed = analogRead(analogPin);

  // 📊 ALWAYS print for Serial Plotter
  Serial.print(val);
  Serial.print(" ");
  Serial.println(reconstructed);

  delay(50); // smooth graph
}