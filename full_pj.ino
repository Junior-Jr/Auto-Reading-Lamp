#include <LiquidCrystal.h>
#define LAMP  8 
// The compiler will replace any mention of LAMP with 8 at compile time.
#define PIR 4 
// The compiler will replace any mention of PIR with 4 at compile time.
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int n=0,stat=0,timing=0; // sets the variable
void setup() {
  lcd.begin(8, 2);  // set up the LCD's number of columns and rows
  lcd.print("Lamp");  // Print a message to the LCD.
  lcd.setCursor(0, 1); // set the cursor to column 0, line 1
  lcd.print("Start"); // print a message to the LCD.
  
  pinMode(LAMP, OUTPUT); // sets LAMP as output
  pinMode(PIR,INPUT); // sets PIR as output
  Serial.begin(9600); //  setup serial
}
void loop()
{
  int value_ldr = RecieveLDR();
  int value_pir = RecievePIR();
  Serial.println(value_ldr); //print value
  timing = checkPIR(value_pir, timing); //timing = 0
  if (timing!=0) //check timing if it is't equal to 0
  timing = adjustbrightness(value_ldr, timing);
  delay(1000); // delay 1000 ms before next reading(waits for a second)
}

int RecieveLDR(){
  int ldr = analogRead(A0); // read the input pin
  return ldr;
}
int RecievePIR(){
  int pir = analogRead(A1); // read the input pin
  return pir;
}


int checkPIR(int var_pir, int timing)
{
  if (var_pir>=600&&timing==0) //check value of PIR and timing
  {
    timing = 300; //set the value of timing to 300
    digitalWrite(LAMP,1); //sets the digital pin 8(LAMP) on
  }
  else if (var_pir>=600&&timing!=0) //check value of PIR and timing
    timing += 3; //addition on timing with 3
  else if (timing==0)//check timing
  {
    digitalWrite(LAMP,0); //sets the digital pin 8(LAMP) off
    lcd.clear(); //clears the LCD screen
    lcd.setCursor(0,0); //set the cursor to column0, line0
    lcd.print("Lamp is"); // print "Lamp is" to the LCD.
    lcd.setCursor(0,1); //set the cursor to column0, line1
    lcd.print("already"); // print "already" to the LCD.
  }
  return timing;
}


int adjustbrightness(int var_ldr, int timing)
{
  int total;
  lcd.clear(); //clears the LCD screen
  lcd.setCursor(0,0); //set the cursor to column0, line0
  if (var_ldr<500)//check value of LDR
  {
    total = 500-var_ldr;
    lcd.print("Increase");//print "Increase" to the LCD.
  }
  else if (var_ldr>600){//check value of LDR
    total = 600-var_ldr;
    lcd.print("Decrease");//print "Decrease" to the LCD.
  }
  else if (var_ldr<600&&var_ldr>500) //check value of LDR
  {
    lcd.print("Good To");//print "Good To" to the LCD.
    lcd.setCursor(0,1);//set the cursor to column0, line1jv
    lcd.print(" Read");//print " Read" to the LCD.
    timing--; //decrements timing by 1.
    return timing;
  }
  lcd.setCursor(0,1);//set the cursor to column0, line1
  lcd.print(total);//print value of total to the LCD.
  timing--; //decrements timing by 1.
  return timing;
}
