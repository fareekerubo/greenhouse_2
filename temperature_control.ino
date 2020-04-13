//void temperature_control() {
//  if (t >= 24 && t <= 27) //normal green led
//  {
//    digitalWrite (ledPin, HIGH);
//    digitalWrite (ledPin2, LOW);
//    digitalWrite (ledPin3, LOW);
//    state=0;
//  }
//  else if (t <= 24) //temperature low - amber/orange
//  {
//    digitalWrite (ledPin2,  HIGH);
//    digitalWrite (ledPin, LOW);
//    digitalWrite (ledPin3, LOW);
//    sms_low();
//  }
//  else if (t >= 27) {// temperature high - red
//    if(state==0)
//    {
//       sms_high();
//    delay(50);
//    state=1;
//    }
//   
//    else if(state==1)
//    {
//    digitalWrite (ledPin3, HIGH);
//    digitalWrite (ledPin, LOW);
//    digitalWrite (ledPin2, LOW);
//    delay(50);
//    }
//    
//  }
//}
