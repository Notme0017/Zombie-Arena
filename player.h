#pragma once
#include<SFML/Graphics.hpp>
using namespace sf;

class Player
{
private:
	const float START_SPEED = 200;
	const float START_HEALTH = 100;

	//getting player location
	Vector2f m_Position;
	
	Sprite m_Sprite;

	Texture m_Texture;
	//getting the screen resolution
	Vector2f m_Resolution;
	//sixe of the current arena
	IntRect m_Arena;
	//tile size in arena
	int m_Tilesize;
	//key press direction
	bool m_UpPressed;
	bool m_DownPressed;
	bool m_LeftPressed;
	bool m_RightPressed;
	//how much health player has
	int m_Health;
	//max health of the player
	int m_MaxHealth;
	//last time player got hit
	Time m_LastHit;
	//speed in pixels per second
	float m_Speed;

public:
	Player();

	void spawn(IntRect arena, Vector2f resolution, int tilesize);
	//resetting player stats at teh end of every game
	void resetPlayerStats();

	//getting last hit time for managing hits per second to not instantly get obliterated
	Time getLastHitTime();
	//handling the player getting hit
	bool hit(Time timehit);
	//location of player
	FloatRect getPositon();
	//centre of the player
	Vector2f getCentre();
	//angle which player is facing
	float getRotation();
	//sending a copy of sprite to the player
	Sprite getSprite();
	//moving the player
	void moveRight();
	void moveLeft();
	void moveUp();
	void moveDown();

	//stopping the player
	void stopLeft();
	void stopRight();
	void stopUp();
	void stopDown();

	//frame update
	void update(float elapsedTime, Vector2i mousePosition);
	//giving a speed boost
	void upgradeSpeed();
	//giving a health boost
	void upgradeHealth();
	//increase the max health
	void increaseHealthLevel(int amount);
	//how much health the player currently has
	int getHealth();
};
