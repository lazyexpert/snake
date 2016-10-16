#include <iostream>
#include <SFML/Graphics.hpp>

#include "../headers/View.hpp"
#include "../headers/Model.hpp"

using namespace std;
View :: View() 
{    
    cout<< "View instance created\n";        
    
    this->calculateDimensions();

    this->model = new Model(this->cellsInWidth, this->cellsInHeight);
}

void View :: calculateDimensions() {
    this->screenWidth = sf::VideoMode::getDesktopMode().width;
    this->screenHeight = sf::VideoMode::getDesktopMode().height;
    
    this->cellsInWidth = 30;
    this->cellsInHeight = 25;

    this->cellWidth = this->screenWidth / this->cellsInWidth;
    this->cellHeight = this->screenHeight / this->cellsInHeight;

    cout<<"\nSet new dimensions!\n";
    cout<<"Window width: "<< this->screenWidth<<endl;
    cout<<"Window height: "<< this->screenHeight<<endl;
    cout<<"Cell width: "<< this->cellWidth<<endl;
    cout<<"Cell height: "<< this->cellHeight<<endl;
}

void View :: handleMouseClick(int x, int y) {
    // Make sure we deal left button
    
    // if (event.Button == sf::Mouse::Button.Left) 
    // {
        cout<<"Catch left mouse button"<<endl;
        cout<<"x: "<<x<<endl;
        cout<<"y: "<<y<<endl<<endl;
    // } 
    // else 
    // {
    //     cout<<"Catch mouse click. Not left button :)"<<endl;
    // }
}

void View :: start()
{
    sf::RenderWindow window(sf::VideoMode(this->screenWidth, this->screenHeight), "SFML works!");
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // check the type of the event...
            switch (event.type)
            {
                // window closed
                case sf::Event::Closed:
                    window.close();
                    break;
                
                // catch window resize                
                case sf::Event::Resized:
                     this->calculateDimensions();
                     break;
                
                // Mouse button click
                case sf::Event::MouseButtonPressed:
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                        this->handleMouseClick(event.mouseButton.x, event.mouseButton.y);
                    }                    
                    break;

                // key up
                case sf::Event::KeyReleased:
                    if (event.key.code == sf::Keyboard::Escape)
                    {
                        std::cout << "Pressed Escape\n";                        
                    }
                    cout << "Keypress\n";
                    break;

                // we don't process other types of events
                default:
                    break;
            }
        }

        window.setVerticalSyncEnabled(true);
        window.clear();    
        window.display();
    }
}