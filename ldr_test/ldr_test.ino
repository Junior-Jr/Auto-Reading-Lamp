#define LAMP  8  // choose the pin for the RELAY</p>
#define PIR 4   // choose the input pin (for PIR sensor)</p>                                             
void setup()
{                                                                   
  Serial.begin(9600);
  pinMode(LAMP, OUTPUT); // declare lamp as output
  pinMode(PIR,INPUT); // declare sensor as input
}                                                                                                                         
void loop() {
  int valeur_ldr = analogRead(A0);
  int valeur_pir = digitalRead(A1);
  Serial.println(valeur_ldr);
  Serial.println(valeur_pir);
    if((valeur_ldr<40) && ( valeur_pir == HIGH) ){
       Serial.println("Open");
       analogWrite(LAMP,1000);  // Turn ON the light
       delay(6000);
       }
    else {
       Serial.println("Close");
       digitalWrite(LAMP,LOW); // Turn OFF the light     
      }

}

