#include "MyWindow.h"

void MyWindow::run()
{
    while (m_window.isOpen())
    {
        m_window.clear();
        
       // draw();
            /*
                m_menu.draw(m_window);
                m_board.draw(m_window);
                     for (auto i = size_t(0); i < m_texts.size(); ++i)
                    {
                        window.draw(m_texts[i]);
                    }     
            */
        m_window.display();

        if (auto event = sf::Event{}; m_window.waitEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                m_window.close();
                break;
            case sf::Event::MouseButtonPressed:
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    /*std::cout << "the right button was pressed" << std::endl;
                    std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                    std::cout << "mouse y: " << event.mouseButton.y << std::endl;

                    auto location = m_window.mapPixelToCoords(
                        { event.mouseButton.x, event.mouseButton.y });

                    */
                    
                    // check position - Board ? Menu ?
                    // no need to check x
                    // save in const the menu border - topright + bottomleft ?
                    // borad depend on the current board size

                }
               
            }
            }
        }
    }
}

