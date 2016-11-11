#include "Teemo.h"

Teemo::Teemo(int posX, int posY)
{
	m_posX = posX;
	m_posY = posY;
	m_image.loadImage("images/teemo.png");
	Reset();
}

Teemo::~Teemo()
{
}

void Teemo::Reset()
{
	m_hp = 515.76f;
	m_mana = 267.20f;
}

void Teemo::Update(GameManager *game) {

}

void Teemo::Draw() {
	m_image.draw(m_posX, m_posY);
}