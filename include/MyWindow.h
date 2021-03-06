#pragma once
#include "Board.h"
#include "Menu.h"
#include <SFML/Graphics.hpp>
#include "numof.h"
#include "view_constants.h"
#include <iostream>

enum parts { MENU, BOARD, NONE };

class MyWindow
{
public:
    MyWindow();
    void run();

private:
    void handleClick(const sf::Vector2f& location);
    void handleHover(const sf::Vector2f& location);
    int checkLocation(const sf::Vector2f& location);
    void setIcon();

    //Members
    int m_curr_char;
    sf::RenderWindow m_window;
    sf::Image m_image;
    Menu m_menu; 
    Board m_board;   
};
