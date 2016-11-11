#include "Teemo.h"

Teemo::Teemo(int posX, int posY)
{
	m_posX = posX;
	m_posY = posY;
	m_image.loadImage("images/teemo.png");
	posTeemo.set(posX, posY);
	Reset();
}


Teemo::~Teemo()
{
}

void Teemo::Reset()
{
	m_hp = 515.76f;
	m_mana = 267.20f;
	time = ofGetLastFrameTime();
}

ofVec2f Teemo::GetPosTeemo()
{
	return posTeemo;
}

ofVec2f Teemo::GetDirTeemo()
{
	return dirTeemo;
}

ofVec2f Teemo::SetDirTeemo(ofVec2f direction)
{
	dirTeemo = direction;
}

void Teemo::Update(GameManager *game) {
	velTeemo = (game->posMouse - posTeemo);
	dirTeemo = game->posMouse;
	posTeemo = posTeemo + time * velTeemo;

	way = game->posMouse - posTeemo;
	distance = way.length();

	if (distance < 2)
		dirTeemo.set(0, 0);
}

void Teemo::Draw() {
	m_image.draw(posTeemo.x, posTeemo.y);
}
