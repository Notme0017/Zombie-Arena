// Zombie Arena.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include"player.h";
#include "zombieArena.h";


int main()
{
   //The game will likely be in one of the four states
	enum class State {PAUSED, LEVELLING_UP,
					GAMEOVER, PLAYING};

	//starting with gameover state
	State state = State::GAMEOVER;

	//getting the screen resolution
	Vector2f resolution;
	resolution.x =
		VideoMode::getDesktopMode().width;
	resolution.y =
		VideoMode::getDesktopMode().height;
	RenderWindow window(
		VideoMode(resolution.x, resolution.y),
		"Zombie Arena", Style::Fullscreen);
	//create an sfml view for the main action
	View mainView(sf::FloatRect(0, 0, resolution.x, resolution.y));

	//a clock for everything
	Clock clock;
	//How much time will the whole game take
	Time totalGameTime;
	//mouse location in the game world
	Vector2f mouseWorldPosition;
	//mosue location on screen coordinates
	Vector2i mouseScreenPosition;
	//creating a player instance
	Player player;
	//for the boundaries of the arena
	IntRect arena;
	//create the background
	VertexArray background;
	//Loading the texture from the file
	Texture textureBackground;
	textureBackground.loadFromFile("graphics/background_sheet.png");

	//game loop
	while (window.isOpen())
	{
		//handle input by polling
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::KeyPressed)
			{
				//pause the game while playing
				if (event.key.code == Keyboard::Return &&
					state == State::PLAYING) {
					state == State::PAUSED;
				}
				//restarting while game is paused
				if (event.key.code == Keyboard::Return &&
					state == State::PAUSED)
				{
					state == State::PLAYING;

					//restarting the clock so that the in game objects dont skip the frames
					clock.restart();
				}

				if (event.key.code == Keyboard::Return &&
					state == State::GAMEOVER)
				{
					state = State::LEVELLING_UP;
					//doing this as after a game is over the player first will need some upgrade while playing to survive;
				}

				if (state == State::PLAYING)
				{
				}

			}
		}
		//handle the player quitting
		if (Keyboard::isKeyPressed(Keyboard::Escape)) {
			window.close();
		}

		//handling the WASD keys
		if (Keyboard::isKeyPressed(Keyboard::W))
		{
			player.moveUp();
		}
		else
		{
			player.stopUp();
		}

		if (Keyboard::isKeyPressed(Keyboard::A))
		{
			player.moveLeft();
		}
		else
		{
			player.stopLeft();
		}

		if (Keyboard::isKeyPressed(Keyboard::S))
		{
			player.moveDown();
		}
		else
		{
			player.stopDown();
		}

		if (Keyboard::isKeyPressed(Keyboard::D))
		{
			player.moveRight();
		}
		else
		{
			player.stopRight();
		}

		if (state == State::LEVELLING_UP)
		{
			if (event.key.code == Keyboard::Num1)
			{
				state = State::PLAYING;
			}
			if (event.key.code == Keyboard::Num2)
			{            
				state = State::PLAYING;
			}
			if (event.key.code == Keyboard::Num3)
			{
				state = State::PLAYING;
			}
			if (event.key.code == Keyboard::Num4)
			{
				state = State::PLAYING;
			}
			if (event.key.code == Keyboard::Num5)
			{
				state = State::PLAYING;
			}
			if (event.key.code == Keyboard::Num6)
			{
				state = State::PLAYING;
			}

			if (state == State::PLAYING)
			{
				//Prepare the level
				arena.width = 500;
				arena.height = 500;
				arena.left = 0;
				arena.top = 0;

				int tilesize = createBackground(background, arena);
				//Spawning the player in the middle of the arena
				player.spawn(arena, resolution, tilesize);

				//reseting the clock to avoid frame jump
				clock.restart();
			}
		}

		if (state == State::PLAYING)
		{
			//update the delta time
			Time dt = clock.restart();

			//updating the total game time
			totalGameTime += dt;

			float dtAsSeconds = dt.asSeconds();
			//getting mouse screen position
			mouseScreenPosition = Mouse::getPosition();
			//converting mouse position to world Position
			//on basis of coordinates of the mainView
			mouseWorldPosition = window.mapPixelToCoords(
				Mouse::getPosition(), mainView
			);
			//update the player
			player.update(dtAsSeconds, Mouse::getPosition());
			//Making a note of players new location
			Vector2f playerPostition(player.getCentre());

			//making the main view centre around the player
			mainView.setCenter(player.getCentre());
		}

		/*Drawing the 
		scene*/
		if (state == State::PLAYING)
		{
			window.clear();
			window.setView(mainView);
			window.draw(background, &textureBackground);
			window.draw(player.getSprite());
		}
		
		if (state == State::LEVELLING_UP)
		{

		}

		if (state == State::PAUSED)
		{

		}

		if (state == State::GAMEOVER)
		{

		}
		window.display();
	}

	return 0;
}
