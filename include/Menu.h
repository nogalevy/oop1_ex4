#pragma once

#include <SFML/Graphics.hpp>
#include "view_constants.h"
#include "numof.h"
#include "colors.h"
#include "Button.h"
#include "ObjBtn.h"

#include <iostream>

class Menu
{
public:
	Menu();
	Menu(int width);
	void setSize(int height, int width);
	int getHeight();
	void drawMenu(sf::RenderWindow& window)const;
	
	void setButtonData(std::vector<int> objExists);
	bool isContain(const sf::Vector2f& location);
	void handleClick(const sf::Vector2f& location, int &last_active);
	bool canAddObj(int character);
	void setObjExist(bool b, int character);
	void resetBtnsExist();

private:
	//Members
	sf::Color color = sf::Color::Color(24, 2, 134);
	int m_height;
	int m_width;
	sf::RectangleShape m_container; //change to NOT rectangle

	//std::vector<sf::RectangleShape> m_characters_btns;
	
	std::vector<sf::Texture> m_texture;
	
	std::vector<ObjBtn> m_characters_btns;
	std::vector<Button> m_game_btns;
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