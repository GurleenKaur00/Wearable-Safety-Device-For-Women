#include <TinyGPS.h>
#include <SoftwareSerial.h>

SoftwareSerial Gps(10, 11);  // SoftwareSerial for GPS module
SoftwareSerial Gsm(8, 9);    // SoftwareSerial for GSM module

char phone_no[] = "+919809143000";
TinyGPS gps;
int state;
String textMessage;
bool callMade = false; // Variable to track if the call has been made

void setup() {
  Serial.begin(9600);
  Gps.begin(9600);  // Initialize GPS module
  Gsm.begin(9600);  // Initialize GSM module
  delay(2000);
  Gsm.println("AT+CMGF=1");  // Send AT commands to GSM module
  delay(100);
  Gsm.println("AT+CNMI=2,2,0,0,0");
  delay(100);
  pinMode(3, INPUT_PULLUP);
}

void loop() {
  bool newData = false;
  unsigned long chars;
  unsigned short sentences, failed;

  for (unsigned long start = millis(); millis() - start < 1000;) {
    while (Gps.available()) {  // Read from the GPS module
      char c = Gps.read();
      Serial.print(c);
      if (gps.encode(c))
        newData = true;
    }
  }

  if (Gsm.available() > 0) {
    textMessage = Gsm.readString();
    textMessage.toUpperCase();
    delay(10);
  }

  state = digitalRead(3);

  if (state == 0) {  // Button press
    Serial.println("Button Press");

    if (newData) {
      float flat, flon;
      unsigned long age;
      gps.f_get_position(&flat, &flon, &age);

      Gsm.println("AT+CMGF=1");  // Set SMS mode
      delay(400);
      Gsm.print("AT+CMGS=\"");
      Gsm.print(phone_no);
      Gsm.println("\"");

      String message = "Alert! I need help. http://maps.google.com/maps?q=loc: Latitude = ";
      message += (flat == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flat, 6);
      message += " Longitude = ";
      message += (flon == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flon, 6);

      Gsm.println(message);
      Gsm.write(0x1A);  // Send Ctrl+Z to end the message
      delay(200);
      Gsm.println();
      delay(10000);
    }

    if (!callMade) {
      // Make a call to the specified phone number
      Gsm.println("ATD+919809143000;");
      callMade = true; // Set the flag to indicate the call has been made
    }
  }
}