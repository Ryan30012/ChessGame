#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "ChessConstant.hpp"
#include "Tile.hpp"

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
    else if  (playing_Mode == 1){ // if mode is Player VS Player
        sf::RenderWindow window(sf::VideoMode({800u, 800u}), "Chess Game");
        window.setFramerateLimit(144);

        Tile tiles[8][8];
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                tiles[i][j].setTile(sf::Vector2f(j * 100, i * 100), ((i+j) % 2 == 0 ? TileColor::LIGHT : TileColor::DARK), TileType::DEFAULT);
            }
            
        }
        

        while (window.isOpen())
        {
            while(const std::optional event = window.waitEvent(500ms)) {
                if (event->is<sf::Event::Closed>())
                    window.close();


                if (const auto* mouseEvent = event->getIf<sf::Event::MouseButtonPressed>())
                {
                    if (mouseEvent->button == sf::Mouse::Button::Left)
                    {
                        std::cout << "Left Mouse Button Clicked" << std::endl;
                    }
                }
            }
            
            window.clear(sf::Color::Black);
            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    tiles[i][j].draw(window);
                }
                
            }
            window.display();
        }
    }

    /*
    
    */
    return 0;
}
