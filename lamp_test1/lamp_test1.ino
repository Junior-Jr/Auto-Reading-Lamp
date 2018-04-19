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
  int n=0,i=0;
  Serial.println(valeur_ldr);
  Serial.println(valeur_pir);
  while(i<6){
    n += valeur_pir = analogRead(A1); 
  }
  if ((valeur_ldr<40)&&(n!=)){
  digitalWrite(LAMP,1);
  delay(11000);
  }
  
  else{
  digitalWrite(LAMP,0);
  delay(500);
  }
}

