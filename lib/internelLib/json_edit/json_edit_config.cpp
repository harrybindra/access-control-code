#include "json_edit_config.h"
#include <SPIFFS.h>
#include "FS.h"
#include <LittleFS.h>
#include <ArduinoJson.h>
#include <Arduino.h>

#include <iostream>
String path = "/config.json";

String LSreadFile(String path)
{
  LittleFS.begin(false);
  Serial.printf("Reading file: %s\n", path);
  File file = LittleFS.open(path.c_str(), "r");
  if (!file)
  {
    Serial.println("Failed to open file for reading");
    return "nop";
  }

  Serial.print("Read from file: ");

  String data = file.readString();

  file.close();
  return data;
}
void LSwriteFile(String path, String message)
{
  Serial.printf("Writing file: %s\n", path);
  LittleFS.begin(false, "/");
  File file = SPIFFS.open(path.c_str(), "w");
  if (!file)
  {
    Serial.println("Failed to open file for writing");
    return;
  }
  if (file.print(message))
  {
    Serial.println("File written");
  }
  else
  {
    Serial.println("Write failed");
  } // Make sure the CREATE and LASTWRITE times are different
  file.close();
}

void json_edit_w(String data, int message, String w_path = path);
void json_edit_w(String data, String message, String w_path = path);
void json_edit_w(String data, bool message, String w_path = path);
void json_edit_w(String data, char json_key, String w_path = path)
{
  String ans = LSreadFile(path);
  JsonDocument doc;
  deserializeJson(doc, ans);
  doc[json_key] = data;
  serializeJson(doc, ans);
  LSwriteFile(w_path, ans);
}
String json_edit_r(String json_key, String r_path = path)
{
  String ans = LSreadFile(r_path);
  JsonDocument doc;
  deserializeJson(doc, ans);

  return doc[json_key];
}
String json_edit_config::GetTelToken()
{
  return json_edit_r("teltoken");
  //  String ans = LSreadFile(path);
  //    JsonDocument doc;
  //   deserializeJson(doc,ans);

  //     String data = doc["teltoken"];
  //     return data;
}

void json_edit_config::SetTelToken(String data)
{
  json_edit_w(data, "teltoken");
  String ans = LSreadFile(path);
  JsonDocument doc;
  deserializeJson(doc, ans);
  doc["teltoken"] = data;
  serializeJson(doc, ans);
  LSwriteFile(path, ans);
}

String json_edit_config::GetChatId()
{
  return json_edit_r("chatid");
}
void json_edit_config::SetChatId(String data)
{
  String ans = LSreadFile(path);
  JsonDocument doc;
  deserializeJson(doc, ans);
  doc["chatid"] = data;
  serializeJson(doc, ans);
  LSwriteFile(path, ans);
}

String json_edit_config::GetLastUpdateId()
{

  return json_edit_r("lastupdate_id");
}
void json_edit_config::SetLastUpdateId(String data)
{
  String ans = LSreadFile(path);
  JsonDocument doc;
  deserializeJson(doc, ans);
  doc["lastupdate_id"] = data;
  serializeJson(doc, ans);
  LSwriteFile(path, ans);
}

bool json_edit_config::GetIsNegtiveTimeOffset()
{
  String ans = LSreadFile(path);
  JsonDocument doc;
  deserializeJson(doc, ans);
  bool data = doc["isnegtivetimeoffset"];
  return data;
}
void json_edit_config::SetIsNegtiveTimeOffset(bool data)
{

  String ans = LSreadFile(path);
  JsonDocument doc;
  deserializeJson(doc, ans);
  doc["isnegtivetimeoffset"] = data;
  serializeJson(doc, ans);
  LSwriteFile(path, ans);
}

int json_edit_config::GetTimeOffset()
{
  String ans = LSreadFile(path);
  JsonDocument doc;
  deserializeJson(doc, ans);
  return int(doc["timeoffset"]);
}
void json_edit_config::SetTimeOffset(int data)
{
  String ans = LSreadFile(path);
  JsonDocument doc;
  deserializeJson(doc, ans);
  doc["timeoffset"] = data;
  serializeJson(doc, ans);
  LSwriteFile(path, ans);
}

bool json_edit_config::GetSetup()
{
  String ans = LSreadFile(path);
  JsonDocument doc;
  deserializeJson(doc, ans);
  return doc["setup"];
}
void json_edit_config::SetSetup(bool data)
{
  String ans = LSreadFile(path);
  JsonDocument doc;
  deserializeJson(doc, ans);
  doc["timeoffset"] = data;
  serializeJson(doc, ans);
  LSwriteFile(path, ans);
}

int json_edit_config::GetPinTrys()
{
  String ans = LSreadFile(path);
  JsonDocument doc;
  deserializeJson(doc, ans);
  return doc["pintrys"];
}
void json_edit_config::SetPinTrys(int data)
{
}

int json_edit_config::GetFingTrys()
{
  String ans = LSreadFile(path);
  JsonDocument doc;
  deserializeJson(doc, ans);
  return doc["fingtrys"];
}
void json_edit_config::SetFingTrys(int data)
{
}

bool json_edit_config::GetOverTrys()
{
  String ans = LSreadFile(path);
  JsonDocument doc;
  deserializeJson(doc, ans);
  return doc["overtrys"];
}
void json_edit_config::SetOverTrys(bool data)
{
}

bool json_edit_config::GetErrorCom()
{
  String ans = LSreadFile(path);
  JsonDocument doc;
  deserializeJson(doc, ans);
  return doc["errorcom"];
}
void json_edit_config::SetErrorCom(bool data)
{
}

String json_edit_config::GetSsid()
{
  String ans = LSreadFile(path);
  JsonDocument doc;
  deserializeJson(doc, ans);
  String data = doc["ssid"];

  return data;
}

void json_edit_config::SetSsid(String data)
{
}

String json_edit_config::GetPass()
{
  String ans = LSreadFile(path);
  JsonDocument doc;
  deserializeJson(doc, ans);
  String data = doc["pass"];

  return data;
}

void json_edit_config::SetPass(String data)
{
}