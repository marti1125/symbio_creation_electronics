#include <ESP8266WiFi.h>          //ESP8266 Core WiFi Library (you most likely already have this in your sketch)

#include <DNSServer.h>            //Local DNS Server used for redirecting all requests to the configuration portal
#include <ESP8266WebServer.h>     //Local WebServer used to serve the configuration portal
#include <WiFiManager.h> 

int letpint = 13 //GPIO13 --D7;

WiFiManager wifiManager;
WiFiServer server(80);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  wifiManager.autoConnect("MOVISTAR_FBCF", "FV59KimE4TbeUMwVPwDy");

  Serial.println(WiFi.localIP());

  pinMode(letpint, OUTPUT);
  digitalWrite(letpint, LOW);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println(".");
  }

  server.begin();
  Serial.println("Servicio a iniciado");

  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
  
}

void loop() {
  // put your main code here, to run repeatedly:
  //digitalWrite(letpint, HIGH);

  WiFiClient client = server.available();

  if (!client) {
    return;
  }

  Serial.println("nuevo cliente");
  
  while (!client.available()) {
    delay(1);
  }

  String request = client.readStringUntil('\r');
  client.flush();
  
  int value = LOW;

  Serial.println(request);

  if (request.indexOf("/LED=ON") != -1) {
    digitalWrite(letpint, HIGH);
    value = HIGH;
    Serial.println("prender");
  }

  if (request.indexOf("/LED=OFF") != -1) {
    digitalWrite(letpint, LOW);
    value = LOW;
    Serial.println("apagar");
  }

  //
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
 
  client.print("Led is now: ");
 
  if(value == HIGH) {
    client.print("On");
  } else {
    client.print("Off");
  }
  client.println("<br><br>");
  client.println("<a href=\"/LED=ON\"\"><button>On </button></a>");
  client.println("<a href=\"/LED=OFF\"\"><button>Off </button></a><br />");  
  client.println("</html>");
 
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
  
  
}
