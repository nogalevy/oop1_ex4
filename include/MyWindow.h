#pragma once
#include "Board.h"
#include "Menu.h"
#include <SFML/Graphics.hpp>


class MyWindow
{
public:
    MyWindow();
    void run();

private:
    void handleClick(const sf::Event::MouseButtonEvent& event);
    //sf::CircleShape m_shape;

    //Members
    sf::RenderWindow m_window;
    Menu m_menu; 
    Board m_board;
};

/*
    constructor: 

    MyWindow(): m_board(Board(tesx.t....

    m_board.openFile() //if cant open, get size from user
    m_board.getBoardFromFile() //if opened/exists - gets board and prints to window
        checks if Board.txt exist 
            1. false = window is clear (without board / empty) + ask from user the width
                and height of board and then creates the board
            2. true = load file to board 

    run
    open window
    close window 
    clear window
    color winndow
    size window - constructor? - by user input
    draw window
    handle click - when get event of click check position and send to the relevant
                   member to handle that

                   - get click event on menu - get from menu the button in this position
                        if clear so clear save -save from window 
    read file

*/