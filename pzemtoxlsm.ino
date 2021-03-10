#include <PZEM004Tv30.h>

/* Use software serial for the PZEM
 * Pin 5 Rx (Connects to the Tx pin on the PZEM)
 * Pin 4 Tx (Connects to the Rx pin on the PZEM)
*/
PZEM004Tv30 pzem(4, 5);
 
void setup() {
  Serial.begin(9600);
  Serial.print("Reset Energy");
  pzem.resetEnergy();
  pzem.setAddress(0x42);
  Serial.println("CLEARDATA");
  Serial.println("LABEL,Time,Voltage(V),Current(A),Power(W),Energy(Kwh),Frequency(Hz),PowerFactor(PF)");
  Serial.println("RESETTIMER");
}
 
void loop() {
//int sensorValue = analogRead(A0);
Serial.print("DATA,TIME,");
    float voltage = pzem.voltage();
    if( !isnan(voltage) ){ 
        Serial.print(voltage); 
       // Serial.print("V");
        Serial.print(",");
    } else {
        Serial.print("Error reading voltage");
        Serial.print(",");
    }
 
   float current = pzem.current();
    if( !isnan(current) ){ 
        Serial.print(current); 
      //  Serial.print("A");
        Serial.print(",");
    } else {
        Serial.print("Error reading current");
        Serial.print(",");
    }
 
    float power = pzem.power();
    if( !isnan(power) ){ 
        Serial.print(power); 
       // Serial.print("W");
        Serial.print(",");
    } else {
        Serial.print("Error reading power");
        Serial.print(",");
    }
 
    float energy = pzem.energy();
    if( !isnan(energy) ){ 
        Serial.print(energy,3); 
       // Serial.print("kWh");
        Serial.print(",");
    } else {
        Serial.print("Error reading energy");
        Serial.print(",");
    }
 
    float frequency = pzem.frequency();
    if( !isnan(frequency) ){
        Serial.print(frequency, 1); 
      //  Serial.print("Hz");
        Serial.print(",");
    } else {
        Serial.print("Error reading frequency");
        Serial.print(",");
    }
 
    float pf = pzem.pf();
    if( !isnan(pf) ){
        Serial.print(pf);
        Serial.print(",");
    } else {
        Serial.print("Error reading power factor");
        Serial.print(",");
    }
 
    Serial.println();
    delay(1000);
}
