#define pinBtn_R 2
#define pinBtn_G 12
#define pinControllerLed_R 3
#define pinControllerLed_G 4

struct FullBtnData {
	int Pin;
	bool isPressed;
};
FullBtnData BtnRed   = { pinBtn_R,false };
FullBtnData BtnGreen = { pinBtn_G,false };

void setup_controller() {
	pinMode(BtnGreen.Pin, INPUT_PULLUP);
	pinMode(BtnRed.Pin, INPUT_PULLUP);
	pinMode(pinControllerLed_G, OUTPUT);
	pinMode(pinControllerLed_R, OUTPUT);
}
bool isRedBtnPressed() {
	bool ret = false;
	int val = digitalRead(BtnRed.Pin);
	if (val == LOW) {
		if (!BtnRed.isPressed) {
			ret = true;
		}
		BtnRed.isPressed = true;
	}
	else {
		BtnRed.isPressed = false;
	}
	Serial.println("isRedBtnPressed:: pin=" + String(BtnRed.Pin) + "  ret=" + String(ret));
	return ret;
}
bool isGreenBtnPressed() {
	bool ret = false;
	if (digitalRead(BtnGreen.Pin) == LOW) {
		if (!BtnGreen.isPressed) {
			ret = true;
		}
		BtnGreen.isPressed = true;
	}
	else {
		BtnGreen.isPressed = false;
	}
	return ret;
}
void showControllerLight_Green(int prd) {
	digitalWrite(pinControllerLed_G, HIGH);
	delay(prd);
	digitalWrite(pinControllerLed_G, LOW);
}
void showControllerLight_Red(int prd) {
	digitalWrite(pinControllerLed_R, HIGH);
	delay(prd);
	digitalWrite(pinControllerLed_R, LOW);
}
