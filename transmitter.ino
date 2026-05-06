#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11);

int potPin = A0;
int lastVal = 0;
int threshold = 50;

// 👉 CHANGE THIS ONLY
bool graphMode =false;   // true = Plotter, false = Monitor

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop() {
  int currentVal = analogRead(potPin);
  int outputVal = 0;

  if (abs(currentVal - lastVal) > threshold) {
    // Send packet
    mySerial.write(0xFF);
    mySerial.write(highByte(currentVal));
    mySerial.write(lowByte(currentVal));

    outputVal = currentVal;
    lastVal = currentVal;

    // 👉 Serial Monitor output
    if (!graphMode) {
      Serial.print("Packet Sent -> Value: ");
      Serial.println(currentVal);
    }
  } 
  else {
    outputVal = 0;

    // 👉 Serial Monitor output
    if (!graphMode) {
      Serial.print("Packet Skipped -> Value: ");
      Serial.println(currentVal);
    }
  }

  // 👉 Serial Plotter output (ONLY graph data)
  if (graphMode) {
  
  Serial.print("Input:");
  Serial.print(currentVal);
  Serial.print(" ");

  Serial.print("Threshold:");
  Serial.print(threshold);
  Serial.print(" ");

  Serial.print("Output:");
  Serial.println(outputVal);

  delay(100);  // Smooth graph
  }
  }