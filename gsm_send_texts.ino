void sms()
{
  SIM800.begin(9600);

  Serial.println("Initializing...");
  delay(1000);

  SIM800.println("AT"); //Once the handshake test is successful, it will back to OK
  //updateSerial();
  delay(1000);
  SIM800.println("AT+CMGF=1"); // Configuring TEXT mode
  // updateSerial();
  delay(1000);
  SIM800.println("AT+CMGS=\"+254723580448\"");//change ZZ with country code and xxxxxxxxxxx with phone number to sms
  //updateSerial();
  delay(1000);
//SIM800.println("FARM: NGONG");
//SIM800.println("BLOCK:1OF2");
//// SIM800.println("GH NO:001");
// delay(50);
  SIM800.println(dataMessage); //text content
  SIM800.print(dataMessage1);
delay(1000);
  SIM800.write(26);
  Serial.println("DONE");
}


void sms1()
{
  SIM800.begin(9600);

  Serial.println("SMS 2...");
  delay(1000);

  SIM800.println("AT"); //Once the handshake test is successful, it will back to OK
//  //updateSerial();
  delay(1000);
 SIM800.println("AT+CMGF=1"); // Configuring TEXT mode
//  // updateSerial();
  delay(1000);
  
   SIM800.println("AT+CMGS=\"+254703149329\"");//change ZZ with country code and xxxxxxxxxxx with phone number to sms
  //updateSerial();
  delay(1000);
  SIM800.println(dataMessage); //text content
  SIM800.print(dataMessage1);
  // updateSerial();
  SIM800.write(26);
  Serial.println("SEND..");
}

void sms_high()
{
  SIM800.begin(9600);

  Serial.println("Initializing...");
  delay(1000);

  SIM800.println("AT"); //Once the handshake test is successful, it will back to OK
  //updateSerial();
  delay(1000);
  SIM800.println("AT+CMGF=1"); // Configuring TEXT mode
  // updateSerial();
  delay(1000);
  SIM800.println("AT+CMGS=\"+254703149329\"");//change ZZ with country code and xxxxxxxxxxx with phone number to sms
  //updateSerial();
  delay(1000);
  SIM800.print("TEMPERATURE HIGH"); //text content
  // updateSerial();
  SIM800.write(26);
}



void sms_low()
{
  SIM800.begin(9600);

  Serial.println("Initializing...");
  delay(1000);

  SIM800.println("AT"); //Once the handshake test is successful, it will back to OK
  //updateSerial();
  delay(1000);
  SIM800.println("AT+CMGF=1"); // Configuring TEXT mode
  // updateSerial();
  delay(1000);
  SIM800.println("AT+CMGS=\"+254703149329\"");//change ZZ with country code and xxxxxxxxxxx with phone number to sms
  //updateSerial();
  delay(1000);
  SIM800.print("TEMPERATURE LOW"); //text content
  // updateSerial();
  SIM800.write(26);
}
