#include "Button.h"

Button::Button(int posX, int posY, int height, int width, std::string path)
{
	m_posX = posX;
	m_posY = posY;
	m_height = height;
	m_width = width;
	m_image.loadImage(path);
}


Button::~Button()
{
}

void Button::draw() {
	m_image.draw(m_posX, m_posY);
}
