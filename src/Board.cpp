#include "Board.h"

#include <fstream> //for external files
#include <stdlib.h> //for exit
#include <iostream>

const char fileName[] = "level.txt";

Board::Board() :m_size(0)
{
	//check if file empty
	//if not empty get size
	//set size/ vector
	//read board into vector of rectangles (setTexture each time)

	int size;
	std::ifstream file;
	file.open(fileName);
	if (!file.is_open())
	{
		
		std::cout << "Please enter board size: ";
		std::cin >> size;
	}
	else
		file >> size;

	m_size = size;

	if (size != 0)
		m_mat.resize(size, std::vector<sf::RectangleShape>(size));

}

void Board::saveBoard()
{
	//take mat size
	//write size on file (open file for writing)
	//print vector of rectangles to file
}

void Board::clearBoard()
{
	//delete from mat everything (set background to default for alll)
}

void Board::deleteObjectOnBoard()//gets position
{
	//sets position to default background
}

int Board::getSize()
{
	return 0;
}
