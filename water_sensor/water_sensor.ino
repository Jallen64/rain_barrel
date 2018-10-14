const int LIQUID_SENSOR_PIN = 12;
const int LED_PIN = 13;

void setup() { 
  pinMode(LIQUID_SENSOR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
}

void loop() {

  // Read sensor. If liquid touches the tip, the sensor will 
  // read 0V. Turn on LED if liquid is present.
  int isDry = digitalRead(LIQUID_SENSOR_PIN);
  if ( isDry ) {
    digitalWrite(LED_PIN, LOW);
  } else {
    digitalWrite(LED_PIN, HIGH);
  }

  delay(200);
}
