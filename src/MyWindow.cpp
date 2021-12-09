#include "MyWindow.h"
#include <iostream>

enum parts {MENU, BOARD, NONE};
MyWindow::MyWindow() : m_window(sf::VideoMode(D_MENU_WIDTH, 760), "The Window" ), m_board(), m_menu() //make 200 const
{
    //int square_size = (D_MENU_WIDTH - 500) / m_size;

    //m_board(m_menu.getHeight());
    m_menu.setButtonData(m_board.getObjExists());
    int windowHeight = m_menu.getHeight() + (m_board.getSize()) +  100 ;
    m_window.setSize(sf::Vector2u(D_MENU_WIDTH, windowHeight));
    m_curr_char = -1;
}

//-------------------------------------------------

void MyWindow::run()
{
    while (m_window.isOpen())
    {
        sf::Event event;
        sf::Vector2f location;

        if(event = sf::Event{}; m_window.waitEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                m_window.close();
                break;
            case sf::Event::MouseButtonReleased:
            {
                location = m_window.mapPixelToCoords(
                    { event.mouseButton.x, event.mouseButton.y });

                switch (event.mouseButton.button)
                {
                case sf::Mouse::Button::Left:
                    handleClick(location);
                    break;
                }
                break;
            }
            case sf::Event::MouseMoved:
            {
                location = m_window.mapPixelToCoords(
                    { event.mouseMove.x, event.mouseMove.y });
                handleHover(location);
                break;
            }
            default:
                break;
            }
        }

        m_window.clear(sf::Color::White);

        m_menu.drawMenu(m_window);
        m_board.drawBoard(m_window);

        m_window.display();
    }
}

//void MyWindow::run()
//{
//    while (m_window.isOpen())
//    {
//        //m_window.clear();
//       // draw();
//        /*
//        m_menu.draw(m_window);
//                for (auto i = size_t(0); i < m_texts.size(); ++i)
//            {
//                window.draw(m_texts[i]);
//            }
//        */
//
//        if (auto event = sf::Event{}; m_window.waitEvent(event))
//        {
//            //switch (event.type)
//            //{
//            //case sf::Event::Closed:
//            //    m_window.close();
//            //    break;
//            //case sf::Event::MouseButtonPressed:
//            //{
//            //    if (event.mouseButton.button == sf::Mouse::Left)
//            //    {
//            //        /*std::cout << "the right button was pressed" << std::endl;
//            //        std::cout << "mouse x: " << event.mouseButton.x << std::endl;
//            //        std::cout << "mouse y: " << event.mouseButton.y << std::endl;
//
//            //        auto location = m_window.mapPixelToCoords(
//            //            { event.mouseButton.x, event.mouseButton.y });
//
//            //        */
//            //
//            //        // check position - Board ? Menu ?
//            //        // no need to check x
//            //        // save in const the menu border - topright + bottomleft ?
//            //        // borad depend on the current board size
//
//            //    }
//            //
//            //}
//            //}
//        }
//        m_window.clear();
//
//       // m_board.drawBoard(m_window);
//        for (int i = 0; i < 5; i++)
//        {
//            for (int j = 0; j < 5; j++)
//            {
//                m_window.draw(m_board.m_mat[i][j]);
//            }
//        }
//        m_window.display();
//    }
//}

int MyWindow::checkLocation(const sf::Vector2f& location)
{
    if (m_menu.isContain(location))
    {
        return MENU;
    }
    else
        return BOARD;
}

//-------------------------------------------------

void MyWindow::handleClick(const sf::Vector2f& location)
{
    if (checkLocation(location) == MENU)
    {
        m_menu.handleClick(location, m_curr_char);
        std::cout << "press on " << PIC_NAMES[m_curr_char] << std::endl;

        //save/clear if()
        if (m_curr_char == SAVE)
           m_board.saveBoard();

        else if (m_curr_char == CLEAR)
           m_board.clearBoard();

    }

    else if(checkLocation(location) == BOARD)
    {

        // if m_char ==  KING, MAGE, WARRIOR, THIEF, THRONE
            //if  (can add to board)
                //m_board.handleClick(location, m_curr_char)
        //else
            //m_board.handleClick(location, m_curr_char) -> takes m_curr_char which is delete button or character that can appear as much as we want
    }
}

//-------------------------------------------------

void MyWindow::handleHover(const sf::Vector2f& location)
{
    if (checkLocation(location) == BOARD)
    {
        m_board.handleHover(location);
    }
}
