#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

using namespace std::chrono_literals;


bool HandlingUIMenu() {
    sf::RenderWindow ui_menu(sf::VideoMode({800u, 800u}), "Chess Game");
    ui_menu.setFramerateLimit(144);


    while (ui_menu.isOpen())
    {
        while(const std::optional event = ui_menu.waitEvent(500ms)) {
            if (event->is<sf::Event::Closed>()) {
                ui_menu.close();
                return true;
            }

            if (const auto* mouseEvent = event->getIf<sf::Event::MouseButtonPressed>())
            {
                if (mouseEvent->button == sf::Mouse::Button::Left)
                {
                    std::cout << "Left Mouse Button Clicked" << std::endl;
                }
            }
        }
        
        ui_menu.clear(sf::Color::Black);
        ui_menu.display();
    }

    return true;
} 

int main()
{

    // Opening the UI menu window
    if (!HandlingUIMenu()) {
        return 1;
    }

    std::cout << "UI Menu closed" << std::endl;

    int val;

    std::cin >>  val;

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
