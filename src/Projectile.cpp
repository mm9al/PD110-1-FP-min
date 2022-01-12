#include "Projectile.hpp"

static const float MAX_V = 1.6f;
const float pi = 3.14159;

Projectile::Projectile(const std::vector<sf::Texture>& frames, int type) :
	Entity(frames),
	type(type)
{
	this->sprite.setPosition(sf::Vector2f(100, 100));
}

Projectile::~Projectile()
{
}
/*
void Projectile::shoot(const sf::Event& event)
{
	switch (event.type)
	{
		case sf::Event::KeyPressed:
			switch (event.key.code)
			{
				case sf::Keyboard::V:
					float angle = sprite.getRotation();

					vx = MAX_V * sin(angle * pi / 180);
					vy = -MAX_V * cos(angle * pi / 180);
					break;

				default:
					break;
			}
			break;

		case sf::Event::KeyReleased:
			break;

		default:
			break;
	}
}
*/
void Projectile::checkCollision(Entity& anotherEntity)
{
	if (collidesWith(anotherEntity))
	{
		isAlive = false;
	}
}

int Projectile::getDamage() const
{
	return damage;
}