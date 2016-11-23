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
	m_newGame = new Button(350, 600, 72, 257, "images/newGame.png");
	m_exit = new Button(650, 600, 72, 257, "images/exit.png");
}

void GameMenu::MousePressed(int x, int y, int btn, GameManager *game)
{
	if (x > 350 && x < 607 && y > 600 && y < 672 && btn == OF_MOUSE_BUTTON_1)
		game->SetGameState(GAME_PLAY);

	if (x > 650 && x < 907 && y > 600 && y < 672 && btn == OF_MOUSE_BUTTON_1)
		std::exit(0);
}

void GameMenu::Update(GameManager *game) {
	
}

void GameMenu::Draw(GameManager *game) {
	m_background.draw(0,0);
	m_newGame->Draw();
	m_exit->Draw();
}