#include "Board.h"

Board::Board() :m_size(0), m_lastRow(0), m_lastColumn(0)
{
	int size = 0;
	
	// filling texture vector
	initTextures();

	//opening file
	const char* fileName = "level.txt";
	FILE* file = fopen(fileName, "r");

	if (file != NULL) //if file is not empty
	{
		//reading size
		char c;
		int digit = 10;
		c = getc(file);
		size += (int)c - 48;
		c = getc(file);

		while(c != '\n')
		{
			size *= digit;
			size += (int)c - 48;
			c = getc(file);
		}

		//creating board to read into 
		char** fileBoard;
		fileBoard = new char* [size];

		for (int i = 0; i < size; i++)
			fileBoard[i] = new char[size];
		
		//reading board
		for (int row = 0; row < size; row++)
		{
			for (int col = 0; col < size; col++)
			{
				c = getc(file);
				fileBoard[row][col] = c;
			}
			c = getc(file);
		}

		//fill matrix with file board
		int square_size = (( BOARD_H  )/ size ) - 10; //set 500 to const
		m_mat = initMat(size, square_size);

		for (int row = 0; row < size; row++)
		{
			for (int col = 0; col < size; col++)
			{
				initSquare(row, col, square_size);
				int charObj = getCharObj(fileBoard[row][col]);
				if(charObj != -1)
					m_mat[row][col].setTexture(&m_textures[charObj]);
				else
				{
					m_mat[row][col].setTexture(nullptr);
					m_mat[row][col].setFillColor(BOARD_COLOR);
				}
			}
		}
		fclose(file);

		for (int i = 0; i < size; i++)
			delete [] fileBoard[i];
		delete [] fileBoard;
	}
	else //if file is empty
	{
		std::cout << "Please enter size of board: \n";
		std::cin >> size;

		int square_size = ((BOARD_H) / size) - 10; //set 500 to const

		//int square_size = 500 / size; //set 500 to const
		m_mat = initMat(size, square_size);

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				initSquare(i, j, square_size);
				m_mat[i][j].setTexture(NULL);
				m_mat[i][j].setFillColor(BOARD_COLOR);
			}
		}
	}
	m_size = size;
}

//-------------------------------------------------

void Board::saveBoard()const
{
	const char* fileName = "level";

	//opening file or creating file (overwrites if exists)
	FILE* file = fopen(fileName, "w+"); 

	//printing size to file
	fprintf(file, "%d\n", m_size);

	for (int i = 0; i < m_size; i++)
	{
		for (int j = 0; j < m_size; j++)
		{
			int obj = getObj(i, j);
			char c = (obj != -1) ? SIMBOLS[obj] : ' ';
			fputc(c, file);
			/*switch (obj)
			{
			case KING:
				fprintf(file, "K");
				break;
			case WIZARD:
				fprintf(file, "M");
				break;
			case WARRIOR:
				fprintf(file, "W");
				break;
			case THIEF:
				fprintf(file, "T");
				break;
			case WALL:
				fprintf(file, "=");
				break;
			case GATE:
				fprintf(file, "#");
				break;
			case FIRE:
				fprintf(file, "*");
				break;
			case ORC:
				fprintf(file, "!");
				break;
			case PORTAL:
				fprintf(file, "X");
				break;
			case THRONE:
				fprintf(file, "@");
				break;
			case KEY:
				fprintf(file, "F");
				break;
			default:
				fprintf(file, " ");
				break;
			}*/
		}
		fprintf(file, "\n");
	}
	fclose(file);
}

//-------------------------------------------------

void Board::clearBoard()
{
	for (int row = 0; row < m_size; row++)
		for (int col = 0; col < m_size; col++)
			deleteObjectOnBoard(row, col);
}

//-------------------------------------------------

void Board::deleteObjectOnBoard(int row, int col)
{
	m_mat[row][col].setTexture(NULL);
	//m_mat[row][col].setFillColor(sf::Color::White);
	m_mat[row][col].setFillColor(BOARD_COLOR);
}

//-------------------------------------------------

int Board::deleteObject(const sf::Vector2f& location)
{
	int deletedObj;
	for (int i = 0; i < m_size; i++)
	{
		for (int j = 0; j < m_size; j++)
		{
			if (m_mat[i][j].getGlobalBounds().contains(location))
			{
				deletedObj = getObj(i, j);
				deleteObjectOnBoard(i, j);
				return deletedObj;
			}
		}
	}
	return -1;
}

int Board::getObj(int i, int j)const
{
	if (m_mat[i][j].getTexture() == &m_textures[KING])
		return KING;
	else if (m_mat[i][j].getTexture() == &m_textures[WIZARD])
		return WIZARD;
	else if (m_mat[i][j].getTexture() == &m_textures[WARRIOR])
		return WARRIOR;
	else if (m_mat[i][j].getTexture() == &m_textures[THIEF])
		return THIEF;
	else if (m_mat[i][j].getTexture() == &m_textures[WALL])
		return WALL;
	else if (m_mat[i][j].getTexture() == &m_textures[GATE])
		return GATE;
	else if (m_mat[i][j].getTexture() == &m_textures[FIRE])
		return FIRE;
	else if (m_mat[i][j].getTexture() == &m_textures[ORC])
		return ORC;
	else if (m_mat[i][j].getTexture() == &m_textures[PORTAL])
		return PORTAL;
	else if (m_mat[i][j].getTexture() == &m_textures[THRONE])
		return THRONE;
	else if (m_mat[i][j].getTexture() == &m_textures[KEY])
		return KEY;
	else return - 1;
}

