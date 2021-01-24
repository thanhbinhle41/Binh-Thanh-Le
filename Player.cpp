#include "Player.h"


Player::Player()
{
	speed = 100.0f;
	//jumpHeight = 5;
	canJump = true;
	canMove = true;
	Body.setFillColor(Color(0, 0, 0, 0));
	animation.setOrigin((Vector2f)animation.getSize()*0.5f);
	faceRight = true;
	autoFire = true;
	isDead = false;
}

Player::~Player()
{
}

void Player::Init(const std::string& name, unsigned int act,int col, int row, float jumpHeight)
{
	this->col = col;
	this->row = row;
	this->nameImg = name;
	this->jumpHeight = jumpHeight;
	animation.Init(name, act,this->col,this->row); // 3 9
	animation.setOrigin((Vector2f)animation.getSize() * 0.5f);


	/*vector<Texture> listTexture;
	Texture texture;
	for (int i = 1; i <= 5; i++) {
		texture.loadFromFile("Skill/Water/3/Skill (" + to_string(i) + ").png");
		listTexture.push_back(texture);
	}
	skill.setListTexture(listTexture);
	listTexture.clear();*/
	
}


void Player::Jump()
{
	if (canJump)
	{
		velocity.y = -sqrtf(2.0f * 9.810f * this->jumpHeight);
		animation.Init(nameImg, 2, this->col, this->row);
	}
		
}

void Player::Dead(float deltaTime)
{
	canJump = false;
	this->canMove = false;
	animation.Init(this->nameImg, 8, 3, 9);
	velocity.y += (9.810f * deltaTime)/2.0f;
	this->isDead = true;
}

bool Player::isD()
{
	return this->isDead;
}


RectangleShape Player::getBody()
{
	
	return this->Body;
}

void Player::Update(float deltaTime, bool canMove, RenderWindow& window)
{
	if (this->canMove == false)
	{
		canMove = false;
	}
	velocity.x = 0.0f;
	if (Keyboard::isKeyPressed(sf::Keyboard::A) && canMove)
	{
		
		velocity.x -= speed* deltaTime*2.5;
		if (faceRight == true)
		{
			animation.Init(nameImg, 1, this->col, this->row);
		}
			
		this->faceRight = false;
	}
	
	

	if (Keyboard::isKeyPressed(sf::Keyboard::D) && canMove)
	{
		
		velocity.x += speed* deltaTime*2.5;
		animation.Init(nameImg, 1, this->col, this->row);
		this->faceRight = true;
	}

	//if (Keyboard::isKeyPressed(Keyboard::Space) && canMove)
	if (Keyboard::isKeyPressed(Keyboard::Space) &&  autoFire && canMove)
	{
		skill.setDispl(true);
		skill.setBegin(this->getPosition(),faceRight);
		
		animation.Init(nameImg, 4, this->col, this->row);

		
		skill.setListTexture();
		autoFire = false;
	}

	
	if (skill.getDispl()) {
		
		skill.update(deltaTime);
		skill.draw(window);
	}
	if ((skill.getBody()->getPosition().x > 1500.0f || skill.getBody()->getPosition().x < -300.0f) && canMove) {
		//cout << "FALSE" << endl;
		autoFire = true;
		skill.setDispl(false);
		
	}
	
	if (canJump)
	{
		velocity.y += 9.810f * deltaTime;
	}
		
	if (canMove == false)
	{
		velocity.x -= speed * deltaTime * 1.5;
	}
	
	
	animation.Update(deltaTime,faceRight);
	
	move(velocity);
	Body.setSize((Vector2f)animation.getSize()*this->getScale().x);
	Body.setOrigin(Body.getSize() * 0.5f);
	Body.setPosition(this->getPosition());
	Body.setOutlineThickness(3.f);
	Body.setOutlineColor(Color(0,0,0,0));
	//Body.setFillColor(Color::Red);

	
}






