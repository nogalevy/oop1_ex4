#include "Button.h"
#include "view_constants.h"

const int INFINITIE = -1;

Button::Button() 
	: m_max(INFINITIE), m_btn_width(D_BTN_WIDTH), m_btn_height(D_BTN_HEIGHT), m_exist(0), m_isClicked(false)
{}

//TODO: add int exist
Button::Button(int max, Position position, sf::Texture texture)
	: m_max(max), m_btn_width(D_BTN_WIDTH), m_btn_height(D_BTN_HEIGHT), m_texture(texture), m_isClicked(false), m_exist(0)
{}

sf::RectangleShape Button::createBtn(int row, int col) const
{
	sf::RectangleShape new_btn(sf::Vector2f(m_btn_width, m_btn_height));
	new_btn.setTexture(&m_texture);
	new_btn.setPosition(row, col);

	if (m_isClicked)
	{
		new_btn.setOutlineThickness(5);
		new_btn.setOutlineColor(sf::Color::Black);
	}
	else
	{
		new_btn.setOutlineThickness(0);
	}
	return new_btn;
}

void Button::setBtnSize(int width, int height)
{
	m_btn_width = width;
	m_btn_height = height;
}

void Button::setBtnTexture(sf::Texture texture)
{
	m_texture = texture;
}

void Button::setIsClicked(const bool b)
{
	m_isClicked = b;
}

void Button::setMax(const int max)
{
	m_max = max;
}

void Button::setExist(bool op)
{
	op ? m_exist++ : m_exist--;
}

bool Button::canAddToBoard() const
{
	return m_max > m_exist;
}

