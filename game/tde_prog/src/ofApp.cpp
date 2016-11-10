#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	//ofSetBackgroundColor(0, 0, 0);
	ofHideCursor();

	gameManager = new GameManager(GAME_MENU);
	gameMenu = new GameMenu();
}

//--------------------------------------------------------------
void ofApp::update() {
	switch (gameManager->GetGameState()) {
	case GAME_MENU:
		gameMenu->update(gameManager);
		break;
	case GAME_PLAY:
		break;
	case GAME_OVER:
		break;
	case GAME_RESET:
		gameMenu->reset();
		gameManager->SetGameState(GAME_MENU);
		break;
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	switch (gameManager->GetGameState()) {
	case GAME_MENU:
		gameMenu->draw(gameManager);
		break;
	case GAME_PLAY:
		break;
	case GAME_OVER:
		break;
	case GAME_RESET:
		break;
	}

	gameManager->draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {
	ofSetWindowShape(WINDOW_WIDTH, WINDOW_HEIGHT);
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
