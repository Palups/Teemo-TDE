#pragma once

#include "ofMain.h"
#include "Button.h"

#define GAME_MENU 0
#define GAME_PLAY 1
#define GAME_OVER 2
#define GAME_RESET 3

#define WINDOW_WIDTH 1200
#define WINDOW_HEIGHT 720

#define ON true
#define OFF false

class GameManager
{
private:
	ofImage m_background;
	ofImage m_mouse;

	ofSoundPlayer m_song;

	int m_gameState;
public:
	void Update();
	void Draw();

	GameManager(int gameState);
	~GameManager();

	void SetGameState(int gameState);
	int GetGameState();
};

