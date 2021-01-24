#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;
using namespace sf;

#define MAX_NUMBER_OF_ITEMS 3


class Menu
{
public:
	Menu(float width, float height);
	~Menu();

	void draw(RenderWindow& window,float);
	void MoveUp();
	void MoveDown();

	int GetPressedItem() { return selectedItemIndex; }

	void setOptionsMenu();

	void drawOptions(RenderWindow&);


private:
	int selectedItemIndex;
	Font font;
	Text menu[MAX_NUMBER_OF_ITEMS]; 
	RectangleShape backGround;
	Player HeroMenu,HeroMenu2;
	//vector <RectangleShape> BGs;
	RectangleShape* BGs[4];
	
};

 