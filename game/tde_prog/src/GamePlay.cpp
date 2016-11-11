#include "GamePlay.h"

GamePlay::GamePlay(GameManager *game)
{
	m_background.loadImage("images/gamePlayBackground.png");
	
	teemo = new Teemo(50, 50);  //Criar Teemo

	Reset(game);
}


GamePlay::~GamePlay()
{
}

void GamePlay::Reset(GameManager *game) {
	teemo->Reset();
}

void GamePlay::Update(GameManager *game) {
	

	teemo->Update(game);
}

void GamePlay::Draw(GameManager *game) {
	m_background.draw(0, 0);
	teemo->Draw();
}
