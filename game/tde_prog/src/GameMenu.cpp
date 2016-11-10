#include "GameMenu.h"

GameMenu::GameMenu()
{
	m_background.loadImage("images/menuBackground.png");
	Reset();
}


GameMenu::~GameMenu()
{
}

void GameMenu::Reset() {
	m_newGame = new Button(640, 580, 50, 100, "images/newGame.png");
	m_exit = new Button(640, 650, 50, 100, "images/exit.png");
}

void GameMenu::Update(GameManager *game) {
	
}

void GameMenu::Draw(GameManager *game) {
	m_background.draw(0,0);
	m_newGame->Draw();
	m_exit->Draw();
}