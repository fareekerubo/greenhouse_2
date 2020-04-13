void query() {
  if (SMSRequest()) {


    if (read_sensor()) {
      delay(10);
      sms();
      //      // Uncomment to change message with farenheit temperature
      //      // String dataMessage = ("Temperature: " + String(f) + "*F " + " Humidity: " + String(h) + "%");
      //
      //      // Send the SMS text message
      //SIM800.print(dataMessage);
      Serial.println("Kwisha");
      //      // Give module time to send SMS
      delay(1000);
    }
  }
  delay(10);
}

boolean SMSRequest() {
  if (SIM800.available() > 0) {
    incomingChar = SIM800.read();
    if (incomingChar == 'S') {
      delay(10);
      Serial.print(incomingChar);
      incomingChar = SIM800.read();
      if (incomingChar == 'T') {
        delay(10);
        Serial.print(incomingChar);
        incomingChar = SIM800.read();
        if (incomingChar == 'A') {
          delay(10);
          Serial.print(incomingChar);
          incomingChar = SIM800.read();
          if (incomingChar == 'T') {
            delay(10);
            Serial.print(incomingChar);
            incomingChar = SIM800.read();
            if (incomingChar == 'E') {
              delay(10);
              Serial.print(incomingChar);
              Serial.print("...Request Received \n");
              return true;
            }
          }
        }
      }
    }
  }
  return false;
}
