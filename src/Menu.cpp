#include "Menu.h"


//-------------------------------------------------

Menu::Menu() : m_width(D_MENU_WIDTH), m_height(D_MENU_HEIGHT) ,m_container(sf::Vector2f(1280, CON_HEIGHT))//make 200 consts
{
	m_container.setFillColor(MENU_COLOR);
	m_texture.resize(NUM_OF_ICONS + GAME_BTN_NUM);

	for (int i = 0; i < NUM_OF_ICONS + GAME_BTN_NUM; ++i)
		m_texture[i].loadFromFile(PIC_NAMES[i] + ".png");

	m_characters_btns.resize(NUM_OF_ICONS);
	for (int i = 0; i < NUM_OF_ICONS; i++)
	{
		m_characters_btns[i].setBtnSize(D_BTN_WIDTH, D_BTN_HEIGHT);
		m_characters_btns[i].setBtnTexture(m_texture[i]);
	}

	m_game_btns.resize(GAME_BTN_NUM);
	for (int i = 0; i < GAME_BTN_NUM; i++)
	{
		m_game_btns[i].setBtnSize(D_BTN_WIDTH *0.7, D_BTN_HEIGHT * 0.7);
		m_game_btns[i].setBtnTexture(m_texture[(NUM_OF_ICONS + i )]);
	}
}

//-------------------------------------------------

Menu::Menu(int width) : m_container(sf::Vector2f(width, D_MENU_HEIGHT)), m_height(CON_HEIGHT) , m_width(width)
{
	for (int i = 0; i < NUM_OF_ICONS; ++i)
		m_texture[i].loadFromFile(PIC_NAMES[i] + ".png");

	//check width to do responsive
	setSize(width, CON_HEIGHT + 20);
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
		window.draw(m_characters_btns[i].createBtn(i * D_BTN_WIDTH, 0));
	}
	for (int i = 0; i < GAME_BTN_NUM; i++)
	{
		window.draw(m_game_btns[i].createBtn(i * D_BTN_WIDTH + i * 20, D_BTN_HEIGHT + 20 + 20));
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

bool Menu::isContain(const sf::Vector2f& location)
{
	return m_container.getGlobalBounds().contains(location);
}

//-------------------------------------------------

void Menu::handleClick(const sf::Vector2f& location, int &last_active)
{

	for (int i = 0; i < NUM_OF_ICONS; i++)
	{
		sf::RectangleShape curr_rect = m_characters_btns[i].createBtn(i * D_BTN_WIDTH, 0);
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
			std::cout << "exist : " << m_characters_btns[i].getExist() << std::endl;
			last_active = i;
			return;
		}

	}

	for (int i = 0; i < GAME_BTN_NUM; i++)
	{
		sf::RectangleShape curr_rect = m_game_btns[i].createBtn(i * D_BTN_WIDTH + i * 20, D_BTN_HEIGHT + 20 + 20);
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

bool Menu::canAddObj(int character)
{
	return m_characters_btns[character].canAddToBoard();
}

void Menu::setObjExist(bool b, int character)
{
	m_characters_btns[character].setExist(b);
}
