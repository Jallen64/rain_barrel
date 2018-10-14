#include <Stepper.h>

#define STEPS 100//number of steps you want the motor to take

const int LIQUID_SENSOR_PIN = 12;
const int LED_PIN = 13;

Stepper stepper(STEPS, 4, 5, 6, 7);

void setup() {
  pinMode(LIQUID_SENSOR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  // set the speed of the motor to 30 RPMs
  stepper.setSpeed(60);

}

void loop() {

  // Read sensor. If liquid touches the tip, the sensor will 
  // read 0V. Turn on LED if liquid is present.
  
  int isDry = digitalRead(LIQUID_SENSOR_PIN);
  if ( !isDry ) {
    open();
  } 
  delay(200);
}

void open() {
    digitalWrite(LED_PIN, LOW);
    Serial.println("Backward");
    stepper.step(-STEPS);
    bool dry = false;
    while(!dry){
      delay(1000);
      int isDry = digitalRead(LIQUID_SENSOR_PIN);
      if(isDry){
        dry = true;
      }      
    }
    digitalWrite(LED_PIN, HIGH);
    Serial.println("Forward");
    stepper.step(STEPS); 
}
