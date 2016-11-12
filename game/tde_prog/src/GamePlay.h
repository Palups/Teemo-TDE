#pragma once

#include "ofMain.h"
#include "GameManager.h"
#include "Teemo.h"

class GamePlay
{
private:
	ofImage m_background;
	Teemo *teemo;
public:
	GamePlay(GameManager *game);
	~GamePlay();

	void MousePressed(int x, int y, int btn);

	void Update(GameManager *game);
	void Draw(GameManager *game);
	void Reset(GameManager *game);
};

