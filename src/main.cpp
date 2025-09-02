#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>


void HandlingUIMenu(bool& startGame) {
    sf::RenderWindow ui_menu(sf::VideoMode({800u, 800u}), "Chess Game");
    ui_menu.setFramerateLimit(144);


    while (ui_menu.isOpen())
    {
        while(const std::optional event = ui_menu.waitEvent(500ms)) {
            if (event->is<sf::Event::Closed>())
                ui_menu.close();


            if (const auto* mouseEvent = event->getIf<sf::Event::MouseButtonPressed>())
            {
                if (mouseEvent->button == sf::Mouse::Button::Left)
                {
                    cout << "Left Mouse Button Clicked" << std::endl;
                }
            }
        }
        
        ui_menu.clear(sf::Color::Black);
        ui_menu.display();
    }
} 

int main()
{

    // Opening the UI menu window
    bool start_game = false;
    HandlingUIMenu(start_game);
    if (!start_game) {
        return 1;
    }

    std::cout << "UI Menu closed" << std::endl;

    /*
    sf::RenderWindow window(sf::VideoMode({800u, 800u}), "Chess Game");
    window.setFramerateLimit(144);


    while (window.isOpen())
    {
        while(const std::optional event = window.waitEvent(500ms)) {
            if (event->is<sf::Event::Closed>())
                window.close();


            if (const auto* mouseEvent = event->getIf<sf::Event::MouseButtonPressed>())
            {
                if (mouseEvent->button == sf::Mouse::Button::Left)
                {
                    cout << "Left Mouse Button Clicked" << std::endl;
                }
            }
        }
        
        ui_menu.clear(sf::Color::Black);
        ui_menu.display();
    }
    
    return 0;*/
}
