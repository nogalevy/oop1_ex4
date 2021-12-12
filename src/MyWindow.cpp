#include "MyWindow.h"


//-------------------------------------------------

MyWindow::MyWindow() : m_window(sf::VideoMode(WINDOW_W, WINDOW_H), TITLE ), m_board(), m_menu()
{
    m_menu.setButtonData(m_board.getObjExists());
    setIcon();
    m_curr_char = KING;
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
            case sf::Event::MouseButtonPressed:
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
 
        m_window.clear(WINDOW_COLOR);
        m_menu.drawMenu(m_window);
        m_board.drawBoard(m_window);
        m_window.display();
    }
}

//-------------------------------------------------

int MyWindow::checkLocation(const sf::Vector2f& location)
{
    if (m_menu.isContain(location))
        return MENU;
    else
        return BOARD;
}

//-------------------------------------------------

void MyWindow::handleClick(const sf::Vector2f& location)
{
    if (checkLocation(location) == MENU)
    {
        m_menu.handleClick(location, m_curr_char);

        //save/clear if()
        if (m_curr_char == SAVE)
           m_board.saveBoard();

        else if (m_curr_char == CLEAR)
        {
           m_board.clearBoard();
           m_menu.resetBtnsExist(); 
           m_window.clear(WINDOW_COLOR);
           m_menu.drawMenu(m_window);
           m_board.drawBoard(m_window);
           m_window.display();
           m_board.setBoard();
        }
    }

    else if(checkLocation(location) == BOARD)
    {
        int deleted_obj;
        if (m_curr_char == DELETE)
        {
            deleted_obj = m_board.handleClick(location, m_curr_char);//takes m_curr_char which is delete button or character that can appear as much as we want
            if (deleted_obj >= 0)
                m_menu.setObjExist(false, deleted_obj);     
            return;
        }
        else
        {
            if ((m_curr_char != CLEAR) && (m_curr_char != SAVE))
            {
                if (m_menu.canAddObj(m_curr_char))
                {
                    if (m_board.handleClick(location, m_curr_char) > 0)
                    {
                        m_menu.setObjExist(true, m_curr_char);
                    }
                }
            }
        }
    }
}

//-------------------------------------------------

void MyWindow::handleHover(const sf::Vector2f& location)
{
    /*
        send m_curr_char - in handleHover of board, add tnai for hovering over object if m_curr_char == delete
    */

    //sf::Cursor cursor;
    if (checkLocation(location) == BOARD)
    {
        m_board.handleHover(location, m_curr_char);
        /*if (cursor.loadFromSystem(sf::Cursor::Arrow))
            m_window.setMouseCursor(cursor);*/
    }
    
   /* else
    {
        if (cursor.loadFromSystem(sf::Cursor::Hand))
            m_window.setMouseCursor(cursor);
    }*/
}

//-------------------------------------------------

void MyWindow::setIcon()
{
    m_image = sf::Image{};
    m_image.loadFromFile("king.png");
    m_window.setIcon(m_image.getSize().x, m_image.getSize().y, m_image.getPixelsPtr());
}