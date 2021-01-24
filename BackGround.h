#pragma once
#include"SFML/Graphics.hpp"
#include <iostream>
using namespace std;
using namespace sf;



class BackGround
{
public:
	BackGround();
	~BackGround();

	void LoadFile(string fileName);

	void Update(float deltaTime);

	void Draw(RenderWindow&);

	void GameOver(RenderWindow&);
	

private:
	sf::RectangleShape s1, s2;
	Texture text;
	float speed = 100.0f;
};

