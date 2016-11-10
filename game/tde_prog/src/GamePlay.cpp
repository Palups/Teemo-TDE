#include "GamePlay.h"

GamePlay::GamePlay(GameManager *game)
{
	m_background.loadImage("images/gamePlayBackground.png");
}


GamePlay::~GamePlay()
{
}

void GamePlay::Reset(GameManager *game) {

}

void GamePlay::Update(GameManager *game) {

}

void GamePlay::Draw(GameManager *game) {
	m_background.draw(0, 0);
}
