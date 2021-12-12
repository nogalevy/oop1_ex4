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
#include "Button.h"

class ObjBtn : public Button
{
public:
	ObjBtn();
	// ObjBtn(int max, sf::Texture texture); //add exist

	//char btn
	void setMax(const int max);
	void setExist(bool op); // - false     + true
	bool canAddToBoard()const;
	void initExists(int num);
	void initMax(int num);
	int getExist()const;

private:
	int m_max;
	int m_exist;
};
