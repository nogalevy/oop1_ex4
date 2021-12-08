#include "ObjBtn.h"

ObjBtn::ObjBtn() : Button()
{
	m_max = 1;
	m_exist = 0;
}

ObjBtn::ObjBtn(int max, sf::Texture texture) : Button(texture)
{
	m_max = max;
	m_exist = 0;
}

void ObjBtn::setMax(const int max)
{
	m_max = max;
}

void ObjBtn::setExist(bool op)
{
	op ? m_exist++ : m_exist--;
}

bool ObjBtn::canAddToBoard() const
{
	return m_max > m_exist;
}

