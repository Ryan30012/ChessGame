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

void updateBoard(sf::RenderWindow& window, Board& board)
{
    window.clear(sf::Color::Black);
    board.draw();
    window.display();
}

int main()
{
    sf::RenderWindow window(sf::VideoMode({800u, 800u}), "Chess Project");
    window.setFramerateLimit(144);

    //Tile tile({0.f, 0.f}, TileType::Active);
    //Piece piece((sf::Vector2f) {0.f, 0.f},Chess::PieceColor::Black, Chess::PieceType::Rook);

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
                    // Get mouse position in Grid coordinates
                    sf::Vector2i gridPosFct = getMousePositionInGrid(window, mouseEvent);
                    board.clickHandler(gridPosFct);
                }
                updateBoard(window, board);
            }
        }
        
        window.clear(sf::Color::Black);
        board.draw();
        window.display();
    }
    
    return 0;
}
