#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Player.h"
#include "Animation.h"
#include "Enimies.h"
#include "Menu.h"
#include "Skill.h"
#include "BackGround.h"
using namespace std;
using namespace sf;


int main()
{
	RenderWindow window(VideoMode(1300, 800), "FireFox", Style::Close | Style::Resize);
	window.setFramerateLimit(60);


	RenderWindow windowMenu(VideoMode(1300, 800),"Menu", Style::Close | Style::Resize);
	windowMenu.setFramerateLimit(60);

	// Menu
	Menu menu(windowMenu.getSize().x, window.getSize().y);
	
	
	

	const float gravity = 9.8;

	Player Hero;
	Hero.Init("kit_from_firefox.png", 0,3,9,5);
	Hero.setScale(Vector2f(1.5f, 1.5f));
	Hero.setPosition(Vector2f(206.0f, 206.0f));

	Enimies Enimie;
	Enimie.Init("ImgEnimies/1.png",0,3,9,8);
	Enimie.setScale(Vector2f(1.8f, 1.8f));
	Enimie.setPosition(Vector2f(900.0f, 206.0f)); 

	std::vector<Player> enimies;
	enimies.push_back(Enimie);
	
	
	
	Skill skill;
	

	srand(time(NULL));
	
	float deltaTime;
	sf::Clock clock;
	
	

	RectangleShape ground;
	ground.setPosition(Vector2f(0, window.getSize().y-140.0f)); //5*4
	ground.setSize(Vector2f(window.getSize().x, window.getSize().y/5));
	ground.setFillColor(Color(0,0,0,0));
	//ground.setFillColor(Color::Green);

	// test
	Texture tmp;
	tmp.loadFromFile("Menu/GameStart.jpg");
	RectangleShape MenuBack((Vector2f)windowMenu.getSize());
	MenuBack.setTexture(&tmp);
	///////
	Texture tmp2,tmp3,tmp4;
	RectangleShape Logo[4];
	tmp2.loadFromFile("ImgBack/Back/logo.png");
	Logo[1].setSize(Vector2f(110.0f, 110.0f));
	Logo[1].setTexture(&tmp2);
	Logo[1].setPosition(Vector2f(620.0f, 50.0f));

	tmp3.loadFromFile("ImgBack/Back/logo2.png");
	Logo[2].setSize(Vector2f(100.0f, 100.0f));
	Logo[2].setTexture(&tmp3);
	Logo[2].setPosition(Vector2f(620.0f-200.0f, 50.0f));

	tmp4.loadFromFile("ImgBack/Back/logo3.png");
	Logo[3].setSize(Vector2f(100.0f, 100.0f));
	Logo[3].setTexture(&tmp4);
	Logo[3].setPosition(Vector2f(620.0f+200.0f, 50.0f));

	bool Options = false;

	//Intro
	
	while (windowMenu.isOpen())
	{
		deltaTime = clock.restart().asSeconds();
		sf::Event event;
		while (windowMenu.pollEvent(event))
		{
			switch (event.type)
			{
			case Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::A:
					menu.MoveUp();
					break;
				case Keyboard::D:
					menu.MoveDown();
					break;

				case Keyboard::Space:
					switch (menu.GetPressedItem())
					{
					case 0:
						std::cout << "Play button has been pressed" << std::endl;
						windowMenu.close();
						break;
					case 1:
						std::cout << "Options button has been pressed" << std::endl;
						Options = true;
						menu.setOptionsMenu();
						break;
					case 2:
						windowMenu.close();
						break;

					}
					break;
				}


			}
		}

		windowMenu.clear(Color(150, 150, 150));

		if (!Options)
		{
			windowMenu.draw(MenuBack);
			menu.draw(windowMenu, deltaTime);
			for (int i = 1; i <= 3; i++)
			{
				windowMenu.draw(Logo[i]);
			}
				
		}
		else
		{
			menu.drawOptions(windowMenu);
		}
		
		windowMenu.display();
	}


	

	
	int dem = 1; // so thu tu cua Enime
	float spawnTime = 0.0f;
	bool isDead = false;

	BackGround BG;
	BG.LoadFile("ImgBack/Back/8.png");
	//BG.LoadFile("ImgBack/Back/2.jpg");

	bool GameOver = false;
	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();
		Event evt;

		// spawn Enimies
		if (spawnTime == 300.0f)
		{
			if (isDead == true)
			{
				float randX = rand() % (1200 - 200 + 1) + 200;
				float randY = rand() % (800 - 200 + 1) + 200;
				float randS = rand() % (4 - 1 + 1) + 1;
				std::string s = "ImgEnimies/";
				s += std::to_string(dem);
				s += ".png";
				//cout << s << endl;
				Enimie.setNameImg(s);
				Enimie.Init(s, 0, 3, 9, 8);
				Enimie.setScale(Vector2f(randS, randS));
				Enimie.setPosition(Vector2f(1200, randY));
				Enimie.canJump = true;
				isDead = false;
				//Enimie.skill.setScale(Vector2f(randS/2, randS/2));
			}
			spawnTime = 0.0f;
		}
		else spawnTime+=1.0f;


		while (window.pollEvent(evt))
		{
			switch (evt.type)
			{
			case Event::Closed:
				window.close();
				break;

			case Event::MouseButtonReleased:
				cout << "Mouse Released\n";
				break;
			case Event::KeyReleased:
				//velocity.x = 0;
				break;
			default:
				break;
			}
		}
		// Hero
		if (ground.getGlobalBounds().intersects(Hero.getBody().getGlobalBounds())) 
		{
			Hero.Jump();
		}
		 //Enimie
		if (ground.getGlobalBounds().intersects(Enimie.getBody().getGlobalBounds()))
		{
			Enimie.Jump();
		}


		// Collision
		
		if (Hero.skill.getBody()->getGlobalBounds().intersects(Enimie.getBody().getGlobalBounds()) )
		{
			
			Enimie.Dead(deltaTime);
			if (isDead == false)
			{
				isDead = true;
				dem++;
				//cout << dem << endl;
				if (dem > 6)	dem = 1;
			}
		}

		if (Enimie.getPosition().x < -100.0f)
		{
			Enimie.Dead(deltaTime);
			if (isDead == false)
			{
				isDead = true;
				dem++;
				cout << dem << endl;
				if (dem > 4)	dem = 1;
			}
			if (Hero.isD())
			{
				GameOver = true;
				
				
			}
		}

		if (Hero.getBody().getGlobalBounds().intersects(Enimie.getBody().getGlobalBounds()))
		{
			Hero.Dead(deltaTime);
		}
		if (Hero.getBody().getGlobalBounds().intersects(Enimie.skill.getBody()->getGlobalBounds()))
		{
			//Hero.Dead(deltaTime);
		}

		window.clear(Color(150, 150, 150));

		if (!GameOver)
		{
			BG.Draw(window);
			BG.Update(deltaTime);


			window.draw(ground);

			window.draw(Hero.getBody());
			Hero.Update(deltaTime, true, window);
			window.draw(Hero);

			window.draw(Enimie.getBody());
			Enimie.Update(deltaTime, false, window);
			Enimie.faceRightE(Hero.getPosition());
			Enimie.autoFire(Enimie.getNameImg(), deltaTime, window);


			window.draw(Enimie);
		}
		else
		{
			BG.GameOver(window);
		}
		
		
		
		window.display();
	}


	return 0;
}