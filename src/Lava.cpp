#include "Lava.hpp"

Lava::Lava(const sf::Vector2f& pos) :
	timer1(0),
	timer2(0)
{
	texture.loadFromFile("content/Image/Lava/lava.png");
	sprite.setPosition(pos);
	sprite.setTexture(texture);
	sprite.scale(Tile::TILE_SIZE / (float)sprite.getTexture()->getSize().x, Tile::TILE_SIZE / (float)sprite.getTexture()->getSize().y);
}

Lava::~Lava()
{
}

void Lava::draw(sf::RenderTexture& bufferMap) const
{
	bufferMap.draw(sprite);
}

void Lava::update(std::vector<Player*> players, float deltaTime)
{
	if (players[0]->sprite.getGlobalBounds().intersects(sprite.getGlobalBounds()))
		timer1 += deltaTime;
	else
		timer1 = 2.99f;
	if (players[1]->sprite.getGlobalBounds().intersects(sprite.getGlobalBounds()))
		timer2 += deltaTime;
	else
		timer2 = 2.99f;

	if (timer1 > Lava::DAMAGE_INTERVAL)
	{
		timer1 -= Lava::DAMAGE_INTERVAL;
		players[0]->dealDamage(Lava::DAMAGE);
	}
	if (timer2 > Lava::DAMAGE_INTERVAL)
	{
		timer2 -= Lava::DAMAGE_INTERVAL;
		players[1]->dealDamage(Lava::DAMAGE);
	}
}