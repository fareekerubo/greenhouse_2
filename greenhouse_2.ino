#include <LiquidCrystal_I2C.h>
#include <amt1001_ino.h>
#include <SoftwareSerial.h>

uint16_t temperature;
uint16_t temperature1;
uint16_t temperature2;

int tempPin = A0;
int tempPin1 = A1;
int tempPin2= A2;

int gsm_reset = 4;

int state = 0;
String dataMessage = "";
String dataMessage1 = "";
// Create global varibales to store temperature and humidity
float t; // temperature in celcius
float t1;
float t2;


float avg;

float average(int tempPin, int tempPin1) {
  return (float)(tempPin + tempPin1) / 2;
}


int upperLIMIT = 27;
int lowerLIMIT = 24;

//const int ledPin = 4; //LED pins for temperature control
const int ledPin2 = 5;
const int ledPin3 = 6;

#define FLOAT_SENSOR  7    // the number of the pushbutton pin
#define LED           8


SoftwareSerial SIM800(3, 2);
LiquidCrystal_I2C lcd(0x27, 16, 2);




// Create variable to store incoming SMS characters
char incomingChar;




void setup() {
  delay(20000);
  Serial.begin(9600);
  Serial.print("Initializing....");
  pinMode(tempPin, INPUT);
  pinMode(tempPin1, INPUT);
 pinMode(tempPin2, INPUT);
 pinMode(gsm_reset, OUTPUT);
  SIM800.begin(9600);
  lcd.begin();
  lcd.backlight();

 digitalWrite(gsm_reset, HIGH);
  pinMode(LED, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(FLOAT_SENSOR, INPUT_PULLUP);


  // Give time to your GSM shield log on to network
  
  Serial.print("SIM800 ready...");

  // AT command to set SIM800 to SMS mode
  SIM800.print("AT+CMGF=1\r");
  delay(100);
  // Set module to send SMS data to serial out upon receipt
  SIM800.print("AT+CNMI=2,2,0,0,0\r");
  delay(100);
}

//  SIM800.println("FARM: NGONG");
//  SIM800.println("BLOCK:1OF2");
//  SIM800.println("GH NO:001");

void loop() {
  //delete sms
  read_sensor();
   read_sensor2();
//  dataMessage = ("FARM:  NGONG" + \n + "BLOCK:1OF2" + '\n' + "GH NO:001" + '\n'  "Ambient Temperature: " + String(avg) + "*C " );
  dataMessage = (" FARM:    NGONG \n BLOCK: 1OF2 \n GH NO:  001 \n Ambient Temperature:" + String(avg) + "*C " );
  dataMessage1 = ("Ground Temperature: " + String(t2) + "*C " );
  Serial.print(dataMessage);
  Serial.print("    ");
  Serial.print(dataMessage1);
  Serial.println("        ");
  delay(100);
  sms();
  delay(1000);
  sms1();
  //delay(50);
  //digitalWrite(gsm_reset, LOW);
  //delay(500);
  //digitalWrite(gsm_reset, HIGH);
  //sms1();
  delay(900000);
  // // temperature_control();
  // // pump_control();
  //  query();
  
}
