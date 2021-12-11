#pragma once
#include "Board.h"
#include "Menu.h"
#include <SFML/Graphics.hpp>
#include "numof.h"
#include "view_constants.h"
#include <iostream>


class MyWindow
{
public:
    MyWindow();
    void run();

private:
    void handleClick(const sf::Vector2f& location);
    void handleHover(const sf::Vector2f& location);
    int checkLocation(const sf::Vector2f& location);

    //Members
    int m_curr_char;
    sf::RenderWindow m_window;
    Menu m_menu; 
    Board m_board;   
};