//-------------------------------------------------

int Board::getSize()const
{
	return m_size;
}

//-------------------------------------------------

std::vector<int> Board::getObjExists()const
{
	std::vector<int> objExists(NUM_OF_ICONS, 0);

	for (int i = 0; i < m_size; i++)
	{
		for (int j = 0; j < m_size; j++)
		{
			int obj = getObj(i, j);

			switch (obj)
			{
			case KING:
				objExists[KING]++;
				break;
			case WIZARD:
				objExists[WIZARD]++;
				break;
			case WARRIOR:
				objExists[WARRIOR]++;
				break;
			case THIEF:
				objExists[THIEF]++;
				break;
			case THRONE:
				objExists[THRONE]++;
				break;
			default:
				break;
			}
		}
	}
	return objExists;
}

//-------------------------------------------------

void Board::drawBoard(sf::RenderWindow &window)
{
	//int board_size = 500;
	//int square_size = ((BOARD_H + ) / m_size) - 10; //set 500 to const
	//int col_offset = (window.getSize().x - board_size) / 2;

	for (int i = 0; i < m_size ; i++)
		for (int j = 0; j < m_size; j++)
		{
			window.draw(m_mat[i][j]);
		}
}

//-------------------------------------------------

void Board::initTextures()
{
	m_textures.resize(NUM_OF_ICONS);
	for (int i = 0; i < NUM_OF_ICONS; i++)
	{
		m_textures[i].loadFromFile(PIC_NAMES[i] + ".png");
		m_textures[i].setSmooth(true);
	}


}

//-------------------------------------------------

void Board::initSquare(int row, int col, int square_size)
{
	int board_size = BOARD_H;
	//int square_size = 500 / m_size;
	//m_mat[row][col].setOutlineThickness(1);
	//m_mat[row][col].setOutlineColor(sf::Color::Black);
	int col_offset = (WINDOW_W - board_size) / 2;
	m_mat[row][col].setPosition(col * (square_size + 7 ) + col_offset, row * ( square_size + 7 ) + MENU_H + 15);
}

//-------------------------------------------------

std::vector<std::vector<sf::RectangleShape>> Board::initMat(int size, int square_size)
{
	sf::RectangleShape rect1(sf::Vector2f(square_size, square_size));
	std::vector<std::vector<sf::RectangleShape>> mat(size, std::vector<sf::RectangleShape>(size, rect1));
	return mat;
}

//-------------------------------------------------


int Board::getCharObj(char c)const
{
	switch (c)
	{
	case 'K':
		return KING;
	case 'M':
		return WIZARD;
	case 'W':
		return WARRIOR;
	case 'T':
		return THIEF;
	case '=':
		return WALL;
	case '#':
		return GATE;
	case '*':
		return FIRE;
	case '!':
		return ORC;
	case 'X':
		return PORTAL;
	case '@':
		return THRONE;
	case 'F':
		return KEY;
	default:
		return -1;
	}
	return -1;
}

//-------------------------------------------------

void Board::handleHover(const sf::Vector2f& location)
{
	for (int i = 0; i < m_size; i++)
	{
		for (int j = 0; j < m_size; j++)
		{
			if (m_mat[i][j].getGlobalBounds().contains(location) &&
				m_mat[i][j].getTexture() == nullptr)
			{
				if (m_mat[m_lastRow][m_lastColumn].getTexture())
					m_mat[m_lastRow][m_lastColumn].setFillColor(sf::Color::White);
				else
					m_mat[m_lastRow][m_lastColumn].setFillColor(BOARD_COLOR);

				m_mat[i][j].setFillColor(BOARD_HOVER_COLOR);
				m_lastRow = i;
				m_lastColumn = j;
				return;
			}
		}
	}
	if(m_mat[m_lastRow][m_lastColumn].getTexture())
		m_mat[m_lastRow][m_lastColumn].setFillColor(sf::Color::White);
	else
		m_mat[m_lastRow][m_lastColumn].setFillColor(BOARD_COLOR);

	//m_mat[m_lastRow][m_lastColumn].setFillColor();
}

//-------------------------------------------------

int Board::handleClick(const sf::Vector2f& location, int last_active)
{
	if (last_active == DELETE)
		return deleteObject(location);

	for (int row = 0; row < m_size; row++)
	{
		for (int col = 0; col < m_size; col++)
		{
			if (m_mat[row][col].getGlobalBounds().contains(location) &&	
				m_mat[row][col].getTexture() == nullptr)
			{
				//if(last_active != CLEAR && last_active != SAVE)
				m_mat[row][col].setTexture(&m_textures[last_active]);
				m_mat[row][col].setFillColor(sf::Color::White);
				return 1;
			}
		}
	}
	return -1;
}
