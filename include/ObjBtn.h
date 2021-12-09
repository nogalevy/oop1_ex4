#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include "numof.h"
//#include "Position.h"
#include "view_constants.h"
#include <fstream> //for external files
#include <stdlib.h> //for exit
#include <iostream>
#include <string>
#include <string.h>
#include "Button.h"

class ObjBtn : public Button
{
public:
	ObjBtn();
	ObjBtn(int max, sf::Texture texture); //add exist

	//char btn
	void setMax(const int max);
	void setExist(bool op); // - false     + true
	bool canAddToBoard()const;


private:
	// to char btn - another class;
	//Position m_char_position_on_board;
	int m_max;
	int m_exist;

};
