#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "ChessConstant.hpp"

using namespace std::chrono_literals;
using namespace ChessConstant;

bool isMouseonBtn(sf::RenderWindow& win, sf::RectangleShape btn) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(win);

    sf::Vector2i btn_size = sf::Vector2i(btn.getSize());
    sf::Vector2i btn_Xbounds = sf::Vector2i({(int) btn.getPosition().x, (int) btn.getPosition().x + btn_size.x});
    sf::Vector2i btn_Ybounds = sf::Vector2i({(int) btn.getPosition().y, (int) btn.getPosition().y + btn_size.y});

    if (mousePos.x > btn_Xbounds.x && mousePos.x < btn_Xbounds.y
        && mousePos.y > btn_Ybounds.x && mousePos.y < btn_Ybounds.y)
        return true;
    else
        return false;
}

/*
Function to open UI window and displaying the Main UI menu
Main UI menu contains 3 buttons: "Player vs Player", "Player vs AI", "Exit"
The function returns an INT {-1,1,2,3} depending on the different options selected
Link Options to return Value:
-Player vs Player ---> 1
-Player vs AI ---> 2
-Exit ---> 3
-Error if the window closes without the user selecting ----> -1
*/
int HandlingUIMenu() {
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
                    if (isMouseonBtn(ui_menu, btn1_rect))
                    {
                        std::cout << "Clicked on btn1" << std::endl;
                        ui_menu.close();
                        return 1;
                    }

                    if (isMouseonBtn(ui_menu, btn2_rect))
                    {
                        std::cout << "Clicked on btn2" << std::endl;
                        ui_menu.close();
                        return 2;
                    }

                    if (isMouseonBtn(ui_menu, btnE_rect))
                    {
                        std::cout << "Clicked on btn3" << std::endl;
                        ui_menu.close();
                        return 3;
                    }
                    
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

    return -1;
} 



int main()
{

    // Opening the UI menu window
    int playing_Mode = HandlingUIMenu();
    if (playing_Mode == -1) {
        return -1;
    }
    else if  (playing_Mode == 1){
        std::cout << "Mode Chosen: Player vs Player" << std::endl;
    }
    else if  (playing_Mode == 2){
        std::cout << "Mode Chosen: Player vs AI" << std::endl;
    }
    else if  (playing_Mode == 3){
        std::cout << "Exit Game!" << std::endl;
        return 0;
    }

    std::cin >> playing_Mode;

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
