#include "Board.h"

#include <fstream> //for external files
#include <stdlib.h> //for exit
#include <iostream>
#include <string>

const char fileName[] = "level.txt";
const int NUM_OF_ICONS = 13;
const std::string picNames[NUM_OF_ICONS] = { "brickwall_0", "brickwall_1", "fire", "gate","king", "orc", "portal", "queen", "thief", "throne",
									"wall", "warrior", "wizard" }; //TOOK OUT KEY

Board::Board() :m_size(0)
{
	int size;

	// filling texture vector
	m_textures.resize(NUM_OF_ICONS);
	for (int i = 0; i < NUM_OF_ICONS; i++)
		m_textures[i].loadFromFile(picNames[i] + ".png");

	//checking if file is empty
	std::ifstream file;
	file.open(fileName);

	if (file.is_open())
	{
		file >> size;
		//read from file into matrix
	}
	else
	{
		std::cin >> size;

		//initialize matrix
		int square_size = 500 / size;
		sf::RectangleShape rect1(sf::Vector2f(square_size, square_size));
		std::vector<std::vector<sf::RectangleShape>> mat(size, std::vector<sf::RectangleShape>(size, rect1));
		m_mat = mat; //assign 

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				m_mat[i][j].setPosition(i * square_size, j * square_size);
				m_mat[i][j].setOutlineThickness(6);
				m_mat[i][j].setOutlineColor(sf::Color::Black);
				m_mat[i][j].setTexture(&m_textures[8]);
			}
		}
	}
	m_size = size;
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

void Board::drawBoard(sf::RenderWindow &window)
{
	//sf::Texture texture;

	/*if (!texture.loadFromFile("king.png"))
	{
		std::cerr << "image not found\n";
	}*/

	for (int i = 0; i < m_size ; i++)
	{
		for (int j = 0; j < m_size; j++)
		{
			//m_mat[i][j].setTexture(&texture);
			window.draw(m_mat[i][j]);
		}
	}
}
