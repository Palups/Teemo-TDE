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
	camera.Reset(ofVec2f (m_background.getWidth(), m_background.getHeight()));  //do caralho isso aqui
}

void GamePlay::Update(GameManager *game) {
	teemo->Update(game);
	hud->Update(game, teemo);
	camera.Update(teemo->GetPosition()); //do caralho isso aqui tb
}

void GamePlay::MousePressed(int x, int y, int btn)
{
	if (btn == OF_MOUSE_BUTTON_3)
		teemo->SetDestiny(ofVec2f(ofGetMouseX(), ofGetMouseY()));
	
}

void GamePlay::Draw(GameManager *game) {
	m_background.draw(-camera.GetPosCamera()); //que coisa bizarra
	teemo->Draw(camera.GetPosCamera());
	hud->Draw(teemo, camera.GetPosCamera());
}
