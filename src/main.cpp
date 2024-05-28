#include <Arduino.h>
#include <lebs.h>
json_edit_config configC;
fingerprint sensorfing;
void setup()
{
  Serial.begin(9600, SERIAL_8N1);
}

void loop()
{
  Serial.println(configC.GetTelToken());
}
