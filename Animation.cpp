#include "Animation.h"
#include <iostream>
Animation::Animation()
{
	m_currentFrame = sf::Vector2u(0, 0);
	m_posUV = sf::Vector2i(0, 0);
}

Animation::~Animation()
{
	if (m_Sprite != nullptr)
	{
		//delete m_Sprite;
		//m_Sprite = nullptr;
	}
}

void Animation::Update(const float& deltatime, bool faceRight)
{
	m_currentTime += deltatime;
	if (m_currentTime >= m_framTime)
	{
		m_currentFrame.x++;
		if (m_currentFrame.x == 3)
		{
			m_currentFrame.x = 0;
		}
		m_currentTime -= m_framTime;
	}
	//m_posUV.x = m_currentFrame.x * m_Size.x;

	m_posUV.y = m_currentFrame.y * m_Size.y;
	m_Sprite->setTextureRect(sf::IntRect(m_posUV, (sf::Vector2i)m_Size));

	if (faceRight)
	{
		m_posUV.x = m_currentFrame.x * m_Size.x;
		m_Size.x = abs(m_Size.x);
	}
	else
	{
		m_posUV.x = (m_currentFrame.x + 1) * abs(m_Size.x);
		m_Size.x = -abs(m_Size.x);
	}
}

void Animation::Init(const std::string& name, unsigned int act, unsigned int col, unsigned int row)
{
	m_currentFrame.y = act;
	m_framTime = 0.3f;
	m_Sprite = new sf::Sprite();
	sf::Texture* texture;
	texture = new sf::Texture();
	texture->loadFromFile(name);

	m_Sprite->setTexture(*texture);
	m_Size = sf::Vector2f(texture->getSize().x / col, texture->getSize().y / row);
}

Sprite* Animation::getSprite() {
	return m_Sprite;
}






