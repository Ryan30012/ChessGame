#include "Board.hpp"
#include "ChessConstants.hpp"
#include <memory>
#include <iostream>

Board::Board(sf::RenderWindow& win) : window(win)
{

    // Initialize Board Tiles
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            tiles[i][j] = Tile(sf::Vector2f(i * 100.f, j * 100.f), Chess::TileType::None);
        }
        
    }
    
}

void Board::draw() const
{
    // Draw the chessboard background
    Chess::CreateBackGround(window);

    if (selectedTile) {
        window.draw(selectedTile->getShape());
    }

    if (!possibleMoves.empty())
    {
        for (const auto& move : possibleMoves) {
            if (move) {
                window.draw(move->getShape());
            }
        }
    }
}

void Board::clickHandler(sf::Vector2i gridPos)
{
    std::cout << "Clicked on grid position: (" << gridPos.x << ", " << gridPos.y << ")\n";
    if (gridPos.x < 0 || gridPos.x >= 8 || gridPos.y < 0 || gridPos.y >= 8) {
        return; // Out of bounds
    }

    if (selectedTile) 
    {
        std::cout << "Check 1\n";
        for (int i = 0; i < possibleMoves.size(); i++)
        {
            if (i=0)
                std::cout << "Check 2\n";

            if (gridPos.x == possibleMoves[i]->getPosition().x && gridPos.y == possibleMoves[i]->getPosition().x)
            {
                // Move piece to position

                return;
            }
        }
        std::cout << "Check 3\n";
        // Deselect the tile if no valid move is found
        selectedTile = nullptr;

        if (!selectedTile)
            std::cout << "Check 4\n";
    }
    else 
    {
        selectedTile = &tiles[gridPos.x][gridPos.y];
        selectedTile->setType(Chess::TileType::Active);

        // Show possible moves by ading the position in the possibleMoves vector
    }
}