#include <WiFi.h>
#include <HTTPClient.h>
  
const char* ssid = "Raghav-2.4G";
const char* password =  "raghavp01";
  
void setup() {
  
  Serial.begin(115200);
  delay(4000);
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
  
  Serial.println("Connected to the WiFi network");

  pinMode(15, INPUT_PULLUP);
  pinMode(13, INPUT_PULLUP);



  
}
  
void loop() {

int bulbValue = digitalRead(13);
if (bulbValue == LOW){
    Serial.println("Pin 13 connected bulbs on");
    bulbs_on();}

int panelValue = digitalRead(15);
if (panelValue == LOW){
    Serial.println("Pin 15 connected panels on");
    panels_on();}


    
}

  


void panels_on(){
  if ((WiFi.status() == WL_CONNECTED)) { //Check the current connection status
  
    HTTPClient http;
  
    http.begin("http://www.virtualsmarthome.xyz/url_routine_trigger/activate.php?trigger=aa12a77f-e0c2-467b-b4cd-40539f103dbb&token=fb23310c-2709-4abd-b6eb-de5e9d83f61b&response=json"); //Specify the URL
    int httpCode = http.GET();                                        //Make the request
  
    if (httpCode > 0) { //Check for the returning code
  
        String payload = http.getString();
        Serial.println(httpCode);
        Serial.println(payload);
      }
  
    else {
      Serial.println("Error on HTTP request");
    }
  
    http.end(); //Free the resources
  }
}

void bulbs_on(){
  if ((WiFi.status() == WL_CONNECTED)) { //Check the current connection status
  
    HTTPClient http;
  
    http.begin("https://www.virtualsmarthome.xyz/url_routine_trigger/activate.php?trigger=bada2e58-7584-4727-a3e7-07f87f55a03b&token=be140c16-0a53-47ae-b149-93676335d146&response=json"); //Specify the URL
    int httpCode = http.GET();                                        //Make the request
  
    if (httpCode > 0) { //Check for the returning code
  
        String payload = http.getString();
        Serial.println(httpCode);
        Serial.println(payload);
      }
  
    else {
      Serial.println("Error on HTTP request");
    }
  
    http.end(); //Free the resources
  }
}