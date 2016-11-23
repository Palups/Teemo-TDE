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
	m_position.set(0, 400);
	m_destiny.set(0, 400);
	m_hp = 515.76f;
	m_mana = 267.20f;
	m_scalar = 2;
	m_duracao = 0.0f;
	m_skillW = false;
}

void Teemo::Update(GameManager *game) {
	m_direction = m_destiny - m_position;
	m_speed = m_direction.normalize();

	if (m_destiny.distance(m_position) > 5)
		m_position += m_speed * m_scalar;

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
}

void Teemo::Draw(const ofVec2f& camera) {
	m_image.draw(m_position - camera);   //tive que tirar essa subtração da câmera
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

