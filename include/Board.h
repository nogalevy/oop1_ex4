#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

class MyWindow;

class Board
{
public:
	Board();

	//Menu Buttons
	void saveBoard(); //from save button on menu
	void clearBoard(); // from clear button on menu
	void deleteObjectOnBoard(int row, int col); //from delete object on menu

	//Access Functions
	int getSize();
	
	void drawBoard(sf::RenderWindow &window)const;
	//other Functions
	

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