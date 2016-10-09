#include <iostream>
#include <SFML/Graphics.hpp>

#include "../headers/View.hpp"

using namespace std;
View :: View() {    
    cout<< "View instance created";
    cout << sf::VideoMode::getDesktopMode().width;    
}

void View :: start() {
    sf::RenderWindow window(sf::VideoMode(5000, 5000), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
}