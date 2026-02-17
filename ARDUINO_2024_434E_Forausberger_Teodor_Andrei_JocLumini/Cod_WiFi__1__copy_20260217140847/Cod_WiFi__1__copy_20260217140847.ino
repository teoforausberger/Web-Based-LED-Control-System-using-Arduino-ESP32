const char* ssid = "Proiect.tema9";
const char* password = "team8_amaratii";
 
 
WiFiServer server(80);
 
 
String header;
 
String outputJOC_1State = "off";
String outputJOC_2State = "off";
String outputJOC_3State = "off";
 
 
 
const int outputLED_1 = 17;
const int outputLED_2 = 5;
const int outputLED_3 = 18;
const int outputLED_4 = 21;
const int outputDIGIT1 = 13;
const int outputDIGIT2 = 4;
const int outputA = 2;
const int outputB = 12;
const int outputC = 14;
const int outputD = 26;
const int outputE = 27;
const int outputF = 0;
const int outputG = 15;
 
void setup() {
  Serial.begin(115200);
 
  pinMode(outputLED_1, OUTPUT);
  pinMode(outputLED_2, OUTPUT);
  pinMode(outputLED_3, OUTPUT);
  pinMode(outputLED_4, OUTPUT);
  pinMode(outputDIGIT1, OUTPUT);
  pinMode(outputDIGIT2, OUTPUT);
  pinMode(outputA, OUTPUT);
  pinMode(outputB, OUTPUT);
  pinMode(outputC, OUTPUT);
  pinMode(outputD, OUTPUT);
  pinMode(outputE, OUTPUT);
  pinMode(outputF, OUTPUT);
  pinMode(outputG, OUTPUT);
 
 
  digitalWrite(outputLED_4, LOW);
  digitalWrite(outputLED_2, LOW);
  digitalWrite(outputLED_3, LOW);
  digitalWrite(outputLED_4, LOW);
  digitalWrite(outputDIGIT1, LOW);
  digitalWrite(outputDIGIT2, LOW);
  digitalWrite(outputA, LOW);
  digitalWrite(outputB, LOW);
  digitalWrite(outputC, LOW);
  digitalWrite(outputD, LOW);
  digitalWrite(outputE, LOW);
  digitalWrite(outputF, LOW);
  digitalWrite(outputG, LOW);
 
 
 
  Serial.print("Setting AP (Access Point)…");
 
  WiFi.softAP(ssid, password);
 
  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);
 
  server.begin();
}
 
