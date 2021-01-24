#pragma once
#include"SFML/Graphics.hpp"
#include<vector>
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
using namespace sf;
class Skill :public Transformable
{
private:
	vector<Texture> listTexture;
	int index;
	float totaltime, switchtime;
	RectangleShape Body;
	Vector2f m_Size;
	Sprite skill;
	Vector2f velocity;
	float speed;

	bool displ;

	bool faceRight;
	

public:
	Skill();
	~Skill();

	void setListTexture();

	void update(float);

	void draw(RenderWindow&);

	RectangleShape* getBody();

	void setBegin(Vector2f Begin,bool faceRight);
	
	void setDispl(bool displ);
	bool getDispl();

	
	
};
