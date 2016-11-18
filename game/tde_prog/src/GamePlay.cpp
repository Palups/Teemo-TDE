#include "GamePlay.h"

GamePlay::GamePlay(GameManager *game)
{
	m_background.loadImage("images/gamePlayBackground.png");

	teemo = new Teemo();  //Criar Teemo
	hud = new HUD(); //Criar HUD
	minion = nullptr;

	//caminho dos waypoints
	m_way1.push_back(ofVec2f(m_background.getWidth() / 2 + 0, 200));
	m_way1.push_back(ofVec2f(m_background.getWidth() / 2 + 50, 200));
	m_way1.push_back(ofVec2f(m_background.getWidth() / 2 + 100, 200));
	m_way1.push_back(ofVec2f(m_background.getWidth() / 2 + 150, 200));

	m_way2.push_back(ofVec2f(m_background.getWidth() / 2 + 0, 600));
	m_way2.push_back(ofVec2f(m_background.getWidth() / 2 + 50, 600));
	m_way2.push_back(ofVec2f(m_background.getWidth() / 2 + 100, 600));
	m_way2.push_back(ofVec2f(m_background.getWidth() / 2 + 150, 600));
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
}

void GamePlay::Update(GameManager *game) {
	teemo->Update(game);
	hud->Update(game, teemo);
	camera.Update(teemo->GetPosition()); //do caralho isso aqui tb

	count += ofGetLastFrameTime();

	if (count > 5) {
		int random = rand() % 2;
		minion = new Minion(random == 0 ? m_way1 : m_way2);
		minion->Reset();
		count = 0;
	}

	if (minion) 
		minion->Update(game);
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

	if (minion) 
		minion->Draw(camera.GetPosCamera());

	/*if (minion != nullptr) 
		minion->Draw(camera.GetPosCamera());*/

	for (int i = 0; i < m_way1.size(); i++) {
		ofDrawCircle(m_way1[i] - camera.GetPosCamera(), 5);
		ofDrawCircle(m_way2[i] - camera.GetPosCamera(), 5);
	}
}
