#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

using namespace std::chrono_literals;


bool HandlingUIMenu() {
    sf::RenderWindow ui_menu(sf::VideoMode({800u, 800u}), "Chess Game");
    ui_menu.setFramerateLimit(144);

    // Adding a Title
    const sf::Font font("../../fonts/Inter_18pt-Regular.ttf");
    sf::Text title(font, "CHESS GAME");
    title.setCharacterSize(60);
    title.setPosition({204,152});
    title.setFillColor(sf::Color::Black);
    
    // Adding Button Player vs Player named btn1
    sf::RectangleShape btn1_rect;
    btn1_rect.setSize(sf::Vector2f(381,104));
    btn1_rect.setPosition({209,306});
    btn1_rect.setFillColor(sf::Color(217,217,217,255));
    sf::Text btn1_txt(font, "Player VS Player");
    btn1_txt.setCharacterSize(38);
    btn1_txt.setPosition({252,335});
    btn1_txt.setFillColor(sf::Color::Black);

    // Adding Button Player vs AI named btn2
    sf::RectangleShape btn2_rect;
    btn2_rect.setSize(sf::Vector2f(381,104));
    btn2_rect.setPosition({209,452});
    btn2_rect.setFillColor(sf::Color(217,217,217,255));
    sf::Text btn2_txt(font, "Player VS    AI");
    btn2_txt.setCharacterSize(38);
    btn2_txt.setPosition({252,481});
    btn2_txt.setFillColor(sf::Color::Black);

    // Adding Button Exit named btnE
    sf::RectangleShape btnE_rect;
    btnE_rect.setSize(sf::Vector2f(381,104));
    btnE_rect.setPosition({209,598});
    btnE_rect.setFillColor(sf::Color(217,217,217,255));
    sf::Text btnE_txt(font, "Exit");
    btnE_txt.setCharacterSize(38);
    btnE_txt.setPosition({359,627});
    btnE_txt.setFillColor(sf::Color::Black);


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
        
        ui_menu.clear(sf::Color::White);
        // Drawing Buttons and Texts
        ui_menu.draw(title);
        ui_menu.draw(btn1_rect);
        ui_menu.draw(btn1_txt);

        ui_menu.draw(btn2_rect);
        ui_menu.draw(btn2_txt);

        ui_menu.draw(btnE_rect);
        ui_menu.draw(btnE_txt);

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
