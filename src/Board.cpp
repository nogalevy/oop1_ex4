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
	//std::ifstream file;

	//file.open(fileName);

	sf::Texture texture;
	texture.loadFromFile("orc.png");

	size = 5; //size of rows and cols
	int square_size = 100;//500 / size; //calc the size of each square
	sf::RectangleShape rect1(sf::Vector2f(square_size, square_size));
	//std::vector<std::vector<sf::RectangleShape>> mat(size, std::vector<sf::RectangleShape>(size, rect1));
	m_mat.resize(size, std::vector<sf::RectangleShape>(size, rect1));


	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			m_mat[i][j].setPosition(i * square_size, j * square_size);
			m_mat[i][j].setTexture(&texture);
		}
	}

	/*if (!file.is_open())
	{
		std::cout << "Please enter board size: ";
		std::cin >> size;
		clearBoard();
	}
	else
		file >> size;
		//fill board from file

	m_size = size;

	if (size != 0)
	{
		m_mat.resize(size, std::vector<sf::RectangleShape>(size));
		sf::Texture texture;
		texture.loadFromFile("texture1.jpg");
	}
	*/

}

void Board::saveBoard()
{
	//take mat size
	//write size on file (open file for writing)
	//print vector of rectangles to file

	std::ofstream file;
	file.open(fileName); //perror?

	//printing size to file
	file << this->getSize() << "\n";

	//printing board to file
	for (int i = 0; i < this->getSize(); i++)
	{
		for (int j = 0; j < this->getSize(); j++)
		{
			/*
			switch (m_mat[i][j].getTexture())
			{
				case 
			}
			*/
		}
	}

}

void Board::clearBoard()
{
	for (int row = 0; row < this->getSize(); row++)
		for (int col = 0; col < this->getSize(); col++)
			deleteObjectOnBoard(row, col);
}


void Board::deleteObjectOnBoard(int row, int col)
{
	m_mat[row][col].setTexture(NULL);
	m_mat[row][col].setFillColor(sf::Color::Black);
}

int Board::getSize()
{
	return m_size;
}

void Board::drawBoard(sf::RenderWindow &window)const
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			window.draw(m_mat[i][j]);
		}
	}
}
