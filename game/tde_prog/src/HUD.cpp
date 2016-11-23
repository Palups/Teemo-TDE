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
	m_timer = 0.0f;
}

void HUD::Update(GameManager *game, Teemo *teemo)
{
	teemo->GetHp();
	teemo->GetMana();
	m_timer += ofGetLastFrameTime();
}

void HUD::Draw(Teemo *teemo/*, const ofVec2f& camera*/)
{
	m_background.draw(m_posX/*-camera.x*/, m_posY/*-camera.y*/);

	ofSetColor(ofColor::white);
	ofDrawBitmapString("HP: " + ofToString(teemo->GetHp()) + "    ||", 25, 30);

	ofSetColor(ofColor::white);
	ofDrawBitmapString("Mana: " + ofToString(teemo->GetMana()), 175, 30);

	ofSetColor(ofColor::white);
	ofDrawBitmapString("Timer: " + ofToString(m_timer), 575, 30);

	string fpsStr = "FPS: " + ofToString(ofGetFrameRate(), 2);
	ofDrawBitmapString(fpsStr, 1080, 30);
}
