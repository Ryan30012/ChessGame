#ifndef BOARD_HPP
#define BOARD_HPP

#include "ChessConstants.hpp"
#include <SFML/Graphics.hpp>
#include "Piece.hpp"
#include "Tile.hpp"
#include <vector>

class Board
{
private:
    sf::RenderWindow& window;
    Tile tiles[8][8];
    Tile* selectedTile = nullptr;
    std::vector<Tile*> possibleMoves;
public:
    Board(sf::RenderWindow& win);
    void clickHandler(sf::Vector2i gridPos);
    ~Board() = default;
    void draw() const;
};






#endif // BOARD_HPP