#include "Button.h"
//#include "view_constants.h"

const int INFINITIE = -1; //infinity || infinite Tali:Q: where do you want to put this?

//-------------------------------------------------

Button::Button() 
	: m_btn_width(BTN_W), m_btn_height(BTN_H), m_isClicked(false)
{}

//-------------------------------------------------

Button::Button(sf::Texture texture)
	: m_btn_width(BTN_W), m_btn_height(BTN_H), m_texture(texture), m_isClicked(false)
{}

//-------------------------------------------------

sf::RectangleShape Button::createBtn(int row, int col) const
{
	sf::RectangleShape new_btn(sf::Vector2f(m_btn_width, m_btn_height));
	new_btn.setTexture(&m_texture);
	new_btn.setPosition(row, col);

	if (m_isClicked)
	{
		new_btn.setFillColor(sf::Color::Color(255, 255, 255, 255));

		new_btn.setOutlineThickness(8);
		new_btn.setOutlineColor(sf::Color::Color(114, 150, 158));
	}
	else
	{
		new_btn.setFillColor(sf::Color::Color(219, 249, 255, 215));
		new_btn.setOutlineThickness(0);
	}
	return new_btn;
}

//-------------------------------------------------

void Button::setBtnSize(int width, int height)
{
	m_btn_width = width;
	m_btn_height = height;
}

//-------------------------------------------------

void Button::setBtnTexture(sf::Texture texture)
{
	m_texture = texture;
}

//-------------------------------------------------

void Button::setIsClicked(const bool b)
{
	m_isClicked = b;
}
