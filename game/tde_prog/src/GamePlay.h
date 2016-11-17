#pragma once

#include "ofMain.h"
#include "GameManager.h"
#include "Teemo.h"
#include "HUD.h"

class GamePlay
{
private:
	ofImage m_background;
	Teemo *teemo;
	HUD *hud;
public:
	GamePlay(GameManager *game);
	~GamePlay();

	void MousePressed(int x, int y, int btn);

	void Update(GameManager *game);
	void Draw(GameManager *game);
	void Reset(GameManager *game);
};

