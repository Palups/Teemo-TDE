#include "Teemo.h"

Teemo::Teemo()
{
	m_image.loadImage("images/teemo.png");
	Reset();
}

Teemo::~Teemo()
{
}

void Teemo::Reset()
{
	m_position.set(0, 0);
	m_hp = 515.76f;
	m_mana = 267.20f;
}

void Teemo::Update(GameManager *game) {

}

void Teemo::Draw() {
	m_image.draw(m_position.x, m_position.y);
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

