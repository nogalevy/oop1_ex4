#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include "numof.h"
#include "view_constants.h"
#include <fstream> //for external files
#include <stdlib.h> //for exit
#include <iostream>
#include <string>
#include <string.h>


class MyWindow;

class Board
{
public:
	Board();

	//Menu Buttons
	void saveBoard(); //from save button on menu
	void clearBoard(); // from clear button on menu
	void deleteObjectOnBoard(int row, int col); //from delete object on menu
	void deleteObject(const sf::Vector2f& location);
	void handleHover(const sf::Vector2f& location);
	void handleClick(const sf::Vector2f& location, int last_active);


	//Access Functions
	int getSize();
	
	//other Functions
	void drawBoard(sf::RenderWindow &window); 

private:
	//members
	int m_size;
	std::vector<std::vector<sf::RectangleShape>> m_mat;
	std::vector<sf::Texture> m_textures;
	//std::vector<std::vector<int>> m_mm;
	int m_lastRow;
	int m_lastColumn;

};
