#include "Menu.h"

Menu::Menu() : m_height(200), m_width(200) //make 200 consts
{
}

void Menu::setSize(int height, int width)
{
	m_height = height;
	m_width = width;
}

int Menu::getHeight()
{
	return m_height;
}
