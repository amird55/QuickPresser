int BreakLong_min = 1400;
int BreakLong_max = 2400;
int LightLong_min = 400;
int LightLong_max = 600;

int sectionLong;
long sectionStartTime;
bool sectionIsBreak;
int sectionColor;

long gameLong = 60000;
long gameStartTime;
int gameScore;

void StartGame() {
	gameStartTime = millis();
	gameScore = 0;
}
void FinishGame() {
	showColor(NONE);
}
void gameManager() {
	showNum(gameScore, 50);
	if (millis() - gameStartTime >= gameLong) {
		FinishGame();
	}
	else {
		if (isRedBtnPressed()) {
			if (!sectionIsBreak && sectionColor == RED) {
				goodAns();
			}
			else {
				wrongAns();
			}
		}
		if (isGreenBtnPressed()) {
			if (!sectionIsBreak && sectionColor == GREEN) {
				goodAns();
			}
			else {
				wrongAns();
			}
		}
		if (millis() - sectionStartTime >= sectionLong) {
			if (sectionIsBreak) {
				chooseColor();
				showColor(sectionColor);
			}
			else {
				setBreak();
				showColor(NONE);
			}
		}
	}
}
void chooseColor() {
	sectionLong = random(LightLong_min, LightLong_max);
	sectionColor = random(1, 3);//only 2 colors
	sectionIsBreak = false;
	sectionStartTime = millis();
}
void setBreak() {
	sectionLong = random(BreakLong_min, BreakLong_max);
	sectionColor = 0;
	sectionIsBreak = true;
	sectionStartTime = millis();
}
void goodAns() {
	showColor(NONE);
	gameScore++;
	showControllerLight_Green(200);
	setBreak();
}
void wrongAns() {
	showColor(NONE);
	if (gameScore > 0) {
		gameScore--;
	}
	showControllerLight_Red(1000);
	setBreak();
}
