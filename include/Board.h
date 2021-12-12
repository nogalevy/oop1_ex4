#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include "numof.h"
#include "colors.h"

#include "view_constants.h"
#include <stdlib.h> //for exit
#include <iostream>

class Board
{
public:
	Board();

	void saveBoard()const; //from save button on menu
	void clearBoard(); // from clear button on menu
	int deleteObject(const sf::Vector2f& location);
	void handleHover(const sf::Vector2f& location, int last);
	int handleClick(const sf::Vector2f& location, int last_active);
	int getObj(int i, int j)const;
	void setBoard();

	int getSize()const;
	std::vector<int> getObjExists()const;

	void drawBoard(sf::RenderWindow &window);

private:
	//members
	int m_size; //size of board
	std::vector<std::vector<sf::RectangleShape>> m_mat;
	std::vector<sf::Texture> m_textures;
	int m_lastRow; //last row and columns hovered over
	int m_lastColumn;

	void deleteObjectOnBoard(int row, int col); //from delete object on menu
	void initTextures();
	void initSquare(int row, int col, int square_size);
	std::vector<std::vector<sf::RectangleShape>> initMat(int size, int square_size);
	int getCharObj(char c)const;
};
