#pragma once
#include<SFML/Graphics.hpp>
using namespace sf;

class Zombie
{
private:
	const float BLOATER_SPEED = 40;
	const float CRAWLER_SPEED = 20;
	const float CHASER_SPEED = 80;

	const float BLOATER_HEALTH = 5;
	const float CHASER_HEALTH = 1;
	const float CRAWLWER_HEALTH = 3;

	const int MAX_VARIANCE = 30;
	const int OFFSET = 101 - MAX_VARIANCE;

	//where is zombie
	Vector2f m_Position;
	//A sprite for the zombie
	Sprite m_Sprite;
	//speed of zomnie
	float m_Speed;
	//Health of the zomnbie;
	float m_Health;
	//zomnbie alove or not
	bool m_Alive;

public:
	//checks for hits;
	bool hit();
	//finding if the zombie alive or not
	bool isAlive();
	//spawn a new zombie
	void spawn(float startX, float startY, int type, int seed);
	//Returning a rectangle present in the real world representng the zomnie
	FloatRect getPosition();
	//get a copy of the sprete to be drawn
	Sprite getSprite();
	//updatng the zombeis in each frame
	void update(float time_elapsed, Vector2f playerLocation);

};