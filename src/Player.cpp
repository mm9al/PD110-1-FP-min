#include "Player.hpp"

const float Player::MAX_V = .5f;

Player::Player(const sf::Vector2f& border, std::vector<sf::Texture> frames, int number) :
	Entity(frames),
	hp(Player::MAX_HP)
{
	pressingW = pressingA = pressingS = pressingD = false;
	this->border = border;
	this->rebouncingx = false;
	this->rebouncingy = false;
	this->number = number;
	sprite.scale(.3f, .3f);
}

Player::~Player()
{
}

void Player::control(const sf::Event& event)
{
	const float pi = 3.14159;
	float angle0 = sprite.getRotation();
	float angle = angle0*pi/180;

	if (number == 1)
	{
		float omega = 10;
		switch (event.type)
		{
			case sf::Event::KeyPressed:
				switch (event.key.code)
				{
					case sf::Keyboard::A:
						sprite.rotate(-omega);
						break;
					case sf::Keyboard::D:
						sprite.rotate(omega);
						break;
					case sf::Keyboard::W:
						vx = MAX_V*sin(angle);
						vy = -MAX_V*cos(angle);
						break;
					case sf::Keyboard::S:
						vx = -MAX_V*sin(angle);
						vy = MAX_V*cos(angle);
						break;
					default:
						break;
				}
				break;
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
					case sf::Keyboard::A:

						break;
					case sf::Keyboard::D:

						break;
					case sf::Keyboard::W:
						vx=0;
						vy=0;
						break;
					case sf::Keyboard::S:
						vx=0;
						vy=0;
						break;
					default:
						break;
				}
				break;
			default:
				break;
		}
	}
	else if (number == 2)
	{
		float omega = 0.1;
		switch (event.type)
		{
			case sf::Event::KeyPressed:
				switch (event.key.code)
				{
					case sf::Keyboard::Left:
						sprite.rotate(-omega);
						break;
					case sf::Keyboard::Right:
						sprite.rotate(omega);
						break;
					case sf::Keyboard::Up:
						vx = MAX_V*sin(angle);
						vy = -MAX_V*cos(angle);
						break;
					case sf::Keyboard::Down:
						vx = -MAX_V*sin(angle);
						vy = MAX_V*cos(angle);
						break;
					default:
						break;
				}
				break;
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
					case sf::Keyboard::Left:

						break;
					case sf::Keyboard::Right:

						break;
					case sf::Keyboard::Up:
						vx=0;
						vy=0;
						break;
					case sf::Keyboard::Down:
						vx=0;
						vy=0;
						break;

					default:
						break;
				}
				break;
			default:
				break;
		}
	}

}

void Player::checkBorder()
{
	auto pos = sprite.getPosition();

	if (pos.x < 0)
		sprite.setPosition(0, pos.y);
	if (pos.x > border.x)
		sprite.setPosition(border.x, pos.y);
	pos = sprite.getPosition();
	if (pos.y < 0)
		sprite.setPosition(pos.x, 0);
	if (pos.y > border.y)
		sprite.setPosition(pos.x, border.y);
}

void Player::update(const sf::Event& event, float deltaTime)
{
	control(event);
	if (currTime >= Entity::UPDATE_TIME)
	{
		updateMovement();
		updateFrame();
		currTime -= Entity::UPDATE_TIME;
	}
	checkBorder();
	currTime += deltaTime;
}

void Player::dealDamage(int damage) {
	hp -= damage;
	if (hp <= 0) isAlive = false;
	std::cout << "[Player" << number <<  "] " << "a damage of 5 was dealt, " << hp << " left." << std::endl;
}

void Player::reset(const sf::Vector2f& newPos) {
	hp = Player::MAX_HP;
	sprite.setPosition(newPos);
}