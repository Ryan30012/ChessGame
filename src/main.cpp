#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "ChessConstants.hpp"

using namespace Chess;
using namespace std::chrono_literals;

#include "Board.hpp"
#include "Tile.hpp"
#include "Piece.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode({800u, 800u}), "Chess Project");
    window.setFramerateLimit(144);

    Board board(window);


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
        
        window.clear(sf::Color::Black);
        window.display();
    }
    
    return 0;
}
