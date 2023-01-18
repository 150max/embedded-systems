#include <Wire.h>

#include <Servo.h>

#include <LiquidCrystal.h>

LiquidCrystal lcd(13,12,11,10,9,8);

int PIN_QA=A0;
int PIN_GAS=A1;
int Temperatura = A2;
int Humidade = A3;
int PIN_LED=7;
int PIN_LDR=A4;
int OutputValue=0;

Servo myServo0;
Servo myServo1;
  int state =0;

int pos = 0;
volatile int time =30;
void setup()
{
   Wire.begin(); 
  Serial.begin(9600);
lcd.begin(16,2);
  pinMode(PIN_LED,OUTPUT);
 pinMode(PIN_LDR,INPUT);
  myServo0.attach(6);
   myServo1.attach(5);
}

void loop()
{
  int value_QA = analogRead(PIN_QA);
    int value_GAS = analogRead(PIN_GAS);
    int value_Temperatura = analogRead(Temperatura);
  int value_Humidade = analogRead(Humidade);
  int value_LDR = analogRead(PIN_LDR);
  
  if(value_LDR < 160)
  {
    digitalWrite(PIN_LED,HIGH);
    
  }
  else
    {
    digitalWrite(PIN_LED,LOW);
    
  }
  if (value_Temperatura <100)
  {
    myServo0.write(180);
    delay(3000);
  }
  
  else
  {
    myServo0.write(0);
    delay(3000);
  }
  
  if (value_Humidade < 100)
  {
    
 for (pos=0; pos <180; pos +=1)
 {
   myServo1.write(pos);
   delay(time);
  
 }
     for (pos=180; pos <0; pos -=1)
 {
   myServo1.write(pos);
delay(time);
 }
 
   
  }
  
  delay(1250);

  
   Serial.print("---------------------------------------------\n");
   Serial.print("Valor de Qualidade do Ar = ");
  Serial.println(value_QA);
    Serial.print("Valor de Qualidade do Gas = ");
  Serial.println(value_GAS);
    Serial.print("Valor da Temperatura = ");
  Serial.println(value_Temperatura);
    Serial.print("Valor da Humidade = ");
  Serial.println(value_Humidade);
    Serial.print("Valor da Luminosidade = ");
  Serial.println(value_LDR);
  
  lcd.begin(16,2);
  lcd.print("Qualidade do Ar: ");
  lcd.setCursor(0,1);
  lcd.print(value_QA);
  
  delay(1250);
    lcd.begin(16,2);
  lcd.print("Qualidade do Gas: ");
  lcd.setCursor(0,1);
  lcd.print(value_GAS);
  
  delay(1250);
   lcd.begin(16,2);
  lcd.print("Temperatura: ");
  lcd.setCursor(0,1);
  lcd.print(value_Temperatura);
  
  delay(1250);
    lcd.begin(16,2);
  lcd.print("Humidade: ");
  lcd.setCursor(0,1);
  lcd.print(value_Humidade);
  
  delay(1250);
  
    lcd.begin(16,2);
  lcd.print("Luminosidade: ");
  lcd.setCursor(0,1);
  lcd.print(value_LDR);
  
  delay(1250);
  
}
