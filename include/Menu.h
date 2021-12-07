#pragma once

#include <SFML/Graphics.hpp>
#include "view_constants.h"
#include "numof.h"
#include "colors.h"



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
	sf::Color color = sf::Color::Color(24, 2, 134);
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