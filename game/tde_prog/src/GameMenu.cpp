#include "GameMenu.h"

GameMenu::GameMenu()
{
	m_background.loadImage("images/menuBackground.png");
	reset();
}


GameMenu::~GameMenu()
{
}

void GameMenu::reset() {
	m_newGame = new Button(500, 300, 50, 100, "images/newGame.png");
	m_exit = new Button(500, 500, 50, 100, "images/exit.png");
}

void GameMenu::update(GameManager *game) {

}

void GameMenu::draw(GameManager *game) {
	m_newGame->draw();
	m_exit->draw();
}