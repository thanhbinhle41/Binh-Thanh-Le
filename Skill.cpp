#include "Skill.h"

void Skill::setListTexture()
{
	this->listTexture.erase(this->listTexture.begin(), this->listTexture.end());
	srand(time(NULL));
	int ran = rand() % (11 - 1 + 1) + 1;
	string s = "Skill/";
	switch (ran)
	{
		case 1:
		{
			s += "Blood/";
			break;
		}
		case 2:
		{
			s += "Blue/";
			break;
		}
		case 3:
		{
			s += "Cosmic/";
			break;
		}
		case 4:
		{
			s += "Fire/";
			break;
		}
		case 5:
		{
			s += "Fireball/";
			break;
		}
		case 6:
		{
			s += "Gold/";
			break;
		}
		case 7:
		{
			s += "Gold/";
			break;
		}
		case 8:
		{
			s += "Light/";
			break;
		}
		case 9:
		{
			s += "Pure/";
			break;
		}
		case 10:
		{
			s += "Water/";
			break;
		}
		case 11:
		{
			s += "Arcane/";
			break;
		}
	}



	Texture texture;
	int ran2 = rand() % (5 - 1 + 1) + 1;
	for (int i = 1; i <= 5; i++) {
		texture.loadFromFile(s+ to_string(ran2) +"/Skill (" + to_string(i) + ").png");
		this->listTexture.push_back(texture);
	}



	
}

void Skill::update(float deltaTime)
{
	totaltime += deltaTime / 2.0f;
	if (totaltime >= switchtime) {
		totaltime -= switchtime;
		index++;
		if (index >= listTexture.size()) index = 0;
		skill.setTexture(listTexture[index]);
		if (this->faceRight == true)
		{
			skill.setScale(Vector2f(-1.0f, -1.0f));
		}
	}
	this->m_Size = Vector2f(listTexture[index].getSize().x, listTexture[index].getSize().y);

	if (faceRight == true)
	{
		velocity.x = speed * deltaTime*4;
	}
	else
	{
		velocity.x = -speed * deltaTime * 4;
	}
		
	

	skill.setScale(0.7f, 0.7f);

	

	skill.move(velocity);
	//Body.setSize((Vector2f)m_Size* skill.getScale().x);
	Body.setSize(Vector2f(m_Size.x  *0.5f , m_Size.y  *0.5f ));
	Body.setOrigin(Body.getSize() * 0.05f); //00.05
	Body.setPosition(skill.getPosition());
	Body.setOutlineThickness(3.f);
	Body.setOutlineColor(Color(0, 0, 0, 0));
	//Body.setOutlineColor(Color::Red);
	Body.setFillColor(Color(0, 0, 0, 0));
	

}

void Skill::draw(RenderWindow& window)
{
	if (this->displ) {
		window.draw(Body);
		window.draw(skill);
	}
}

RectangleShape* Skill::getBody()
{
	return &Body;
}

void Skill::setBegin(Vector2f Begin, bool faceRight)
{
	this->faceRight = faceRight;
	if (faceRight == false)
	{
		Begin.x -=100.0f;
	}
	this->skill.setPosition(Begin);


}

void Skill::setDispl(bool displ)
{
	this->displ = displ;

}

bool Skill::getDispl()
{
	return this->displ;
}




Skill::Skill()
{
	//skill.setPosition(400.0f, 400.0f);
	this->index = 0;
	this->totaltime = 0;
	this->switchtime = 0.1f;
	speed = 100.0f;
	//this->displ = false;
	velocity.x = 0;
	
	
}
Skill::~Skill()
{
}