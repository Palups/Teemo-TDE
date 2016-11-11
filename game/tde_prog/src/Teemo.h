#pragma once

#include "ofMain.h"
#include "GameManager.h"

class Teemo
{
private:
	int m_posX, m_posY;
	float m_hp, m_mana, distance;
	double time;
	ofImage m_image;
	ofVec2f posTeemo, dirTeemo, velTeemo, way;
public:
	Teemo(int posX, int posY);
	~Teemo();

	void Update(GameManager *game);
	void Draw();
	void Reset();

	ofVec2f GetPosTeemo();
	ofVec2f GetDirTeemo();
	ofVec2f SetDirTeemo(ofVec2f direction);
};

