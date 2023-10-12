#include <SoftwareSerial.h> 
#define TX_PIN      7
#define RX_PIN      6
char value; 
SoftwareSerial bluetooth(RX_PIN, TX_PIN);
int baudRate[] = {300, 1200, 2400, 4800, 9600, 19200, 38400, 57600, 115200};
char kytu;
String chuoi; 
int n=0;
int relay1=2;
int relay2=3;

void setup() {
  Serial.begin(9600);
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  
  
  while (!Serial) {}
  
  Serial.println("Configuring, please wait...");
  
  for (int i = 0 ; i < 9 ; i++) {
     bluetooth.begin(baudRate[i]);
     String cmd = "AT+BAUD4";
     bluetooth.print(cmd);
     bluetooth.flush();
     delay(100);
  }
  
  bluetooth.begin(9600);
  Serial.println("Config done");
  while (!bluetooth) {}
  
  Serial.println("Enter AT commands:");
}
 
void loop() {
  
  if (bluetooth.available()) {
    
    kytu=bluetooth.read();
    chuoi=chuoi+kytu;
    Serial.println(kytu);
    if(chuoi.indexOf("bật đèn")>=0){
        digitalWrite(relay1,HIGH);
        Serial.println(chuoi);
        chuoi="";
        n=0;
      }
    if(chuoi.indexOf("Tắt Đèn")>=0 ){
        digitalWrite(relay1,LOW);
        Serial.println(chuoi);
        chuoi="";
        n=0;
      }
     if(chuoi.indexOf("bật quạt")>=0){
        digitalWrite(relay2,HIGH);
        Serial.println(chuoi);
        chuoi="";
        n=0;
      }
    if(chuoi.indexOf("tắt quạt")>=0){
        digitalWrite(relay2,LOW);
        Serial.println(chuoi);
        chuoi="";
        n=0;
      }
    
  }
  
}

