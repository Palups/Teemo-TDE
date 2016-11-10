#pragma once

#include "ofMain.h"
#include "GameManager.h"

class GameMenu
{
private:
	ofImage m_background;

	Button *m_newGame;
	Button *m_exit;
public:
	GameMenu();
	~GameMenu();

	void update(GameManager *game);
	void draw(GameManager *game);
	void reset();
};