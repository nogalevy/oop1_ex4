#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include "numof.h"
#include "Position.h"
#include "view_constants.h"
#include <fstream> //for external files
#include <stdlib.h> //for exit
#include <iostream>
#include <string>
#include <string.h>


class Button
{
public:
	Button();
	Button(int max, Position position, sf::Texture texture);
	sf::RectangleShape createBtn(int row, int col) const;
	void setBtnSize(int width, int height);
	void setBtnTexture(sf::Texture texture);
	void setIsClicked(const bool b);

	//char btn
	void setMax(const int max);
	void setExist(bool op); // - false     + true
	bool canAddToBoard()const;


private:
	int m_btn_width;
	int m_btn_height;
	sf::Texture m_texture;
	bool m_isClicked;

	// to char btn - another class;
	Position m_char_position_on_board;
	int m_max;
	int m_exist;

};
