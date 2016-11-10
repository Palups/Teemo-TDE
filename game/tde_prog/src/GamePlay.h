#pragma once

#include "ofMain.h"
#include "GameManager.h"

class GamePlay
{
private:
	ofImage m_background;
public:
	GamePlay(GameManager *game);
	~GamePlay();

	void Update(GameManager *game);
	void Draw(GameManager *game);
	void Reset(GameManager *game);
};

