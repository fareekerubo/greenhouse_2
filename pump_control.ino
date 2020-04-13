
void pump_control() 
{
  if(digitalRead(FLOAT_SENSOR) == LOW) 
  {
    // turn LED on:
    digitalWrite(LED, HIGH);
  } 
  else 
  {
    // turn LED off:
    digitalWrite(LED, LOW);
  }
}
