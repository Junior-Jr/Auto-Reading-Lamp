#define LAMP  8  // choose the pin for the RELAY</p>
#define PIR 4   // choose the input pin (for PIR sensor)</p>                                             
void setup()
{                                                                   
  Serial.begin(9600);
  pinMode(LAMP, OUTPUT); // declare lamp as output
  pinMode(PIR,INPUT); // declare sensor as input
}                                                                                                                         
void loop() { 
  int valeur_ldr = analogRead(A0); // read LDR value
  int valeur_pir = analogRead(A1); // read input value
  int n=0;
  Serial.println(valeur_ldr);
  Serial.println(valeur_pir);
  if (valeur_pir >=100){
    digitalWrite(LAMP,1);  // Turn ON the light
    n=1;
    if((valeur_ldr<40) ){
       Serial.println("Open");
       digitalWrite(LAMP,1);  // Turn ON the light
       delay(1000);
       }
    else {
       Serial.println("Close");
       digitalWrite(LAMP,0); // Turn OFF the light
       delay(1000);      
      } 
      }
   else if (valeur_pir <= 100 && n!=0&&n>10){
    digitalWrite(LAMP,1);  // Turn ON the light
    n++;
    if((valeur_ldr<20&&valeur_ldr<300) ){
       Serial.println("Open");
       digitalWrite(LAMP,1);  // Turn ON the light
       delay(1000);
      }
     else if (valeur_ldr>100&&valeur_ldr>300) {
       Serial.println("Close");
       digitalWrite(LAMP,0); // Turn OFF the light
       delay(1000);    
       }
 }
 else if (valeur_pir ==0){
  digitalWrite(LAMP,0); // Turn OFF the light
  n=0;
  delay(1000);
 }
}

