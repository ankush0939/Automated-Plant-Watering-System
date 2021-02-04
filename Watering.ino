/*Calibration of the soil moisture sensor as the 
volumetric moisture ccontent value varies soil to soil.*/

// defining default values

#define soilWet 400
#define soilDry 750
#define sensorPower 0         //For power supply to sensor          
#define relayPower 1         //For power supply to relay, relay is in NO mode
#define sensorInput A0     //For reading the analog values from sensor

void setup() {
  // put your setup code here, to run once:
  
  pinMode(sensorPower,OUTPUT);
  pinMode(relayPower,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(sensorPower, HIGH);             // Power supplied to sensor
  int VMC =  analogRead(sensorInput);          // Reading the value of VMC from sensor
  digitalWrite(sensorPower, LOW);              // Power discontinued as the reading is taken

  if( VMC >= soilWet && VMC < soilDry ){

    digitalWrite(relayPower, HIGH);           // Power is being supplied to water pump through relay
    delay(3000);                              // For three seconds the water will flow through relay water pump
    digitalWrite(relayPower, LOW);
    
  }

  if( VMC  > soilDry) {

     digitalWrite(relayPower, HIGH);
     delay(10000);                         // For ten seconds, water flows as the soil is too dry 
     digitalWrite(relayPower, LOW);
     
  }

  else {

    digitalWrite(relayPower, LOW);
    
  }

}
