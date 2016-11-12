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