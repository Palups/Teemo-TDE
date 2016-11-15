#include "HUD.h"

HUD::HUD()
{
	m_background.loadImage("images/hud_background.png");
	Reset();
}

HUD::~HUD()
{
}

void HUD::Reset()
{
	m_posX = 0;
	m_posY = 0;
	m_width = 1280;
	m_height = 50;
}

void HUD::Update(GameManager *game, Teemo *teemo)
{
	teemo->GetHp();
	teemo->GetMana();
}

void HUD::Draw(Teemo *teemo)
{
	m_background.draw(m_posX, m_posY);

	ofSetColor(ofColor::white);
	ofDrawBitmapString("HP: " + ofToString(teemo->GetHp()), 10, 30);

	ofSetColor(ofColor::white);
	ofDrawBitmapString("Mana: " + ofToString(teemo->GetMana()), 200, 30);

	string fpsStr = "FPS: " + ofToString(ofGetFrameRate(), 2);
	ofDrawBitmapString(fpsStr, 1175, 30);
}
