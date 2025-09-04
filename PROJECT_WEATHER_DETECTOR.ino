#include <DHT.h>
#include <DHT_U.h>
#include <LiquidCrystal.h>
#include <Servo.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int Temp_Sensor = A0;
int Light_Sensor = A1;
int Humid_Sensor = A2;
int LED = 6;
int ServoPin = 9;
int DHTPin = 10;
int DHTType = DHT22;

Servo myServo;
DHT dht(DHTPin,DHTType);

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(16, 2);  
  pinMode(Temp_Sensor,INPUT); 
  pinMode(Light_Sensor,INPUT);
  pinMode(Humid_Sensor,INPUT);
  pinMode(LED,OUTPUT);
  pinMode(ServoPin,OUTPUT);
  myServo.attach(9);
}

void loop()
{
  // put your main code here, to run repeatedly:
  lcd.setCursor(0, 0);
  lcd.print("TEMP:");
  float temp = map(analogRead(Temp_Sensor),20,358,0,100);
  lcd.print(temp);
  lcd.setCursor(1, 0);
  lcd.print("HUMID:");
  float humid = map(dht.readHumidity(),20,358,0,100);
  lcd.print(humid);
  
  int servoPos = (180./100.)*temp;
  myServo.write(servoPos);
                   
  int ldrs = 0;
  ldrs = analogRead(Light_Sensor);
  Serial.println(ldrs);
  int ledBrightness = (-255./673.)*(ldrs-679);
  analogWrite(LED, ledBrightness);
  delay(200);
}
