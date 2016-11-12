#pragma once

#include "ofMain.h"
#include "GameManager.h"

class Teemo
{
private:
	ofVec2f m_position;

	float m_hp, m_mana, distance;

	ofImage m_image;

public:
	Teemo();
	~Teemo();

	void Update(GameManager *game);
	void Draw();
	void Reset();
};

