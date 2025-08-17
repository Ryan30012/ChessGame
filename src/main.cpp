#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "ChessConstants.hpp"

using namespace Chess;
using namespace std::chrono_literals;

#include "Board.hpp"
#include "Tile.hpp"
#include "Piece.hpp"

sf::Vector2i getMousePositionInGrid(const sf::RenderWindow& window, const sf::Event::MouseButtonPressed* mouseEvent)
{
    sf::Vector2i mousePos(window.mapPixelToCoords(sf::Vector2i(mouseEvent->position)));
    return sf::Vector2i((mousePos.x / 100), (mousePos.y / 100));
}

int main()
{
    sf::RenderWindow window(sf::VideoMode({800u, 800u}), "Chess Project");
    window.setFramerateLimit(144);

    Tile tile({0.f, 0.f}, TileType::Active);
    Piece piece((sf::Vector2f) {0.f, 0.f},Chess::PieceColor::Black, Chess::PieceType::Rook);

    while (window.isOpen())
    {
        while(const std::optional event = window.waitEvent(500ms)) {
            if (event->is<sf::Event::Closed>())
                window.close();


            if (const auto* mouseEvent = event->getIf<sf::Event::MouseButtonPressed>())
            {
                if (mouseEvent->button == sf::Mouse::Button::Left)
                {
                    sf::Vector2i gridPosFct = getMousePositionInGrid(window, mouseEvent);
                    // Get mouse position in window coordinates
                    sf::Vector2i mousePos(window.mapPixelToCoords(sf::Vector2i(mouseEvent->position)));
                    sf::Vector2i gridPos((mousePos.x / 100), (mousePos.y / 100));
                    std::cout << "Mouse clicked at: " << mousePos.x << ", " << mousePos.y << std::endl;
                    std::cout << "Mouse clicked at: " << gridPos.x << ", " << gridPos.y << std::endl;
                    std::cout << "Mouse clicked at: " << gridPosFct.x << ", " << gridPosFct.y << std::endl;
                }

            }
        }
        
        window.clear(sf::Color::Black);
        Chess::CreateBackGround(window);
        window.draw(tile.getShape());
        piece.draw(window);
        window.display();
    }
    
    return 0;
}
