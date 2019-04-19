#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
using namespace sf;

class Menus
{
private:
	RectangleShape startBtn;
	bool GameStarted = false;
	bool GameOver = false;
public:
	//checks and handles what to do if the mouse is lifted up
	void handleMouseUp(Vector2f mouse)
	{
		if (startBtn.getGlobalBounds().contains(mouse))
		{
			GameStarted = true;
			GameOver = false;
		}
	}
	//returns whether the game has started or not
	bool isGameStarted()
	{
		return GameStarted;
	}
	//returns whether the game is over or not
	bool isGameOver()
	{
		return GameOver;
	}
	//ends the game (sets GameOver to true)
	void endGame()
	{
		GameOver = true;
	}
	//draws the menu in the four states the game could be in
	void draw(RenderWindow& win, int life, int aliens)
	{
		Font font;
		font.loadFromFile("C:\\Windows\\Fonts\\comic.ttf");

		//this checks to see if the game hasn't started yet
		if (!GameStarted)
		{
			Text title("Intersteller Intruders", font, 40);
			title.setPosition(win.getSize().x / 4.0f + 40, win.getSize().y / 4.0f);
			win.draw(title);

			startBtn.setPosition(win.getSize().x / 2.0f - 65, win.getSize().y / 1.5f);
			startBtn.setFillColor(Color::Blue);
			startBtn.setOutlineColor(Color::White);
			startBtn.setOutlineThickness(2);
			startBtn.setSize(Vector2f(200, 30));
			win.draw(startBtn);

			Text subtitle("Open the Game!", font, 20);
			subtitle.setPosition(win.getSize().x / 2.0f - 60, win.getSize().y / 1.5f);
			win.draw(subtitle);
		}
		//this checks to see if the player has lives and the game hasn't ended yet
		else if (life > 0 && !GameOver)
		{
			Text lives("Lives:", font, 20);
			lives.setPosition(20, 20);
			win.draw(lives);

			Text curlives(to_string(life), font, 20);
			curlives.setPosition(75, 22);
			win.draw(curlives);

			Text destroyed("Destroyed:", font, 20);
			destroyed.setPosition(600, 20);
			win.draw(destroyed);

			Text alides(to_string(aliens), font, 20);
			alides.setPosition(720, 20);
			win.draw(alides);
		}
		//this checks to see if the game ended due to player running out of lives
		else if (life <= 0)
		{
			Text gameov("Aliens Win", font, 80);
			gameov.setPosition(win.getSize().x / 8.0f, win.getSize().y / 2.0f - 20);
			win.draw(gameov);

			startBtn.setPosition(win.getSize().x / 2.0f - 65, win.getSize().y / 1.5f);
			startBtn.setFillColor(Color::Blue);
			startBtn.setOutlineColor(Color::White);
			startBtn.setOutlineThickness(2);
			startBtn.setSize(Vector2f(200, 30));
			win.draw(startBtn);

			Text subtitle("Play Again?", font, 20);
			subtitle.setPosition(win.getSize().x / 2.0f - 60, win.getSize().y / 1.5f);
			win.draw(subtitle);
			GameOver = true;
		}
		//and this is the catch all, it just lets the player win
		else
		{
			Text gameov("You Win", font, 80);
			gameov.setPosition(win.getSize().x / 8.0f, win.getSize().y / 2.0f - 20);
			win.draw(gameov);

			startBtn.setPosition(win.getSize().x / 2.0f - 65, win.getSize().y / 1.5f);
			startBtn.setFillColor(Color::Blue);
			startBtn.setOutlineColor(Color::White);
			startBtn.setOutlineThickness(2);
			startBtn.setSize(Vector2f(200, 30));
			win.draw(startBtn);

			Text subtitle("Play Again?", font, 20);
			subtitle.setPosition(win.getSize().x / 2.0f - 60, win.getSize().y / 1.5f);
			win.draw(subtitle);
			GameOver = true;
		}
	}
};