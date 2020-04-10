// Snake.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <SFML\Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "Snake");
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Green);

        // draw everything here...
        // window.draw(...);

        // end the current frame
        window.display();
    }

        return 0;
}

