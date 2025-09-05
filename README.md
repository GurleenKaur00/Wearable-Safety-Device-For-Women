
Women often face safety concerns when traveling alone or in unfamiliar areas.
Existing solutions may not provide real-time location tracking or reliable communication during emergencies.
Also in these situations they get no time to call a person or send location immediately through mobile phone or smartwatch.
Our wearable safety device leverages GPS and GSM technology to send accurate location data to a designated emergency contact, enabling quick assistance in case of danger.

COMPONENTS USED
Arduino Nano
NEO-6M GPS Module
SIM800L GSM Module
Trigger Button
Microphone on GSM Module
Bread Board

CONNECTIONS USED 
SIM 800L GSM MODULE
VCC --> 5v (ARDUINO NANO)
RXD --> D9 (ARDUINO NANO)
TXD --> D8 (ARDUINO NANO)
GND --> GND (ARDUINO NANO)
MICP --> MICROPHONE
MICN --> MICROPHONE

GPS NEO 6M
VCC --> 5v (ARDUINO NANO)
RXD --> D11 (ARDUINO NANO)
TXD --> D10 (ARDUINO NANO)
GND --> GND (ARDUINO NANO)

ARDUINO NANO
5v --> TRIGGER BUTTON
D3 --> TRIGGER BUTTON
VIN --> CELLS
GND --> CELLS
RESISTOR BETWEEN GND(ARDUINO NANO) AND TRIGGER BUTTON(D3 SIDE)

WORKING 
First of all code is uploaded to ARDUINO NANO using ARDUINO IDE SOFTWARE. Then power supply is given to ARDUINO NANO using lithium cells. When trigger button is pressed, ARDUINO retrieves live location from GPS NEO 6M.
The retrieved location is sent to registered mobile number via SMS using SIM 800L GSM MODULE. The operator at registered mobile number can click on location sent via SMS to open live location of devicde and can track the person in need. 
Also a call is sent to same number. Through this call live audio can be heard by person at registered mobile number with the use of MICROPHONE. He/She can record this call for further use like to hand it over to police for evidences, etc.


FEATURES OF EMERGENCY WEARABLE DEVICE
Real-Time Location Sharing: The device provides real-time GPS location updates.
Audio Call Capability: It enables audio communication through GSM.
Single Trigger Button: All functions are initiated by a discreet single button which is hidden and with single trigger ensuring quick actions.Hidden Design: The primary feature is hidden, ensuring discreet use in emergencies
