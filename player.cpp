#include "player.h"
#include<iostream>

Player::Player()
	: m_Speed(START_SPEED),
	m_Health(START_HEALTH),
	m_MaxHealth(START_HEALTH),
	m_Sprite(),
	m_Texture(),
	m_UpPressed(false),
	m_DownPressed(false),
	m_LeftPressed(false),
	m_RightPressed(false),
	m_Tilesize(0)
{
	m_Texture.loadFromFile("graphics/player.png");
	m_Sprite.setTexture(m_Texture);

	//setting the origin of the sprite to centre for smooth rotation
	m_Sprite.setOrigin(25, 25);
}

void Player::spawn(IntRect arena, Vector2f resolution, int tilesize)
{
	m_Position.x = arena.width / 2;
	m_Position.y = arena.height / 2;

	//resetting the arena location
	m_Arena.left = arena.left;
	m_Arena.width = arena.width;
	m_Arena.top = arena.top;
	m_Arena.height = arena.height;

	//storing the tilesize;
	m_Tilesize = tilesize;

	//storing the resoluion
	m_Resolution.x = resolution.x;
	m_Resolution.y = resolution.y;
}

void Player::resetPlayerStats()
{
	m_Speed = START_SPEED;
	m_Health = START_HEALTH;
	m_MaxHealth = START_HEALTH;
}

Time Player::getLastHitTime()
{
	return m_LastHit;
}

bool Player::hit(Time timehit)
{
	if ((timehit.asMilliseconds() -
		m_LastHit.asMilliseconds()) > 200)
	{
		m_LastHit = timehit;
		m_Health -= 10;

		return true;
	}
	else
	{
		return false;
	}
}

FloatRect Player::getPositon()
{
	return m_Sprite.getGlobalBounds();
}

Vector2f Player::getCentre()
{
	return m_Position;
}

float Player::getRotation()
{
	return m_Sprite.getRotation();
}

Sprite Player::getSprite()
{
	return m_Sprite;
}

void Player::moveRight()
{
	m_RightPressed = true;
}

void Player::moveLeft()
{
	m_LeftPressed = true;
}

void Player::moveUp()
{
	m_UpPressed = true;
}

void Player::moveDown()
{
	m_DownPressed = true;
}

void Player::stopLeft()
{
	m_LeftPressed = false;
}

void Player::stopRight()
{
	m_RightPressed = false;
}

void Player::stopUp()
{
	m_UpPressed = false;
}

void Player::stopDown()
{
	m_DownPressed = false;
}

void Player::update(float elapsedTime, Vector2i mousePosition)
{
	if (m_LeftPressed) {
		m_Position.x -= m_Speed * elapsedTime;
	}
	if (m_RightPressed) {
		m_Position.x += m_Speed * elapsedTime;
	}
	if (m_UpPressed) {
		m_Position.y -= m_Speed * elapsedTime;
	}
	if (m_DownPressed) {
		m_Position.y += m_Speed * elapsedTime;
	}
	//resetting the sprite position
	m_Sprite.setPosition(m_Position);

	if (m_Position.x > m_Arena.width - m_Tilesize)
	{
		m_Position.x = m_Arena.width - m_Tilesize;
	}
	if (m_Position.x < m_Arena.left + m_Tilesize)
	{						   
		m_Position.x = m_Arena.left + m_Tilesize;
	}
	if (m_Position.y > m_Arena.height- m_Tilesize)
	{						  
		m_Position.y = m_Arena.height- m_Tilesize;
	}
	if (m_Position.y < m_Arena.top + m_Tilesize)
	{						   
		m_Position.y = m_Arena.top + m_Tilesize;
	}

	//setting the angle of the sprite
	float angle = (atan2(mousePosition.y - m_Resolution.y / 2,
		mousePosition.x - m_Resolution.x / 2) * 180) / 3.141;

	//setting the rotation
	m_Sprite.setRotation(angle);
}

void Player::upgradeSpeed()
{
	//increasing the speed by 20%
	m_Speed += (START_SPEED * 0.2);
}

void Player::upgradeHealth()
{
	//upgrading the health by 20 percent
	m_MaxHealth += (START_HEALTH) * 0.2;
}

void Player::increaseHealthLevel(int amount)
{
	m_Health += amount;

	if (m_Health > m_MaxHealth)
	{
		m_Health = m_MaxHealth;
	}
}

int Player::getHealth()
{
	return m_Health;
}
