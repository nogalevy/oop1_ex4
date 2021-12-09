#include "Board.h"

Board::Board() :m_size(0), m_lastRow(0), m_lastColumn(0)
{
	std::cout << "here\n";

	int size = 0;

	// filling texture vector
	m_textures.resize(NUM_OF_ICONS);
	for (int i = 0; i < NUM_OF_ICONS; i++)
		m_textures[i].loadFromFile(PIC_NAMES[i] + ".png");
	std::cout << "here\n";

	const char* fileName = "level.txt";
	std::cout << "here\n";

	FILE* file = fopen(fileName, "r");

	if (file != NULL) //if file is not empty
	{
		std::cout << "here\n";
		char c;
		int digit = 10;
		c = getc(file);
		std::cout<< "Char read: " << int(c) - 48 << "\n";
		size += (int)c - 48;
		c = getc(file);
		std::cout << "Char read: " << (int)c - 48 << "\n";

		while(c != '\n')
		{
			size *= digit;
			size += (int)c - 48;
			c = getc(file);
			std::cout << "Char read: " << (int)c - 48 << "\n";

		}
		//read from file into matrix
		std::cout <<"Size is:" << size << "\n";

		const int newsize = size;
		char** fileBoard;
		fileBoard = new char* [size];

		for (int i = 0; i < size; i++)
			fileBoard[i] = new char[size];

		//reading 
		c = getc(file);
		std::cout << c; //null ...why??
		//c = getc(file);
		//std::cout << c; //newline

		
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
				m_mat[row][col].setOutlineThickness(1);
				m_mat[row][col].setOutlineColor(sf::Color::Black);
				m_mat[row][col].setPosition(col * square_size, row * square_size + CON_HEIGHT + 20);


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
				case 'F':
					m_mat[row][col].setTexture(&m_textures[KEY]);
					break;
				default:
					m_mat[row][col].setTexture(NULL);

					break;
				}
			}
		}
		std::cout << "here1\n";
		fclose(file);
		for (int i = 0; i < size; i++)
			delete [] fileBoard[i];
		delete [] fileBoard;
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
				m_mat[i][j].setOutlineThickness(1);
				m_mat[i][j].setOutlineColor(sf::Color::Black);
				m_mat[i][j].setTexture(NULL);
			}
		}
	}
	m_size = size;
}

//-------------------------------------------------

void Board::saveBoard()
{
	const char* fileName = "level";

	//opening file or creating file (overwrites if exists)
	FILE* file = fopen(fileName, "w+"); 

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
			else if (m_mat[i][j].getTexture() == &m_textures[KEY])
				fprintf(file, "F");
		}
		fprintf(file, "\n");
	}
	fclose(file);
	for (int i = 0; i < m_size; i++)
		delete[] fileBoard[i];
	delete[] fileBoard;
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
	m_mat[row][col].setFillColor(sf::Color::White);
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
				std::cout << "get obj " << deletedObj << "\n";
				deleteObjectOnBoard(i, j);
				return deletedObj;
			}
		}
	}
	return -1;
}

int Board::getObj(int i, int j)
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
	std::vector<int> objExists(NUM_OF_ICONS);

	for (int i = 0; i < NUM_OF_ICONS; i++)
		objExists[i] = 0;

	for (int i = 0; i < m_size; i++)
	{
		for (int j = 0; j < m_size; j++)
		{

			if (m_mat[i][j].getTexture() == &m_textures[KING])
				objExists[KING]++;
			else if (m_mat[i][j].getTexture() == &m_textures[WIZARD])
				objExists[WIZARD]++;
			else if (m_mat[i][j].getTexture() == &m_textures[WARRIOR])
				objExists[WARRIOR]++;
			else if (m_mat[i][j].getTexture() == &m_textures[THIEF])
				objExists[THIEF]++;
			else if (m_mat[i][j].getTexture() == &m_textures[THRONE])
				objExists[KING]++;
		}
	}

	return objExists;
}

//-------------------------------------------------

void Board::drawBoard(sf::RenderWindow &window)
{
	int board_size = 500;
	int square_size = 500 / m_size;
	//int square_size = (D_MENU_WIDTH - 500) / m_size;
	int col_offset = (window.getSize().x - board_size) / 2;

	for (int i = 0; i < m_size ; i++)
		for (int j = 0; j < m_size; j++)
		{
			m_mat[i][j].setPosition(j * square_size + col_offset, i * square_size + CON_HEIGHT + 20);
			window.draw(m_mat[i][j]);

		}
}

//-------------------------------------------------

void Board::handleHover(const sf::Vector2f& location)
{
	for (int i = 0; i < m_size; i++)
	{
		for (int j = 0; j < m_size; j++)
		{
			if (m_mat[i][j].getGlobalBounds().contains(location))
			{
				//check if empty
				if (m_mat[i][j].getTexture() == nullptr)
				{
					m_mat[m_lastRow][m_lastColumn].setFillColor(sf::Color::White);
					m_mat[i][j].setFillColor(sf::Color::Cyan);
					m_lastRow = i;
					m_lastColumn = j;
					return;
				}
			}
		}
	}
	m_mat[m_lastRow][m_lastColumn].setFillColor(sf::Color::White);
}
//-------------------------------------------------

int Board::handleClick(const sf::Vector2f& location, int last_active)
{
	if (last_active == DELETE)
	{
		return deleteObject(location);
		
	}

	for (int row = 0; row < m_size; row++)
	{
		for (int col = 0; col < m_size; col++)
		{
			if (m_mat[row][col].getGlobalBounds().contains(location))
			{
				if (m_mat[row][col].getTexture() == nullptr)
				{
					switch (last_active)
					{
					case KING:
						m_mat[row][col].setTexture(&m_textures[KING]);
						break;
					case WIZARD:
						m_mat[row][col].setTexture(&m_textures[WIZARD]);
						break;
					case WARRIOR:
						m_mat[row][col].setTexture(&m_textures[WARRIOR]);
						break;
					case THIEF:
						m_mat[row][col].setTexture(&m_textures[THIEF]);
						break;
					case WALL:
						m_mat[row][col].setTexture(&m_textures[WALL]);
						break;
					case GATE:
						m_mat[row][col].setTexture(&m_textures[GATE]);
						break;
					case FIRE:
						m_mat[row][col].setTexture(&m_textures[FIRE]);
						break;
					case ORC:
						m_mat[row][col].setTexture(&m_textures[ORC]);
						break;
					case PORTAL:
						m_mat[row][col].setTexture(&m_textures[PORTAL]);
						break;
					case THRONE:
						m_mat[row][col].setTexture(&m_textures[THRONE]);
						break;
					case KEY:
						m_mat[row][col].setTexture(&m_textures[KEY]);
						break;
					default:
						m_mat[row][col].setTexture(NULL);
						break;
					}
				}
			}
		}
	}
	return -1;
}
