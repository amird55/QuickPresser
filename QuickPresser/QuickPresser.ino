/*
 Name:		QuickPresser.ino
 Created:	4/12/2021 7:38:16 PM
 Author:	amird
*/

// the setup function runs once when you press reset or power the board
void setup() {
	setup_7seg();
	rgb_setup();
	setup_controller();
	startWaitingForNewGame();
}

// the loop function runs over and over again until power down or reset
void loop() {
	gameManager_SM();
	//Serial.println(digitalRead(2));
}
