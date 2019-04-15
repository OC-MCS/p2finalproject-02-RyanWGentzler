#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "MissileGroup.h"
#include "Squadron.h"
using namespace std;
using namespace sf; 

//============================================================
// Ryan Gentzler
//============================================================

int main()
{
	const int WINDOW_WIDTH = 800;
	const int WINDOW_HEIGHT = 600;
	int globalTimer = 0;
	Player ship;
	MissileGroup grp;
	Alien alien;

	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "aliens!");
	// Limit the framerate to 60 frames per second
	window.setFramerateLimit(60);

	// load textures from file into memory. This doesn't display anything yet.
	// Notice we do this *before* going into animation loop.
	Texture shipTexture;
	if (!shipTexture.loadFromFile("ship.png"))
	{
		cout << "Unable to load ship texture!" << endl;
		exit(EXIT_FAILURE);
	}
	Texture starsTexture;
	if (!starsTexture.loadFromFile("stars.jpg"))
	{
		cout << "Unable to load stars texture!" << endl;
		exit(EXIT_FAILURE);
	}
	Texture missileTexture;
	if (!missileTexture.loadFromFile("missile.png"))
	{
		cout << "Unable to load missile texture!" << endl;
		exit(EXIT_FAILURE);
	}
	Texture alienTexture;
	if (!alienTexture.loadFromFile("alien2.png"))
	{
		cout << "Unable to load alien texture!" << endl;
		exit(EXIT_FAILURE);
	}

	// A sprite is a thing we can draw and manipulate on the screen.
	// We have to give it a "texture" to specify what it looks like

	Sprite background;
	background.setTexture(starsTexture);
	// The texture file is 640x480, so scale it up a little to cover 800x600 window
	background.setScale(1.5, 1.5);

	// create sprite and texture it
	ship.setTexture(shipTexture);

	alien.setTexture(alienTexture);
	alien.setPosition(window.getSize().x / 2.0f, window.getSize().y / 2.0f);

	grp.setTexture(missileTexture);

	// initial position of the ship will be approx middle of screen
	float shipX = window.getSize().x / 2.0f;
	float shipY = window.getSize().y - (window.getSize().y / 8.0f);
	ship.setPosition(shipX, shipY);


	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		// For now, we just need this so we can click on the window and close it
		Event event;

		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == Event::Closed)
				window.close();
			else if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Space)
				{
					grp.addMiss(ship.getPosition());
				}
				
			}
		}

		grp.moveMissiles();
		//===========================================================
		// Everything from here to the end of the loop is where you put your
		// code to produce ONE frame of the animation. The next iteration of the loop will
		// render the next frame, and so on. All this happens ~ 60 times/second.
		//===========================================================

		window.draw(background);

		

		// draw the ship on top of background 
		// (the ship from previous frame was erased when we drew background)
		ship.move();
		window.draw(ship.getSprite());
		grp.draw(window);
		alien.draw(window);


		// end the current frame; this makes everything that we have 
		// already "drawn" actually show up on the screen
		window.display();

		if (globalTimer < 1000000)
			globalTimer++;
	}

	return 0;
}

