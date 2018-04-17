#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
#define LAMP  8
#define PIR 4
int n=0,stat=0,timing=0;
void setup() {
  lcd.begin(8, 2);
  lcd.print("Lamp");
  lcd.setCursor(0, 1); 
  lcd.print("Start");
  pinMode(LAMP, OUTPUT);
  pinMode(PIR,INPUT);
}
void loop(){
  int value_ldr = RecieveLDR();
  int value_pir = RecievePIR();
  if (timing != 0)
    int timing = checkPIR(value_pir,timing);
  delay(1000);
}
int RecieveLDR(){
  int ldr = analogRead(A0);
  return ldr;
}
int RecievePIR(){
  int pir = analogRead(A1);
  return pir;
}
int checkPIR(int var_pir, int timing){
  if (var_pir>=600&&timing==0){
    timing = 300;
    digitalWrite(LAMP,1);
  }
  else if (var_pir>=600&&timing!=0)
    timing+=3;
  else if (timing==0){
    digitalWrite(LAMP,0);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Lamp is");
    lcd.setCursor(0,1);
    lcd.print("already");
    return timing;
  }
}
int adjustbrightness(int var_ldr, int timing){
  int total;
  lcd.clear();
  lcd.setCursor(0,0);
  if (var_ldr<500){
    total = 500-var_ldr;
    lcd.print("Increase");
  }
  else if (var_ldr>600){
    total = 600-var_ldr;
    lcd.print("Decrease");
  }
  else if (var_ldr<600&&var_ldr>500);
    lcd.print("Reading");
  lcd.setCursor(0,1);
  lcd.print(total);
  timing--;
  return timing;
}
