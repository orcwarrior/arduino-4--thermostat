//
//
//
								
#include "printTemperature.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

const char CHAR_DEGREE = (char)247;		  

void _printOFFTemperature(Adafruit_GFX &display, int row, const char* caption) {
					 display.setTextColor(WHITE);
					 display.setTextSize(2);
					 display.setCursor(4, row);
					 display.print("O");
					 display.setTextSize(1);
					 display.setTextWrap(false);
					 display.setCursor(16, row+7);
					 display.print("FF");						 	
}

void printTemperature(Adafruit_GFX &display, double temp, int row, const char* caption = "") {
	if (temp == TEMP_OFF) {
		_printOFFTemperature(display, row, caption);
		return;
	}
	int decPart = temp/1;
	char decimalPart[3];
	char fractionalPart[3];
	
	if (decPart < 10)
	sprintf(decimalPart, " %d", decPart);
	else
	sprintf(decimalPart, "%d", decPart);
	sprintf(fractionalPart, "%d", (int)((temp-decPart)*10));
	display.setTextColor(WHITE);
	display.setTextSize(2);
	display.setCursor(-1, row);
	display.print(decimalPart);
	
	display.drawCircle(25, row-1, 2, WHITE); // Degree sign
	display.fillCircle(23, row+14, 1, WHITE); // Number point

	display.setTextSize(1);
	display.setTextWrap(false);
	display.setCursor(27, row+7);
	display.print(fractionalPart);

	display.setCursor(0, row+20);
//	display.setTextColor(BLACK, WHITE);
	display.print(caption);
//	display.setTextColor(WHITE);
}