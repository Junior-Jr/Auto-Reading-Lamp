#define LAMP  8  // choose the pin for the RELAY
#define PIR 4   // choose the input pin (for PIR sensor)
int stat = 1,valeur_pir=0,valeur_ldr=0; // defalt status lamp is 1                                       
void setup()
{                                                                   
  Serial.begin(9600);
  pinMode(LAMP, OUTPUT); // declare lamp as output
  pinMode(PIR,INPUT); // declare sensor as input
}                                                                                                                         
void loop() { 
  valeur_ldr = analogRead(A0); //input LDR
  valeur_pir = analogRead(A1); // input PIR
  if(valeur_pir>=600){ //check status ON or OFF
     if (stat==1){ // if status is 1 set lamp to of mode and set status = 0
      digitalWrite(LAMP,0);
      stat=0;}
     else // if status is 0 set status = 1
      stat=1;
  }
  else if (valeur_pir<600&&stat==0){ // check if valeur_pir < 600(ค่านี้เป็นค่าที่สมมติขึ้นมายังไม่ได้ใช้จริง เป็นค่าที่ใช้เช็คความร้อนของคน)
    if(valeur_ldr<250){ // check if valeur_pir <250(ค่านี้สมมุติขึ้นมา ค่าจริงๆคือค่าสูงสุตของความเข้มแสงสูงสุดที่ใช้ในการอ่านหนังสือ)
       Serial.println("Open");
      digitalWrite(LAMP,1);  // Turn ON the light
        }
    else { // check if valeur_ldr>standard var of ldr
       Serial.println("Close");
       digitalWrite(LAMP,0); // Turn OFF the light
       }
  }
  Serial.println(valeur_ldr); // just idiot print check var
  Serial.println(valeur_pir);
  delay(1000);
}

