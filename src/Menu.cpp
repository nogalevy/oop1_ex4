#include "Menu.h"

//-------------------------------------------------

Menu::Menu() : m_width(DEFAULT_WIDTH), m_height(DEFAULT_HEIGHT) ,m_container(sf::Vector2f(1280, 760))//make 200 consts
{
	m_container.setFillColor(sf::Color::Color(23, 45, 65));
	m_texture.resize(NUM_OF_ICONS);

	for (int i = 0; i < NUM_OF_ICONS; ++i)
		m_texture[i].loadFromFile(m_char_names[i] + ".png");


	m_characters_btns.resize(NUM_OF_ICONS);
	for (int i = 0; i < NUM_OF_ICONS; i++)
	{
		m_characters_btns[i].setSize(sf::Vector2f(DEFAULT_BTN_WIDTH, DEFAULT_BTN_HEIGHT));
		m_characters_btns[i].setTexture(&m_texture[i]);
		m_characters_btns[i].setPosition(i * DEFAULT_BTN_WIDTH, 0);
	}
}

//-------------------------------------------------

Menu::Menu(int width) : m_container(sf::Vector2f(width, DEFAULT_HEIGHT)), m_height(DEFAULT_HEIGHT) , m_width(width)
{
	for (int i = 0; i < NUM_OF_ICONS; ++i)
		m_texture[i].loadFromFile(m_char_names[i] + ".png");

	//check width to do responsive
	setSize(width, DEFAULT_HEIGHT);
}

//-------------------------------------------------

void Menu::setSize(int height, int width)
{
	m_height = height;
	m_width = width;
}

//-------------------------------------------------

int Menu::getHeight()
{
	return m_height;
}

//-------------------------------------------------

void Menu::drawMenu(sf::RenderWindow& window) const
{
	window.draw(m_container);
	for (int i = 0; i < NUM_OF_ICONS; i++)
	{
		window.draw(m_characters_btns[i]);
	}
}
