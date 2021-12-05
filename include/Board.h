#pragma once
#include "MyWindow.h"

class Board
{
public:
	Board();

	//Menu Buttons
	void saveBoard(); //from save button on menu
	void clearBoard(); // from clear button on menu
	void deleteObjectOnBoard(); //from delete object on menu

	//Access Functions
	int getSize();
	
	//other Functions
	//
	

private:
	//members
	int m_size;
	std::vector<std::vector<sf::RectangleShape>> m_mat; //(size, std::vector<sf::RectangleShape>(size, rect1));

};

/*
	functions:
	
	constructor: Board(fstream "level.txt", ....)


	handle click - get position of mouse and blalbkalbaa
	set board (from file) - constructor ?

	members:
	vector of sf::square
	fstream m_level




*/