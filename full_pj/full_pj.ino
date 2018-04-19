#include <LiquidCrystal.h>
#define LAMP  8 // The compiler will replace any mention of LAMP with 8 at compile time.
#define PIR 4 // The compiler will replace any mention of PIR with 4 at compile time.
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int n=0,stat=0,timing=0;
void setup() {
  // set up the LCD's number of columns and rows
  lcd.begin(8, 2);
  // Print a message to the LCD.
  lcd.print("Lamp");
  // set the cursor to column 0, line 1
  lcd.setCursor(0, 1); 
  // print a message to the LCD.
  lcd.print("Start");
  pinMode(LAMP, OUTPUT); // sets LAMP as output
  pinMode(PIR,INPUT); // sets PIR as output
}
void loop()
{
  int value_ldr = RecieveLDR();
  int value_pir = RecievePIR();
  timing = checkPIR(value_pir, timing);
  if (timing!=0)
  timing = adjustbrightness(value_ldr, timing);
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
int checkPIR(int var_pir, int timing)
{
  if (var_pir>=600&&timing==0)
  {
    timing = 60;
    digitalWrite(LAMP,1);
  }
  else if (var_pir>=600&&timing!=0)
    timing+=3;
  else if (timing==0)
  {
    digitalWrite(LAMP,0);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Lamp is");
    lcd.setCursor(0,1);
    lcd.print("already");
  }
  return timing;
}
int adjustbrightness(int var_ldr, int timing)
{
  int total;
  lcd.clear();
  lcd.setCursor(0,0);
  if (var_ldr<500)
  {
    total = 500-var_ldr;
    lcd.print("Increase");
  }
  else if (var_ldr>600){
    total = 600-var_ldr;
    lcd.print("Decrease");
  }
  else if (var_ldr<600&&var_ldr>500)
  {
    lcd.print("Good To");
    lcd.setCursor(0,1);
    lcd.print(" Read");
    timing--;
    return timing;
  }
  lcd.setCursor(0,1);
  lcd.print(total);
  timing--;
  return timing;
}
