#include "Teemo.h"

Teemo::Teemo()
{
	m_image.loadImage("images/teemo.png");
	m_image.setAnchorPoint(m_image.getWidth() / 2, m_image.getHeight() / 2);

	Reset();
}

Teemo::~Teemo()
{
}

void Teemo::Movement()
{
	m_direction = m_destiny - m_position;
	m_speed = m_direction.normalize();

	if (m_destiny.distance(m_position) > 5) {
		m_position += m_speed * m_scalar;
		m_moving = true;
		m_invisible = false;
	}
	else
		m_moving = false;
}

void Teemo::Skill_W()
{	
	if (m_mana >= 40) {
		m_skillW = true;
		m_scalar = 4;
		m_mana -= 40;
	}
}

void Teemo::Reset()
{
	m_position.set(50, 300);
	m_destiny.set(50, 300);
	m_hp = 515.76f;
	m_mana = 267.20f;
	m_scalar = 2;
	m_duracao = 0.0f;
	m_timerRegen = 0.0f;
	m_mouseTimer = 0.0f;
	m_skillW = false;
	m_invisible = false;
	m_moving = false;
}

void Teemo::Update(GameManager *game) {

	//movimentação do teemo
	this->Movement();

	if (m_moving == false && m_invisible == false) {
		if (m_mouseTimer >= 2.0f) {
			m_invisible = true;
			m_mouseTimer = 0.0f;
		}
		else {
			m_mouseTimer += ofGetLastFrameTime();
		}
	}
	
	//-------------------------------------

	if (m_skillW)
	{
		if (m_duracao >= 3.0f)
		{
			m_skillW = false;
			m_duracao = 0.0f;
			m_scalar = 2;
		}
		else
			m_duracao += ofGetLastFrameTime();
	}

	//--------------------------------------

	m_timerRegen += ofGetLastFrameTime();
	
	if (m_timerRegen >= 1.0f) {
		if (m_hp < 515.76f)
			m_hp += 4.65f;
		if (m_mana < 267.20f)
			m_mana += 6.45f;
		m_timerRegen = 0.0f;
	}

}

void Teemo::Draw(const ofVec2f& camera) {
	if (m_invisible) {
		ofSetColor(255, 255, 255, 50);
		m_image.draw(m_position - camera);
		ofSetColor(255, 255, 255, 255);
	}
	else {
		m_image.draw(m_position - camera);
	}
}

void Teemo::SetPosition(ofVec2f position)
{
	m_position = position;
}

void Teemo::SetDirection(ofVec2f direction)
{
	m_direction = direction;
}

void Teemo::SetSpeed(ofVec2f speed)
{
	m_speed = speed;
}

void Teemo::SetDestiny(ofVec2f destiny)
{
	m_destiny = destiny;
}

ofVec2f Teemo::GetPosition()
{
	return m_position;
}

ofVec2f Teemo::GetDirection()
{
	return m_direction;
}

ofVec2f Teemo::GetSpeed()
{
	return m_speed;
}

ofVec2f Teemo::GetDestiny()
{
	return m_destiny;
}

float Teemo::GetHp()
{
	return m_hp;
}

float Teemo::GetMana()
{
	return m_mana;
}

