#include "BackGround.h"

BackGround::BackGround()
{

}

BackGround::~BackGround()
{
}

void BackGround::LoadFile(string fileName)
{
	text.loadFromFile(fileName);
	s1.setTexture(&text);
	s2.setTexture(&text);
	
	s1.setSize(sf::Vector2f(1300, 800));
	s2.setSize(sf::Vector2f(1300, 800));

	s1.setPosition(Vector2f(0, 0));
	s2.setPosition(Vector2f(s1.getSize().x, 0));
}

void BackGround::Update(float deltaTime)
{
	s1.move(-speed*deltaTime, 0);
	s2.move(-speed * deltaTime, 0);
	if (s2.getPosition().x <= 0.f)
	{
		s1.setPosition(Vector2f(0, 0));
		s2.setPosition(Vector2f(s1.getSize().x, 0));
	}
}

void BackGround::Draw(RenderWindow& window)
{
	window.draw(s1);
	window.draw(s2);
}

void BackGround::GameOver(RenderWindow& window)
{
	Texture tmp;
	tmp.loadFromFile("Menu/GameOver.png");
	RectangleShape GO((Vector2f)window.getSize());
	GO.setTexture(&tmp);
	window.draw(GO);
}
