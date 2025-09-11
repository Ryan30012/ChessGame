#ifndef TILE_HPP
#define TILE_HPP

#include <SFML/Graphics.hpp>
#include "ChessConstant.hpp"
#include <vector>

using namespace ChessConstant;

class Tile
{
private:
    sf::RectangleShape shape;
    sf::Vector2f pos;
    sf::Color color;
    TileType type;

public:
    Tile();
    Tile(sf::Vector2f tilePosition, TileColor tileColor, TileType tileType);
    ~Tile() = default;
    sf::RectangleShape getShape() const { return shape; }
    sf::Vector2f getPosition() const { return pos; }
    TileType getType() const { return type; }
    void setShape(sf::RectangleShape newShape);
    void setPosition(sf::Vector2f newPos);
    void setType(TileType newType);
    void setColor(TileColor newColor);
    void setTile(sf::Vector2f tilePosition, TileColor tileColor, TileType tileType);

    void draw(sf::RenderWindow& win);
};


#endif // TILE_HPP