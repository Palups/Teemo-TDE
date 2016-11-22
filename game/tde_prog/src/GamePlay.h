#pragma once

#include "ofMain.h"
#include "GameManager.h"
#include "Teemo.h"
#include "HUD.h"
#include "Camera.h"
#include <vector>
#include "Minion.h"

class GamePlay
{
private:
	ofImage m_background;
	Teemo *teemo;
	HUD *hud;
	Camera camera;
	Minion *minion;

	vector <ofVec2f> m_way1;
	vector <ofVec2f> m_way2;

	float count;

public:
	GamePlay(GameManager *game);
	~GamePlay();

	void MousePressed(int x, int y, int btn);
	void KeyPressed(int key);

	void Update(GameManager *game);
	void Draw(GameManager *game);
	void Reset(GameManager *game);
};

