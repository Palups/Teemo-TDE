#pragma once

#include "GameManager.h"
#include "Teemo.h"

class Camera
{
private:
	ofVec2f m_screenCenter;
	ofVec2f m_posCamera;

	float m_maxX, m_maxY;
public:
	Camera(ofVec2f background);
	~Camera();

	void Update(ofVec2f player);

	ofVec2f GetPosition();
};

