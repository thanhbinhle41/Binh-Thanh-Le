#include "Menu.h"


Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("Menu/2.otf"))
	{
		
		
	}
	
	
	


	HeroMenu.Init("kit_from_firefox.png", 4, 3, 9, 2.6);
	HeroMenu.setScale(Vector2f(3.0f, 3.0f));
	HeroMenu2.Init("ImgEnimies/1.png", 2, 3, 9, 2.6);
	HeroMenu2.setScale(Vector2f(3.0f, 3.0f));

	menu[0].setFont(font);
	menu[0].setFillColor(Color::Red);
	menu[0].setString("Play");
	//menu[0].setPosition(Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));
	menu[0].setPosition(Vector2f(width / 3 - 50.0f, 700.0f));

	menu[1].setFont(font);
	menu[1].setFillColor(Color::White);
	menu[1].setString("Options");
	//menu[1].setPosition(Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));
	menu[1].setPosition(Vector2f(width / 2 - 50.0f, 700.0f));
	

	menu[2].setFont(font);
	menu[2].setFillColor(Color::White);
	menu[2].setString("Exit");
	//menu[2].setPosition(Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));
	menu[2].setPosition(Vector2f(width*2 /3+50.0f  , 700.0f));

	selectedItemIndex = 0;
}

Menu::~Menu()
{
}

void Menu::draw(RenderWindow& window, float deltaTime)
{
	
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
	HeroMenu.Update(deltaTime, false, window);
	HeroMenu.setPosition(Vector2f(130.0f, window.getSize().y / 2));
	window.draw(this->HeroMenu);
	
	HeroMenu2.Update(deltaTime, false, window);
	HeroMenu2.setPosition(Vector2f(1200.f, window.getSize().y / 2));
	window.draw(this->HeroMenu2);

	
	
	
}

void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(Color::Red);
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setFillColor(Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(Color::Red);
	}
}

void Menu::setOptionsMenu()
{
	
	for (int i = 1; i <= 3; i++)
	{
		Texture tmp;
		string s= "ImgBack/Back/" + to_string(i)+".png";
		tmp.loadFromFile(s);
		cout << s << endl;
		/*RectangleShape tmp2;
		tmp2.setTexture(&tmp);*/
		//BGs[i]->setTexture(&tmp);
		//BGs[i]->setSize(Vector2f(200.0f, 100.0f));
	}
	/*BGs[1]->setPosition(Vector2f(100.0f, 200.0f));
	BGs[2]->setPosition(Vector2f(200.0f, 200.0f));
	BGs[3]->setPosition(Vector2f(300.0f, 200.0f));*/
	
}

void Menu::drawOptions(RenderWindow& window)
{
	/*for (int i = 1; i <= 3; i++)
	{
		window.draw(*BGs[i]);
	}*/
}
