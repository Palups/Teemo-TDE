#pragma once

#include "GameManager.h"
#include "Teemo.h"

class HUD
{
private:
	int m_posX, m_posY;
	int m_width, m_height;
	ofImage m_background;

	ofTrueTypeFont m_life;
	ofTrueTypeFont m_mana;
	ofTrueTypeFont m_timer;
public:
	HUD();
	~HUD();

	void Update(GameManager *game, Teemo *teemo);
	void Draw(Teemo *teemo);
	void Reset();
};

