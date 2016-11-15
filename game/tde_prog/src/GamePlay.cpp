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

	// Teemo andando ao clicar com botão direito
	teemo->SetDirection(teemo->GetDestiny() - teemo->GetPosition());
	teemo->SetSpeed(teemo->GetDirection().normalize());

	if (teemo->GetDestiny().distance(teemo->GetPosition()) > 5)
		teemo->SetPosition(teemo->GetPosition() + teemo->GetSpeed() * 2);

	// Teemo deveria olhar pra onde é clicado
	if (teemo->GetAngle() != teemo->GetNextAngle())
		if (teemo->GetAngle() < teemo->GetNextAngle()) {
			teemo->SetAngle(teemo->GetAngle() + 1);

			if (teemo->GetAngle() > teemo->GetNextAngle())
				teemo->SetAngle(teemo->GetNextAngle());
			else
				teemo->SetAngle(teemo->GetAngle());
		}
		else {
			teemo->SetAngle(teemo->GetAngle() - 1);

			if (teemo->GetAngle() < teemo->GetNextAngle())
				teemo->SetAngle(teemo->GetNextAngle());
			else
				teemo->SetAngle(teemo->GetAngle());
		}
	

	//----------------------------

	teemo->Update(game);
}

void GamePlay::MousePressed(int x, int y, int btn)
{
	if (btn == OF_MOUSE_BUTTON_3)
		teemo->SetDestiny(ofVec2f(ofGetMouseX(), ofGetMouseY()));

	//----------------

	teemo->SetDistance(teemo->GetDestiny() - teemo->GetCenter());
	teemo->SetNextAngle(ofRadToDeg(atan2f(teemo->GetDistance().x, teemo->GetDistance().y)));
}

void GamePlay::Draw(GameManager *game) {
	m_background.draw(0, 0);
	teemo->Draw();

	ofPushMatrix();
	ofTranslate(teemo->GetCenter());
	ofRotateZ(teemo->GetAngle() - 90);
	ofPopMatrix();
}
