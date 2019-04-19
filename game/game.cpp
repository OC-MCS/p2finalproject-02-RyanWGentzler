#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "MissileGroup.h"
#include "Bombardment.h"
#include "Squadron.h"
#include "Menus.h"
#include "Level.h"
using namespace std;
using namespace sf; 

//============================================================
// Ryan Gentzler
//============================================================

int main()
{
	const int WINDOW_WIDTH = 800;
	const int WINDOW_HEIGHT = 600;
	int globalTimer = 0, tempTimer = 0, numdestroyed = 0;
	bool atLimit = false;
	Player ship;
	MissileGroup grp;
	Bombardment bmb;
	Squadron squad;
	Alien alien;
	Menus menu;
	Level level;

	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "aliens!");
	// Limit the framerate to 60 frames per second
	window.setFramerateLimit(60);

	// load textures from file into memory. This doesn't display anything yet.
	// Notice we do this *before* going into animation loop.
	Texture shipTexture;
	if (!shipTexture.loadFromFile("savior_starship.png"))
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
	if (!alienTexture.loadFromFile("alien.png"))
	{
		cout << "Unable to load alien texture!" << endl;
		exit(EXIT_FAILURE);
	}
	level.setTexture1(alienTexture);
	Texture alienTexture2;
	if (!alienTexture2.loadFromFile("alien2.png"))
	{
		cout << "Unable to load alien2 texture!" << endl;
		exit(EXIT_FAILURE);
	}
	level.setTexture2(alienTexture2);

	// A sprite is a thing we can draw and manipulate on the screen.
	// We have to give it a "texture" to specify what it looks like

	Sprite background;
	background.setTexture(starsTexture);
	// The texture file is 640x480, so scale it up a little to cover 800x600 window
	background.setScale(1.5, 1.5);

	// create sprite and texture it
	ship.setTexture(shipTexture);

	grp.setTexture(missileTexture);
	bmb.setTexture(missileTexture);

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
			else if (event.type == Event::MouseButtonReleased)
			{
				Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));
				menu.handleMouseUp(mousePos);
			}
		}

		if (menu.isGameStarted() && ship.getLives() > 0 && !menu.isGameOver())
		{
			if (globalTimer % 20 == 0)
				atLimit = squad.move(10);

			if (!squad.aliens() && level.getLevel() == 0)
			{
				squad.setTexture(level.getAlienTexture());
				for (int i = 0; i < 10; i++)
				{
					squad.addAlien(75 * i + 40, 30);
				}
				level.setLevel(1);
			}
			else if (!squad.aliens() && level.getLevel() == 1)
			{
				squad.setTexture(level.getAlienTexture());
				for (int i = 0; i < 10; i++)
				{
					squad.addAlien(75 * i + 40, 30);
				}
				level.setLevel(2);
			}
			else if (!squad.aliens() && level.getLevel() == 2)
			{
				menu.endGame();
			}

			if (globalTimer - tempTimer >= 60)
			{
 				bmb.addMiss(squad.getRandPos());
				tempTimer = globalTimer;
			}

			if (atLimit)
			{
				ship.modlives(-1);
				atLimit = squad.move(-450);
			}

			if (!ship.alive())
			{
				menu.endGame();
			}

			for (int i = 0; i < grp.getSize(); i++)
			{
				if (squad.intersect(grp.getSprite(i)))
				{
					grp.remMiss();
					numdestroyed++;
				}
			}

			for (int i = 0; i < bmb.getSize(); i++)
			{
				if (ship.intersect(bmb.getSprite(i)))
				{
					bmb.remMiss();
					squad.move(-(squad.getRandPos().y) + 20);
				}
			}

			
			bmb.moveMissiles(level.getLevel());
			grp.moveMissiles();

			//===========================================================
			// Everything from here to the end of the loop is where you put your
			// code to produce ONE frame of the animation. The next iteration of the loop will
			// render the next frame, and so on. All this happens ~ 60 times/second.
			//===========================================================

			window.draw(background);


			bmb.draw(window);
			grp.draw(window);
			// draw the ship on top of background 
			// (the ship from previous frame was erased when we drew background)
			ship.move();
			window.draw(ship.getSprite());
			squad.draw(window);

			if (globalTimer < 1000000)
				globalTimer++;
		}
		menu.draw(window, ship.getLives(), numdestroyed);

		if(!menu.isGameStarted())
		{
			ship.setlives(3);
		}

		// end the current frame; this makes everything that we have 
		// already "drawn" actually show up on the screen
		window.display();
	}

	return 0;
}

