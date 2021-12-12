#include "ObjBtn.h"


//-------------------------------------------------

ObjBtn::ObjBtn() : Button()
{
	m_max = -1;
	m_exist = 0;
}

//-------------------------------------------------

void ObjBtn::setMax(const int max)
{
	m_max = max;
}

//-------------------------------------------------

void ObjBtn::setExist(bool op)
{
	op ? m_exist++ : m_exist--;
}

//-------------------------------------------------

bool ObjBtn::canAddToBoard() const
{
	return m_max == -1 ? true : m_max > m_exist;
}

//-------------------------------------------------

void ObjBtn::initExists(int num)
{
	m_exist = num;
}

//-------------------------------------------------

void ObjBtn::initMax(int num)
{
	m_max = num;
}

//-------------------------------------------------

int ObjBtn::getExist()const
{
	return m_exist;
}
