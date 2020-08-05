#include <SPI.h>
#include <Dhcp.h>
#include <Dns.h>
#include <Ethernet.h>
#include <EthernetClient.h>
#include <EthernetServer.h>
#include <ArduinoJson.h>
#include "DHT.h"
#define DHTPIN 8
#define DHTTYPE DHT11
DHT dht(DHTPIN,DHTTYPE);

byte mac[]={0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};

IPAddress ip(192,168,30,182);

EthernetServer server(80);

String buffer="";

void setup() {
  Serial.begin(9600);
  Ethernet.begin(mac,ip);

  Serial.println("WebServer Send DHT11 Sensor DATA");
  Serial.print("server is at ");
  Serial.println(Ethernet.localIP());

  server.begin(); //서버 작동
  dht.begin(); //센서를 시작했다는 의미

  delay(2000);
}

void loop() {

  delay(2000);
  int h = dht.readHumidity();
  int t = dht.readTemperature();
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" C");

  //수신 클라이언트 확인
  EthernetClient client = server.available();
  
  //클라이언트가 없을때
  if(!client){ return; }
  else{
    Serial.println("** New client connected...**");

    while( client.available() ){
      client.read();
    }
    DynamicJsonDocument doc(500);
    doc["Humidity"] = dht.readHumidity();
    doc["Temperature"] = dht.readTemperature();

    Serial.print(F("Sending:"));
    serializeJson(doc, Serial);
    Serial.println();
    client.println(F("HTTP/1.0 200 OK"));
    client.println(F("Content-Type: application/json; charset-utf-8"));
    client.println(F("Connection: close"));
    client.print(F("Content-Length: "));
    client.println(measureJsonPretty(doc));
    client.println();

    String str ="";
    serializeJson(doc,str);

    Serial.println("callback("+str+")");
    client.println("callback("+str+")");

    client.stop();
    Serial.println("** Client disconnected... **");
  }



}
