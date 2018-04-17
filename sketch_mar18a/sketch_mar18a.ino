#define LAMP  8  // choose the pin for the RELAY
#define PIR 4   // choose the input pin (for PIR sensor)
int n=0,stat=0;
void setup()
{                                                                   
  Serial.begin(9600);
  pinMode(LAMP, OUTPUT); // declare lamp as output
  pinMode(PIR,INPUT); // declare sensor as input
}                                                                                                                         
void loop() { 
  int valeur_ldr = analogRead(A0); // read LDR value
  int valeur_pir = analogRead(A1); // read input value
  Serial.println(valeur_ldr);
  Serial.println(valeur_pir);
  delay(1000);
  if (valeur_pir>=600&&n==0){
    n++;
    if (stat==1)
       digitalWrite(LAMP,1);
    else
       digitalWrite(LAMP,0);
  }
  else if (valeur_pir>=600&&n==1){
    n++;
     if (stat==1)
       digitalWrite(LAMP,1);
    else
       digitalWrite(LAMP,0);
  }
  else if (valeur_pir>=600&&n==2){
    if (stat==0)
    stat=1;
    else
    stat=0;
    n++;
  }
  else if (stat==0&&n==3)
    n=0;
  if ((stat==1&&n==3)||(stat==1&&n==0)){
    if((valeur_ldr<600) ){
       Serial.println("Open");
       digitalWrite(LAMP,1);  // Turn ON the light
       stat=1;
       }
    else {
       Serial.println("Close");
       digitalWrite(LAMP,0); // Turn OFF the light      
      }
      n=0;
      }
     Serial.print(n);
     Serial.print(" ");
     Serial.println(stat);
}

