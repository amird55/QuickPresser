/*
 Name:		QuickPresser.ino
 Created:	4/12/2021 7:38:16 PM
 Author:	amird
*/

// the setup function runs once when you press reset or power the board
void setup() {
	//pinMode(12, INPUT_PULLUP);
	//pinMode(2, INPUT_PULLUP);
	setup_7seg();
	showNum(555, 1000);
	rgb_setup();
	setup_controller();
	StartGame();
	//pinMode(3, OUTPUT);
	//pinMode(4, OUTPUT);
	//digitalWrite(3, HIGH);
	//digitalWrite(4, HIGH);
	//Serial.begin(9600);
}

// the loop function runs over and over again until power down or reset
void loop() {
	gameManager();
	//Serial.println(digitalRead(2));
}
