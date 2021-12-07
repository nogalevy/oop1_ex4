#pragma once

#include <SFML/Graphics.hpp>

const int NUM_OF_ICONS = 10;


const int DEFAULT_WIDTH = 500;
const int DEFAULT_HEIGHT = 500;

const int DEFAULT_BTN_WIDTH = DEFAULT_WIDTH / NUM_OF_ICONS;
const int DEFAULT_BTN_HEIGHT = DEFAULT_BTN_WIDTH;

class Menu
{
public:
	Menu();
	Menu(int width);
	void setSize(int height, int width);
	int getHeight();
	void drawMenu(sf::RenderWindow& window)const;

private:
	//Members
	int m_height;
	int m_width;
	sf::RectangleShape m_container;

	std::string m_char_names[NUM_OF_ICONS] = { "king", "wizard",  "thief",  "warrior",  "wall",  "gate",  "orc",  "portal",  "fire",  "throne" };
	std::vector<sf::RectangleShape> m_characters_btns;
	
	std::vector<sf::Texture> m_texture;

	// GameObjects...

};

/*
	functions:
	draw menu
		all buttons and Objects buttons
	handle click - get poaition of mouse and blalbkalbaa


	members:
	Buttons:
		save board
		clear board
		delete object
	Objects:
		King ....

*/

class GameObjects
{
public:

private:

};