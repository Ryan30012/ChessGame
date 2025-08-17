#ifndef TILE_HPP
#define TILE_HPP

#include <SFML/Graphics.hpp>
#include "ChessConstants.hpp"


class Tile
{
private:
    sf::RectangleShape shape; // Shape of the tile
    sf::Vector2f position; // Position of the tile on the board
    Chess::TileType type; // Type of the tile (None, Active, PossibleMove)
public:
    Tile();
    Tile(sf::Vector2f pos, Chess::TileType tileType);
    ~Tile() = default;
    const sf::RectangleShape& getShape() const { return shape; }
    void setType(Chess::TileType newType) { type = newType; }
    sf::Vector2f getPosition() const { return position; }
};


#endif // TILE_HPP