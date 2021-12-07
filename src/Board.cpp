#include "Board.h"

#include <fstream> //for external files
#include <stdlib.h> //for exit
#include <iostream>
#include <string>
#include <string.h>

enum Icons { KING, WIZARD, WARRIOR, THIEF, WALL, GATE, FIRE, ORC, PORTAL, THRONE };
//const std::string fileName = "level.txt"; //when using file stream
const char* fileName = "level.txt";
const int NUM_OF_ICONS = 10;
const std::string picNames[NUM_OF_ICONS] = {"king", "wizard", "warrior", "thief", "brickwall_2", "gate", "fire", "orc", "portal", "throne"}; //TOOK OUT KEY

Board::Board() :m_size(0)
{
	int size;

	// filling texture vector
	m_textures.resize(NUM_OF_ICONS);
	for (int i = 0; i < NUM_OF_ICONS; i++)
		m_textures[i].loadFromFile(picNames[i] + ".png");
	
	FILE* file = fopen(fileName, "r");

	if (file != NULL) //if file is not empty
	{
		char c;
		std::cout << "here\n";
		c = getc(file);
		size = ((int)c) - 39;
		//read from file into matrix
		std::cout << size << "\n";
		
		const int newsize = size;
		char** fileBoard;
		fileBoard = new char* [size];

		for (int i = 0; i < size; i++)
			fileBoard[i] = new char[size];


		c = getc(file);
		std::cout << c;
		c = getc(file);
		std::cout << c;


		for (int row = 0; row < size; row++)
		{

			for (int col = 0; col < size; col++)
			{
				c = getc(file);
				std::cout << c;
				fileBoard[row][col] = c;
			}
			c = getc(file);
		
			std::cout << "\n";
		}

		//fill matrix with file board
		int square_size = 500 / size; //set 500 to const
		sf::RectangleShape rect1(sf::Vector2f(square_size, square_size));
		std::vector<std::vector<sf::RectangleShape>> mat(size, std::vector<sf::RectangleShape>(size, rect1));
		m_mat = mat; //assigning matrix created 


		for (int row = 0; row < size; row++)
		{
			for (int col = 0; col < size; col++)
			{
				m_mat[row][col].setOutlineThickness(0.5);
				m_mat[row][col].setOutlineColor(sf::Color::Black);
				m_mat[row][col].setPosition(col * square_size , row * square_size + 200);
				

				switch (fileBoard[row][col])
				{
				case 'K':
					//m_mm[row][col] = KING;
					m_mat[row][col].setTexture(&m_textures[KING]);
					break;
				case 'M':
					m_mat[row][col].setTexture(&m_textures[WIZARD]);
					break;
				case 'W':
					m_mat[row][col].setTexture(&m_textures[WARRIOR]);
					break;
				case 'T':
					m_mat[row][col].setTexture(&m_textures[THIEF]);
					break;
				case '=':
					m_mat[row][col].setTexture(&m_textures[WALL]);
					break;
				case '#':
					m_mat[row][col].setTexture(&m_textures[GATE]);
					break;
				case '*':
					m_mat[row][col].setTexture(&m_textures[FIRE]);
					break;
				case '!':
					m_mat[row][col].setTexture(&m_textures[ORC]);
					break;
				case 'X':
					m_mat[row][col].setTexture(&m_textures[PORTAL]);
					break;
				case '@':
					m_mat[row][col].setTexture(&m_textures[THRONE]);
					break;
				default:
					m_mat[row][col].setTexture(NULL);

					break;
				}
			}
		}
		std::cout << "here1\n";

	}
	else //if file is empty
	{
		std::cout << "Please enter size of board: \n";
		std::cin >> size;

		//creating matrix
		int square_size = 500 / size; //set 500 to const
		sf::RectangleShape rect1(sf::Vector2f(square_size, square_size));
		std::vector<std::vector<sf::RectangleShape>> mat(size, std::vector<sf::RectangleShape>(size, rect1));
		m_mat = mat; //assigning matrix created 

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				m_mat[i][j].setPosition(i * square_size + 500, j * square_size);
				//m_mat[i][j].setOutlineThickness(2);
				//m_mat[i][j].setOutlineColor(sf::Color::Black);
				m_mat[i][j].setTexture(&m_textures[2]); //take out
			}
		}
	}
	m_size = size;
}

void Board::saveBoard()
{

	//opening file or creating file (overwrites if exists)
	FILE* file = fopen(fileName, "w+"); //T: Q: where does it open if it doesnt exist? can we choose?

	//creating array to print into file
	const int newsize = m_size;
	char** fileBoard;
	fileBoard = new char* [m_size];
	
	for (int i = 0; i < m_size; i++)
		fileBoard[i] = new char[m_size];

	//printing size to file
	fprintf(file, "%d\n", m_size);

	for (int i = 0; i < m_size; i++)
	{
		for (int j = 0; j < m_size; j++)
		{
			
			if (m_mat[i][j].getTexture() == &m_textures[KING])
				fprintf(file, "K");
			else if (m_mat[i][j].getTexture() == &m_textures[WIZARD])
				fprintf(file, "M");
			else if (m_mat[i][j].getTexture() == &m_textures[WARRIOR])
				fprintf(file, "W");
			else if (m_mat[i][j].getTexture() == &m_textures[THIEF])
				fprintf(file, "T");
			else if (m_mat[i][j].getTexture() == &m_textures[WALL])
				fprintf(file, "=");
			else if (m_mat[i][j].getTexture() == &m_textures[GATE])
				fprintf(file, "#");
			else if (m_mat[i][j].getTexture() == &m_textures[FIRE])
				fprintf(file, "*");
			else if (m_mat[i][j].getTexture() == &m_textures[ORC])
				fprintf(file, "!");
			else if (m_mat[i][j].getTexture() == &m_textures[PORTAL])
				fprintf(file, "X");
			else if (m_mat[i][j].getTexture() == &m_textures[THRONE])
				fprintf(file, "@");			
		}
		fprintf(file, "\n");
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
	//m_mat[row][col].setFillColor(sf::Color::Black);
}

int Board::getSize()
{
	return m_size;
}

void Board::drawBoard(sf::RenderWindow &window)
{
	for (int i = 0; i < m_size ; i++)
		for (int j = 0; j < m_size; j++)
			window.draw(m_mat[i][j]);		
}