void loop(){
  WiFiClient client = server.available();  
 
  if (client) {                            
    Serial.println("New Client.");          
    String currentLine = "";                
    while (client.connected()) {            
      if (client.available()) {            
        char c = client.read();            
        Serial.write(c);                    
        header += c;
        if (c == '\n') {                    
          if (currentLine.length() == 0) {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();
         
            if (header.indexOf("GET /1/on") >= 0) {
              Serial.println("JOC 1 on");
             
              outputJOC_1State = "on";
 
              digitalWrite(outputDIGIT1, HIGH);
              digitalWrite(outputDIGIT2, LOW);
              digitalWrite(outputA, LOW);
              digitalWrite(outputB, HIGH);
              digitalWrite(outputC, HIGH);
              digitalWrite(outputD, LOW);
              digitalWrite(outputE, LOW);
              digitalWrite(outputF, LOW);
              digitalWrite(outputG, LOW);
 
 
              digitalWrite(outputLED_1, HIGH);
              delay(250);
              digitalWrite(outputLED_3, HIGH);
 
            } else if (header.indexOf("GET /1/off") >= 0) {
              Serial.println("JOC 1 off");
             
              outputJOC_1State = "off";
              digitalWrite(outputLED_1, LOW);
              digitalWrite(outputLED_3, LOW);
              digitalWrite(outputDIGIT1, LOW);
              digitalWrite(outputDIGIT2, LOW);
              digitalWrite(outputA, LOW);
              digitalWrite(outputB, LOW);
              digitalWrite(outputC, LOW);
              digitalWrite(outputD, LOW);
              digitalWrite(outputE, LOW);
              digitalWrite(outputF, LOW);
              digitalWrite(outputG, LOW);
            }
 
            if (header.indexOf("GET /2/on") >= 0) {
              Serial.println("JOC 2 on");
             
              outputJOC_2State = "on";
              digitalWrite(outputDIGIT1, HIGH);
              digitalWrite(outputDIGIT2, LOW);
              digitalWrite(outputA, HIGH);
              digitalWrite(outputB, HIGH);
              digitalWrite(outputC, LOW);
              digitalWrite(outputD, HIGH);
              digitalWrite(outputE, HIGH);
              digitalWrite(outputF, LOW);
              digitalWrite(outputG, HIGH);
              digitalWrite(outputLED_4, HIGH);
              delay(500);
              digitalWrite(outputLED_2, HIGH);
 
            } else if (header.indexOf("GET /2/off") >= 0) {
              Serial.println("JOC 2 off");
             
              outputJOC_2State = "off";
              digitalWrite(outputLED_2, LOW);
              digitalWrite(outputLED_4, LOW);
              digitalWrite(outputDIGIT1, LOW);
              digitalWrite(outputDIGIT2, LOW);
              digitalWrite(outputA, LOW);
              digitalWrite(outputB, LOW);
              digitalWrite(outputC, LOW);
              digitalWrite(outputD, LOW);
              digitalWrite(outputE, LOW);
              digitalWrite(outputF, LOW);
              digitalWrite(outputG, LOW);
            }            
 
            if (header.indexOf("GET /3/on") >= 0) {
              Serial.println("JOC 3 on");
             
              outputJOC_3State = "on";
              digitalWrite(outputDIGIT1, HIGH);
              digitalWrite(outputDIGIT2, LOW);
              digitalWrite(outputA, HIGH);
              digitalWrite(outputB, HIGH);
              digitalWrite(outputC, HIGH);
              digitalWrite(outputD, HIGH);
              digitalWrite(outputE, LOW);
              digitalWrite(outputF, LOW);
              digitalWrite(outputG, HIGH);
              digitalWrite(outputLED_1, HIGH);
              digitalWrite(outputLED_3, HIGH);
              delay(1000);
              digitalWrite(outputLED_4, HIGH);
              digitalWrite(outputLED_2, HIGH);
 
            } else if (header.indexOf("GET /3/off") >= 0) {
              Serial.println("JOC 3 off");
             
              outputJOC_3State = "off";
              digitalWrite(outputLED_1, LOW);
              digitalWrite(outputLED_2, LOW);
              digitalWrite(outputLED_3, LOW);
              digitalWrite(outputLED_4, LOW);
              digitalWrite(outputLED_2, LOW);
              digitalWrite(outputLED_4, LOW);
              digitalWrite(outputDIGIT1, LOW);
              digitalWrite(outputDIGIT2, LOW);
              digitalWrite(outputA, LOW);
              digitalWrite(outputB, LOW);
              digitalWrite(outputC, LOW);
              digitalWrite(outputD, LOW);
              digitalWrite(outputE, LOW);
              digitalWrite(outputF, LOW);
              digitalWrite(outputG, LOW);
            }
           
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println(".button { background-color: #4CAF50; border: none; color: white; padding: 16px 40px;");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            client.println(".button2 {background-color: #555555;}</style></head>");
           
           
            client.println("<body><h1>Joc de lumini</h1>");
           
           
            client.println("<p>JOC 1 - State " + outputJOC_1State + "</p>");
                 
            if (outputJOC_1State=="off") {
              client.println("<p><a href=\"/1/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/1/off\"><button class=\"button button2\">OFF</button></a></p>");
            }
 
            client.println("<p>JOC 2 - State " + outputJOC_2State + "</p>");
                 
            if (outputJOC_2State=="off") {
              client.println("<p><a href=\"/2/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/2/off\"><button class=\"button button2\">OFF</button></a></p>");
            }
 
            client.println("<p>JOC 3 - State " + outputJOC_3State + "</p>");
                 
            if (outputJOC_3State=="off") {
              client.println("<p><a href=\"/3/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/3/off\"><button class=\"button button2\">OFF</button></a></p>");
            }
               
            client.println("</body></html>");
           
            client.println();
            break;
          } else { //
            currentLine = "";
          }
        } else if (c != '\r') {  
          currentLine += c;      
        }
      }
    }
   
    header = "";
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}
has context menu