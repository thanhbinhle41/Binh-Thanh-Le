#pragma once
#include "Player.h"
#include <iostream>
#include <vector>
#include <string>

using namespace sf;
using namespace std;

class Enimies:public Player
{
private:
	Player player1;
	Animation animation;
	bool faceRight;
	bool autoF;
	string nameImg;

public:
	Enimies();
	~Enimies();

	
	void faceRightE(Vector2f);
	void autoFire(string nameImg, float deltaTime, RenderWindow& window);
	void Spawn(int dem);
	Skill skill;
	void setNameImg(string);
	string getNameImg();
}; 

