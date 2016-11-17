#include "GamePlay.h"

GamePlay::GamePlay(GameManager *game)
{
	m_background.loadImage("images/gamePlayBackground.png");

	teemo = new Teemo();  //Criar Teemo
	hud = new HUD(); //Criar HUD

	//caminho dos waypoints
	m_way1.push_back(ofVec2f(m_background.getWidth() / 2 + 35, 500));
	m_way1.push_back(ofVec2f(m_background.getWidth() / 2 + 75, 500));
	m_way1.push_back(ofVec2f(m_background.getWidth() / 2 + 185, 500));
	m_way1.push_back(ofVec2f(m_background.getWidth() / 2 + 295, 500));

	m_way2.push_back(ofVec2f(m_background.getWidth() / 2 + 35, 300));
	m_way2.push_back(ofVec2f(m_background.getWidth() / 2 + 75, 300));
	m_way2.push_back(ofVec2f(m_background.getWidth() / 2 + 185, 300));
	m_way2.push_back(ofVec2f(m_background.getWidth() / 2 + 295, 300));
	//-------------------------

	count = 0.0f;

	Reset(game);
}


GamePlay::~GamePlay()
{
}

void GamePlay::Reset(GameManager *game) {
	teemo->Reset();
	hud->Reset();
	camera.Reset(ofVec2f (m_background.getWidth(), m_background.getHeight()));  //do caralho isso aqui
	minion->Reset();
}

void GamePlay::Update(GameManager *game) {
	teemo->Update(game);
	hud->Update(game, teemo);
	camera.Update(teemo->GetPosition()); //do caralho isso aqui tb

	count += ofGetLastFrameTime();

	if (count > 5) {
		int random = rand() % 2;
		minion = new Minion(random == 0 ? m_way1 : m_way2);
		minion->Update(game);
		count = 0;
	}
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
	minion->Draw(camera.GetPosCamera());
}
