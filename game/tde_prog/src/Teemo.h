#pragma once

#include "ofMain.h"
#include "GameManager.h"

class Teemo
{
private:
	int m_posX, m_posY;
	float m_hp, m_mana, distance;
	ofImage m_image;
public:
	Teemo(int posX, int posY);
	~Teemo();

	void Update(GameManager *game);
	void Draw();
	void Reset();
};

