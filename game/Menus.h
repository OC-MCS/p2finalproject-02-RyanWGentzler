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
	void handleMouseUp(Vector2f mouse)
	{
		if (startBtn.getGlobalBounds().contains(mouse))
		{
			GameStarted = true;
			GameOver = false;
		}
	}
	bool isGameStarted()
	{
		return GameStarted;
	}
	bool isGameOver()
	{
		return GameOver;
	}
	void endGame()
	{
		GameOver = true;
	}
	void draw(RenderWindow& win, int life)
	{
		Font font;
		font.loadFromFile("C:\\Windows\\Fonts\\comic.ttf");

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
		else if (life > 0 || !GameOver)
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

		//	Text alides(to_string(aliens), font, 20);
		//	alides.setPosition(470, 20);
		//	win.draw(alides);
		}
		else
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
	}
};