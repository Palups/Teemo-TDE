#pragma once

#include "ofMain.h"
#include "Button.h"
#include "Teemo.h"

#define GAME_MENU 0
#define GAME_PLAY 1
#define GAME_OVER 2
#define GAME_RESET 3

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

#define ON true
#define OFF false

class GameManager
{
private:
	ofImage m_background;
	ofImage m_mouse;

	int m_gameState;
	Teemo *teemo;
public:
	ofVec2f posMouse;

	void Update();
	void Draw();
	
	GameManager(int gameState);
	~GameManager();

	void MousePressed(int x, int y, int btn);

	void SetGameState(int gameState);
	int GetGameState();
};

