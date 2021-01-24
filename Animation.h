#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
using namespace std;
using namespace sf;


class Animation
	:public sf::Drawable,public sf::Transformable
{
public:
	Animation();
	~Animation();
	Sprite* getSprite();
	void Update(const float& deltatime, bool faceRight);
	void Init(const std::string& name, unsigned int act, unsigned int row, unsigned int col);
	Vector2f getSize() { return m_Size; };

protected:
	float m_framTime;	// thoi gian chuyen hinh anh
	sf::Vector2u m_currentFrame;	// vi tri frame hien tai
	float m_currentTime; // dem thoi gian 

	sf::Vector2f m_Size;	// kich thuong nhan vat
	sf::Vector2i m_posUV;

private:
	sf::Sprite* m_Sprite;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		states.transform *= getTransform();
		target.draw(*m_Sprite, states);
	}

};

// setorgin sizeeffect*0.5

// set position player - player.getsize.x/2 - effect.getsize.x/2;
/*
	
	 vector Image effect
	 4 ims 

*/
