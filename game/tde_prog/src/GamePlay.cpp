#include "GamePlay.h"

GamePlay::GamePlay(GameManager *game)
{
	m_background.loadImage("images/gamePlayBackground.png");

	teemo = new Teemo();  //Criar Teemo
	hud = new HUD(); //Criar HUD

	Reset(game);
}


GamePlay::~GamePlay()
{
}

void GamePlay::Reset(GameManager *game) {
	teemo->Reset();
	hud->Reset();
}

void GamePlay::Update(GameManager *game) {

	// Teemo andando ao clicar com botão direito
	teemo->SetDirection(teemo->GetDestiny() - teemo->GetPosition());
	teemo->SetSpeed(teemo->GetDirection().normalize());

	if (teemo->GetDestiny().distance(teemo->GetPosition()) > 5)
		teemo->SetPosition(teemo->GetPosition() + teemo->GetSpeed() * 2);

	//---------------------

	teemo->Update(game);
	hud->Update(game, teemo);
}

void GamePlay::MousePressed(int x, int y, int btn)
{
	if (btn == OF_MOUSE_BUTTON_3)
		teemo->SetDestiny(ofVec2f(ofGetMouseX(), ofGetMouseY()));
	
}

void GamePlay::Draw(GameManager *game) {
	m_background.draw(0, 0);
	teemo->Draw();
	hud->Draw(teemo);
}
