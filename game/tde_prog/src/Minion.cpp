#include "Minion.h"

Minion::Minion(vector <ofVec2f>& path):receiver(path)
{
	m_image.loadImage("images/minion.png");
	m_position.set(receiver[0]);
	Reset();
}

Minion::~Minion()
{
}

void Minion::Update(GameManager *game)
{
	m_destiny.set(receiver[current + 1] - m_position);
	m_position += m_destiny;

	m_size = (receiver[current + 1] - m_position).length();

	if (current + 1 != receiver.size() - 1 && m_size < 10) {
		m_position.set(receiver[current + 1]);
		current += 1;
	}
}

void Minion::Draw(const ofVec2f& camera)
{
	m_image.draw(m_position - camera);
}

void Minion::Reset()
{
	m_hp = 100.0f;
}
