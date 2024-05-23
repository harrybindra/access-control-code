#include "json_edit_config.h"
#include <SPIFFS.h>
#include "FS.h"
#include <LittleFS.h>
#include <ArduinoJson.h>
#include <Arduino.h>

#include <iostream>
String path = "/config.json";

 String LSreadFile( String path)
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
void LSwriteFile( String path, String message)
{
    Serial.printf("Writing file: %s\n", path);
LittleFS.begin(false,"/");
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

void json_edit_w( String data, int message, String w_path = path);
void json_edit_w( String data, String message, String w_path = path);
void json_edit_w( String data, bool message, String w_path = path);
void json_edit_w(String data,char json_key, String w_path = path ){
   String ans = LSreadFile(path);
    JsonDocument doc;
     deserializeJson(doc,ans);
    doc[json_key] = data;
    serializeJson(doc,ans);
    LSwriteFile(w_path,ans);
}

String json_edit_r(String json_key, String r_path = path ){
  String ans = LSreadFile(r_path);
     JsonDocument doc;
    deserializeJson(doc,ans);
  
      return doc[json_key];
}

// void   LSlistDir( String *dirname)
// {
//     Serial.printf("Listing directory: %s\n", dirname);

//     FILE root = LittleFS.openDir(dirname);

//     while (root.next())
//     {
//         File file = root.openFile("r");
//         Serial.print("  FILE: ");
//         Serial.print(root.fileName());
//         Serial.print("  SIZE: ");
//         Serial.print(file.size());
//         time_t cr = file.getCreationTime();
//         time_t lw = file.getLastWrite();
//         file.close();
//         struct tm *tmstruct = localtime(&cr);
//         Serial.printf("    CREATION: %d-%02d-%02d %02d:%02d:%02d\n", (tmstruct->tm_year) + 1900, (tmstruct->tm_mon) + 1, tmstruct->tm_mday, tmstruct->tm_hour, tmstruct->tm_min, tmstruct->tm_sec);
//         tmstruct = localtime(&lw);
//         Serial.printf("  LAST WRITE: %d-%02d-%02d %02d:%02d:%02d\n", (tmstruct->tm_year) + 1900, (tmstruct->tm_mon) + 1, tmstruct->tm_mday, tmstruct->tm_hour, tmstruct->tm_min, tmstruct->tm_sec);
//     }
// }

String GetTelToken()
{
 return json_edit_r("teltoken");
  //  String ans = LSreadFile(path);
  //    JsonDocument doc;
  //   deserializeJson(doc,ans);
    
  //     String data = doc["teltoken"];
  //     return data;
}

void    SetTelToken( String data)
{
   String ans = LSreadFile(path);
    JsonDocument doc;
     deserializeJson(doc,ans);
    doc["teltoken"] = data;
    serializeJson(doc,ans);
    LSwriteFile(path,ans);

}

String  GetChatId( )
{
   return json_edit_r("chatid");


}
void    SetChatId(String data)
{
  String ans = LSreadFile(path);
    JsonDocument doc;
     deserializeJson(doc,ans);
    doc["chatid"] = data;
    serializeJson(doc,ans);
    LSwriteFile(path,ans);
}

 String  GetLastUpdateId( )
{

      return json_edit_r("lastupdate_id");

}
void  SetLastUpdateId( String data)
{
  String ans = LSreadFile(path);
    JsonDocument doc;
     deserializeJson(doc,ans);
    doc["lastupdate_id"] = data;
    serializeJson(doc,ans);
    LSwriteFile(path,ans);
}

bool  GetIsNegtiveTimeOffset( )
{
     String ans = LSreadFile(path);
      JsonDocument doc;
    deserializeJson(doc,ans);
    bool data =  doc["isnegtivetimeoffset"] ;
    return data;
}
void  SetIsNegtiveTimeOffset(bool data)
{
   
        String ans = LSreadFile(path);
    JsonDocument doc;
     deserializeJson(doc,ans);
    doc["isnegtivetimeoffset"] = data;
    serializeJson(doc,ans);
    LSwriteFile(path,ans);
}

int  GetTimeOffset( )
{
       String ans = LSreadFile(path);
      JsonDocument doc;
    deserializeJson(doc,ans);
    return int(doc["timeoffset"]);
}
void  SetTimeOffset(int data)
{
     String ans = LSreadFile(path);
    JsonDocument doc;
     deserializeJson(doc,ans);
    doc["timeoffset"] = data;
    serializeJson(doc,ans);
    LSwriteFile(path,ans);
    }

 bool  GetSetup()
{
      String ans = LSreadFile(path);
      JsonDocument doc;
    deserializeJson(doc,ans);
    return doc["setup"];
}
void  SetSetup(bool data)
{
    String ans = LSreadFile(path);
    JsonDocument doc;
     deserializeJson(doc,ans);
    doc["timeoffset"] = data;
    serializeJson(doc,ans);
    LSwriteFile(path,ans);
}

int  GetPinTrys( )
{
      String ans = LSreadFile(path);
      JsonDocument doc;
    deserializeJson(doc,ans);
    return doc["pintrys"];
}
void  SetPinTrys(int data)
{
}

int  GetFingTrys()
{
      String ans = LSreadFile(path);
      JsonDocument doc;
    deserializeJson(doc,ans);
    return doc["fingtrys"];
}
void  SetFingTrys(int data)
{
}

bool  GetOverTrys()
{
       String ans = LSreadFile(path);
      JsonDocument doc;
    deserializeJson(doc,ans);
    return doc["overtrys"];
}
void    SetOverTrys(bool data)
{
}

bool  GetErrorCom()
{
      String ans = LSreadFile(path);
      JsonDocument doc;
    deserializeJson(doc,ans);
    return doc["errorcom"];
}
void  SetErrorCom(bool data)
{
}

String    GetSsid()
{
 String ans = LSreadFile(path);
      JsonDocument doc;
    deserializeJson(doc,ans);
         String data = doc["ssid"];

    return data;
}

void  SetSsid( String data)
{

}

String    GetPass()
{
  String ans = LSreadFile(path);
      JsonDocument doc;
    deserializeJson(doc,ans);
       String data = doc["pass"];

    return data;
}

void  SetPass(String data){
  
}