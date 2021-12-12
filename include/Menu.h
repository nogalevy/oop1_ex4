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
	void drawMenu(sf::RenderWindow& window)const;
	void setButtonData(std::vector<int> objExists);
	bool isContain(const sf::Vector2f& location)const;
	void handleClick(const sf::Vector2f& location, int &last_active);
	bool canAddObj(int character)const;
	void setObjExist(bool b, int character);
	void resetBtnsExist();

private:
	//Members
	sf::Color color = sf::Color::Color(24, 2, 134);
	sf::RectangleShape m_container;	
	std::vector<sf::Texture> m_texture;

	std::vector<ObjBtn> m_characters_btns; 
	std::vector<Button> m_game_btns;

};