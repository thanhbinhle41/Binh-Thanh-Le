 #pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include"Skill.h"
#include <iostream>
using namespace sf;
using namespace std;

class Player :public Drawable, public Transformable
{

private:
	
	Animation animation;
	float speed;
	RectangleShape Body;
	Vector2f velocity;
	float jumpHeight;
	int row,col;
	std::string nameImg;
	bool canMove;
	bool faceRight;
	bool autoFire;
	bool autoFireEn;
	bool isDead;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		states.transform *= getTransform();
		target.draw(animation, states);
		
	}


public:
	Player();
	~Player();
	bool canJump;
	
	RectangleShape getBody();
	void Update(float deltaTime, bool canMove, RenderWindow &window);
	void Init(const std::string& name, unsigned int act, int col, int row, float JumpHeight);
	void Jump();
	void Dead(float deltaTime);
	Skill skill;


	bool isD();
	
	



}; 
