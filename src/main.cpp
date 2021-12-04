//#include "MyWindow.h"
#include <SFML/Graphics.hpp>
#include <iostream>

//int main()
//{
//    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
//    sf::CircleShape shape(100.f);
//    shape.setFillColor(sf::Color::Green);
//
//    while (window.isOpen())
//    {
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//
//        window.clear();
//        window.draw(shape);
//        window.display();
//    }
//
//    return 0;
//}

int main()
{
    //auto my_window = MyWindow(); // need

    //my_window.run(); // need

    //------- try - noga - draw matrix of 5X5 squares with image background ----------
    int window_size = 500;
    sf::RenderWindow window(sf::VideoMode(window_size, window_size), "SFML works!");
    //sf::RectangleShape shape(sf::Vector2f(120, 50));
    //shape.setFillColor(sf::Color::Green);
    // 
    //==  we can load as image - whats the difference?
    //sf::Image image; 
    //image.loadFromFile("texture1.jpg");
    // 
    // declare texture of shape
    sf::Texture texture;
    texture.loadFromFile("texture1.jpg"); // this image in 'images' folder 

    int size = 5; //size of rows and cols
    int square_size = window_size / size; //calc the size of each square
    sf::RectangleShape rect1(sf::Vector2f(square_size, square_size)); 
    //vector of vector with size = 5 and deafault value of rect is the rect1 above
    std::vector<std::vector<sf::RectangleShape>> mat(size, std::vector<sf::RectangleShape>(size, rect1)); 

    //set texture and position for each rect - 
    //position - calc the position by its index and the size of the rect
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            mat[i][j].setPosition(i * square_size, j * square_size);
            mat[i][j].setTexture(&texture);
        }
    }

    /*if (!texture.loadFromFile("./texture1.jpg"))
    {
        std::cerr << "image not found\n";
        return -1;
    }*/

    //shape.setTexture(&texture);

    while (window.isOpen())
    {
        sf::Event event;
        //some event 
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    
        window.clear();
        //window.draw(shape);

        //draw aall the squares
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                window.draw(mat[i][j]);
            }
        }

        window.display(); //display alll
    }

    return EXIT_SUCCESS;
}