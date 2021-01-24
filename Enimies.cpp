#include "Enimies.h"

Enimies::Enimies()
{
	faceRight = false;
	autoF = true;
	player1.Init(nameImg, 4, 3, 9, 9);
}

Enimies::~Enimies()
{
}




void Enimies::faceRightE(Vector2f HeroPos)
{
	if (this->getPosition().x < HeroPos.x)
	{
		faceRight = true;
	}
	if (this->getPosition().x > HeroPos.x)
	{
		faceRight = false;
	}
}

void Enimies::autoFire(string nameImg, float deltaTime, RenderWindow& window)
{
	if (autoF && this->getPosition().x>0.0f)
	{
		//cout << "TQ" << endl;
		skill.setDispl(true);
		//skill.setScale(Vector2f(-1.0f, 1.0f));
		skill.setBegin(this->getPosition(), this->faceRight);
		
		skill.setListTexture();
		autoF = false;
	}
	if (skill.getDispl()) 
	{
		skill.update(deltaTime);
		skill.draw(window);
	}
	if ((skill.getBody()->getPosition().x > 1500.0f || skill.getBody()->getPosition().x < -300.0f)) 
	{
		//cout << "FALSE" << endl;
		autoF = true;
		skill.setDispl(false);
	}
	player1.Update(deltaTime, false, window);
	
}

void Enimies::Spawn(int dem)
{
	std::string s = "ImgEnimies/";
	s += std::to_string(dem);
	s += ".png";
	std::cout << s << std::endl;
	//player1.Init(s, 0, 3, 9, 9);
	player1.setScale(Vector2f(2.5f, 2.5f));
	player1.setPosition(Vector2f(900.0f, 206.0f));
}


void Enimies::setNameImg(string tmp)
{
	this->nameImg = tmp;
}

string Enimies::getNameImg()
{
	return this->nameImg;
}




