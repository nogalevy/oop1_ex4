#include "Menu.h"


//-------------------------------------------------

Menu::Menu() : m_width(WINDOW_W), m_height(MENU_H) ,m_container(sf::Vector2f(WINDOW_W, MENU_H))//make 200 consts
{
	m_container.setFillColor(MENU_COLOR);
	m_texture.resize(NUM_OF_ICONS + GAME_BTN_NUM);

	for (int i = 0; i < NUM_OF_ICONS + GAME_BTN_NUM; ++i)
		m_texture[i].loadFromFile(PIC_NAMES[i] + ".png");

	m_characters_btns.resize(NUM_OF_ICONS);
	for (int i = 0; i < NUM_OF_ICONS; i++)
	{
		m_characters_btns[i].setBtnSize(BTN_W, BTN_H);
		m_characters_btns[i].setBtnTexture(m_texture[i]);
	}

	m_game_btns.resize(GAME_BTN_NUM);
	for (int i = 0; i < GAME_BTN_NUM; i++)
	{
		m_game_btns[i].setBtnSize(BTN_W, BTN_H);
		m_game_btns[i].setBtnTexture(m_texture[(NUM_OF_ICONS + i )]);
	}
}
//
////-------------------------------------------------
//// 
//Menu::Menu(int width) : m_container(sf::Vector2f(width, D_MENU_HEIGHT)), m_height(MENU_H) , m_width(width)
//{
//	for (int i = 0; i < NUM_OF_ICONS; ++i)
//		m_texture[i].loadFromFile(PIC_NAMES[i] + ".png");
//
//	//check width to do responsive
//	setSize(width, MENU_H + 20);
//}

//-------------------------------------------------

void Menu::setSize(int height, int width)
{
	m_height = height;
	m_width = width;
}

//-------------------------------------------------

int Menu::getHeight()const
{
	return m_height;
}

//-------------------------------------------------

void Menu::drawMenu(sf::RenderWindow& window) const
{
	int space = (WINDOW_W - BTN_W * NUM_OF_ICONS) / NUM_OF_ICONS; //space between obj buttons
	window.draw(m_container);
	for (int i = 0; i < NUM_OF_ICONS; i++)
	{
		window.draw(m_characters_btns[i].createBtn(i * (BTN_W + BTN_SPACE), 0));
	}
	for (int i = 0; i < GAME_BTN_NUM; i++)
	{
		window.draw(m_game_btns[i].createBtn(i * ( BTN_W + BTN_SPACE) , BTN_H + 40));
	}
}

//-------------------------------------------------

void Menu::setButtonData(std::vector<int> objExists)
{
	for (int i = 0; i < NUM_OF_ICONS; i++)
	{
		if (objExists[i] != 0)
			std::cout << "setexist to " << i << " to exist =" << objExists[i] << std::endl;
			m_characters_btns[i].initExists(objExists[i]);

		switch (i)
		{
		case KING:
		case THIEF:
		case WARRIOR:
		case THRONE:
		case WIZARD:
			m_characters_btns[i].initMax(1);
			break;
		default:
			break;
		}
	}
}

//-------------------------------------------------

bool Menu::isContain(const sf::Vector2f& location)const
{
	return m_container.getGlobalBounds().contains(location);
}

//-------------------------------------------------

void Menu::handleClick(const sf::Vector2f& location, int &last_active)
{
	for (int i = 0; i < NUM_OF_ICONS; i++)
	{
		sf::RectangleShape curr_rect = m_characters_btns[i].createBtn(i * (BTN_W + BTN_SPACE), 0);
		if (curr_rect.getGlobalBounds().contains(location))
		{
			if (last_active < NUM_OF_ICONS + GAME_BTN_NUM && last_active >= 0)
			{
				if (last_active < NUM_OF_ICONS)
				{
					m_characters_btns[last_active].setIsClicked(false);
				}
				else if (last_active >= NUM_OF_ICONS)
				{
					m_game_btns[last_active - NUM_OF_ICONS].setIsClicked(false);
				}
			}		
			m_characters_btns[i].setIsClicked(true);
			last_active = i;
			return;
		}
	}

	for (int i = 0; i < GAME_BTN_NUM; i++)
	{
		sf::RectangleShape curr_rect = m_game_btns[i].createBtn(i * (BTN_W + BTN_SPACE), BTN_H + 40);
		if (curr_rect.getGlobalBounds().contains(location))
		{
			if (last_active  < NUM_OF_ICONS + GAME_BTN_NUM && last_active >= 0)
			{
				if (last_active < NUM_OF_ICONS)
				{
					m_characters_btns[last_active].setIsClicked(false);
				}
				else if (last_active >= NUM_OF_ICONS)
				{
					m_game_btns[last_active - NUM_OF_ICONS].setIsClicked(false);
				}
			}
			m_game_btns[i].setIsClicked(true);
			last_active = NUM_OF_ICONS + i;
		}
	}
}

//--------------------------------------------

bool Menu::canAddObj(int character)const
{
	return m_characters_btns[character].canAddToBoard();
}

void Menu::resetBtnsExist() 
{
	for (int i = 0; i < NUM_OF_ICONS; i++)
	{
		m_characters_btns[i].initExists(0);
	}
}

//--------------------------------------------

void Menu::setObjExist(bool b, int character)
{
	m_characters_btns[character].setExist(b);
}
