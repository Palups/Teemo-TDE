#pragma once

#include "ofMain.h"
#include "GameManager.h"
#include "Camera.h"

class Teemo
{
private:
	ofVec2f m_position;
	ofVec2f m_direction;
	ofVec2f m_speed;
	ofVec2f m_destiny;

	float m_hp, m_mana;
	ofImage m_image;
public:
	Teemo();
	~Teemo();

	void Update(GameManager *game);
	void Draw(ofVec2f camera);
	void Reset();

	void SetPosition(ofVec2f position);
	void SetDirection(ofVec2f direction);
	void SetSpeed(ofVec2f speed);
	void SetDestiny(ofVec2f destiny);

	ofVec2f GetPosition();
	ofVec2f GetDirection();
	ofVec2f GetSpeed();
	ofVec2f GetDestiny();

	float GetHp();
	float GetMana();
};

