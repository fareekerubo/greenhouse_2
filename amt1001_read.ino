boolean read_sensor() {
  uint16_t step = analogRead(tempPin);
  uint16_t step1 = analogRead(tempPin1);
  //uint16_t step2 = analogRead(tempPin2);
  float temperature = amt1001_gettemperature(step);
  float temperature1 = amt1001_gettemperature(step1);
  //float temperature2 = amt1001_gettemperature(step2);
//  Serial.print(temperature);
//  Serial.print("        ");
//  Serial.print(temperature1);
//  Serial.println("        ");
//  //Serial.print(temperature2);
//  //Serial.print("        ");
//  delay(1000);
//
  avg = average(temperature, temperature1);
//  Serial.print(avg);
//  Serial.print("     ");

  return true;

}

boolean read_sensor2() {
  uint16_t step2 = analogRead(A2);
  //uint16_t step2 = analogRead(tempPin2);
  float temperature2 = amt1001_gettemperature(step2);
 

  return true;

}
