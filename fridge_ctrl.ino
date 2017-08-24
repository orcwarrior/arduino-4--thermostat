#include "src/modules/EventsManager/EventsManager.h"
#include "src/modules/tempSensor/tempSensor.h"
										   
#include "src/printTemperature.h"
#include "src/modules/AM2320/AM2320.h"
#include <Adafruit_SSD1306.h>
#include <gfxfont.h>
#include <Adafruit_GFX.h>

#include <SPI.h>
#include <Wire.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2


#define LOGO16_GLCD_HEIGHT 16
#define LOGO16_GLCD_WIDTH  16


// Sensor stuff:

int sensorPin = A0;    // select the input pin for the potentiometer
int ledPin = 13;      // select the pin for the LED
int potSensorValue = 0;  // variable to store the value coming from the sensor

#if (SSD1306_LCDHEIGHT != 32)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif


AM2320 tempSensor;
const int tempSensorPin = 4; // D4
const float TEMPSENSOR_ERROR = -3.5;

class ITest {
	
};

void setup()   {
	Serial.begin(9600);
	// Sensor:
	Wire.begin();

	// by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
	display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x32)
	display.dim(false);
	display.ssd1306_command(SSD1306_SETCONTRAST);                   // 0x81
	display.ssd1306_command(0x8A);
	// Show image buffer on the display hardware.
	// Since the buffer is intialized with an Adafruit splashscreen
	// internally, this will display the splashscreen.
	display.display();
	delay(100);
	// Clear the buffer.
	display.clearDisplay();
}

void loop() {

	// Temperature set by pot:
	potSensorValue = analogRead(sensorPin);
	double actualTemp = getSensorTemp(potSensorValue);
	display.setTextColor(WHITE);
	// Display set temp:
	// display.setCursor(0,2);
	// display.print(actualTemp, 1);
	// display.print(CHAR_DEGREE); //display.print("C");
	display.clearDisplay();
	printTemperature(display, actualTemp, 3, "SET");
	
	
	// Measure temp:
	int tempSensorResponse = tempSensor.Read();
	char sensorString[ ] = "OFF";
	if (tempSensorResponse == 1) {
		// Reset sensor:
		int sensorState = digitalRead(tempSensorPin);
		int newSensorState = (sensorState==LOW) ? HIGH : LOW;
		
		display.setCursor(1,60);
		display.print("reseting...");
		// digitalWrite(tempSensorPin, !sensorState);
		delay(900);
	}
	if (tempSensorResponse == 2) strcpy(sensorString, "CRCERR");
	else if (tempSensorResponse == 0) {
		printTemperature(display, tempSensor.t + TEMPSENSOR_ERROR, 43, "ACTUAL");
	}
	if (tempSensorResponse) {
		display.setCursor(1,44);
		display.print(sensorString);
	}
	display.setCursor(1, 84);
	display.print(tempSensor.h);
	
	
	display.drawCircle(15, 112, 15, WHITE);
	
	display.display();
	
}

void voidPtrCastingTest() {
	Serial.println("Testing serial starts:");
	float something = 3.0413;
	int sth2 = 12345;
	const char* sth3 = "Hi there!";
	
	void* ptrVoid =	 &something;
	void* ptrVoid2 = &sth2;
	void* ptrVoid3 = &sth3;
	
	float* ptrFloat = (float*) ptrVoid;
	int* ptrInt = (int*) ptrVoid2;
	char **ptrChar = reinterpret_cast<char**>(ptrVoid3);
	Serial.print("ptrVoid: "); Serial.println(*(unsigned int*)ptrVoid);
	Serial.print("ptrVoid2: "); Serial.println(*(unsigned int*)ptrVoid2);
	Serial.print("ptrVoid3: "); Serial.println(*(unsigned int*)ptrVoid3);
	//
	Serial.print("Ptr-void=>float addr/val: "); Serial.print(*(unsigned int*)(void*)ptrFloat);
	Serial.print("/"); Serial.println(*ptrFloat);
	//
	Serial.print("Ptr-void2=>int addr/val/var: "); Serial.print(*(int*)(void*)ptrInt);
	Serial.print("/"); Serial.print(*ptrInt);
	
	Serial.print("Ptr-void3=>int addr/val/var: "); Serial.print(*(int*)(void*)ptrChar);
	Serial.print("/"); Serial.print(*ptrChar);
	Serial.println("End of conversions test");
	
	// Testing serial starts:
	// ptrVoid: 42153
	// ptrVoid2: 12345
	// ptrVoid3: 937
	// Ptr-void=>float addr/val: 42153/3.04
	// Ptr-void2=>int addr/val/var: 12345/12345Ptr-void3=>int addr/val/var: 937/Hi there!End of conversions test
}

double getSensorTemp(int sensorRawValue) {
	const int maxOffValue = 7; // Used 500k pot (whuut?) is quite noisy...
	const int maxTemperature = 13 * 10 + 7; // one after decimal point precision
	if (sensorRawValue <= maxOffValue)
	return -9999;
	else
	return  0.1 * (maxTemperature - sensorRawValue / 9);
}