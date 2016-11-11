#include "GameManager.h"

GameManager::GameManager(int gameState)
{
	m_gameState = gameState;
	m_mouse.loadImage("images/mouse.png");
}


GameManager::~GameManager()
{
}

void GameManager::Draw() {
	m_mouse.draw(ofGetMouseX(), ofGetMouseY());
}

void GameManager::SetGameState(int gameState) {
	m_gameState = gameState;
}

int GameManager::GetGameState() {
	return m_gameState;
}

void GameManager::Update() {
	posMouse.set(ofGetMouseX(), ofGetMouseY());
}

void GameManager::MousePressed(int x, int y, int btn)
{
	if (btn == OF_MOUSE_BUTTON_3)
		teemo->SetDirTeemo(posMouse - teemo->GetPosTeemo());
		teemo->GetDirTeemo.normalize();
}