#define LedPin_R    6
#define LedPin_G    9
#define LedPin_B    10
#define NumberOfLedPins	3
int RGB_led_pins[NumberOfLedPins] = { LedPin_R,LedPin_G,LedPin_B };

#define NONE	0
#define RED		1
#define GREEN	2
#define BLUE	3
#define YELLOW	4
int colors[5][NumberOfLedPins] = {
	{0,0,0},
	{255,0,0},
	{0,255,0},
	{0,0,255},
	{255,255,0}
};
void rgb_setup() {
	for (byte k = 0; k < NumberOfLedPins; k++) {
		pinMode(RGB_led_pins[k], OUTPUT);
	}
}
void showColor(int idx) {
	for (byte k = 0; k < NumberOfLedPins; k++) {
		analogWrite(RGB_led_pins[k], colors[idx][k]);
	}
}

