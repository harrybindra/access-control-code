#include <Arduino.h>
#include <lebs.h> 
void setup() {
  Serial.begin(9600, SERIAL_8N1);
 

}

void loop() {
    Serial.println(GetTelToken());
}
