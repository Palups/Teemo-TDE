#include "GamePlay.h"

GamePlay::GamePlay(GameManager *game)
{
	m_background.loadImage("images/gamePlayBackground.png");

	teemo = new Teemo();  //Criar Teemo

	Reset(game);
}


GamePlay::~GamePlay()
{
}

void GamePlay::Reset(GameManager *game) {
	teemo->Reset();
}

void GamePlay::Update(GameManager *game) {
	teemo->SetDirection(teemo->GetDestiny() - teemo->GetPosition());
	teemo->SetSpeed(teemo->GetDirection().normalize());

	if (teemo->GetDestiny().distance(teemo->GetPosition()) > 5)
		teemo->SetPosition(teemo->GetPosition() + teemo->GetSpeed() * 2);

	teemo->Update(game);
}

void GamePlay::MousePressed(int x, int y, int btn)
{
	if (btn == OF_MOUSE_BUTTON_3)
		teemo->SetDestiny(ofVec2f(ofGetMouseX(), ofGetMouseY()));
		
}

void GamePlay::Draw(GameManager *game) {
	m_background.draw(0, 0);
	teemo->Draw();
}
