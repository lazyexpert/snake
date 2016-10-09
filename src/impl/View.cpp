#include <iostream>
#include <SFML/Graphics.hpp>

#include "../headers/View.hpp"
#include "../headers/Model.hpp"

using namespace std;
View :: View() {    
    cout<< "View instance created\n";        
    this->screenWidth = sf::VideoMode::getDesktopMode().width;
    this->screenHeight = sf::VideoMode::getDesktopMode().height;
    
    this->cellsInWidth = 30;
    this->cellsInHeight = 25;

    this->cellWidth = this->screenWidth / this->cellsInWidth;
    this->cellHeight = this->screenHeight / this->cellsInHeight;

    this->model = new Model(this->cellsInWidth, this->cellsInHeight);
}

void View :: start() {
    sf::RenderWindow window(sf::VideoMode(this->screenWidth, this->screenHeight), "SFML works!");
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();    
        window.display();
    }
}