#pragma once

#include "ofMain.h"
#include "GameManager.h"

class Teemo
{
private:
	ofVec2f m_position;
	ofVec2f m_direction;
	ofVec2f m_speed;
	ofVec2f m_destiny;

	int m_scalar;

	bool m_skillW; //controla a skill
	bool m_invisible, m_moving;

	float m_hp, m_mana, m_duracao, m_timerRegen, m_mouseTimer;

	ofImage m_image;
public:
	Teemo();
	~Teemo();

	void Movement();
	void Skill_W();

	void Update(GameManager *game);
	void Draw(const ofVec2f& camera);
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

