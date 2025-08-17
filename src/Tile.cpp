#include "Tile.hpp"
#include "ChessConstants.hpp"


Tile::Tile() 
    : position({0.f, 0.f}), type(Chess::TileType::None) 
{
    shape.setSize({Chess::TILESIZE, Chess::TILESIZE});
    shape.setPosition(position);
    shape.setFillColor(sf::Color::White);
}

Tile::Tile(sf::Vector2f pos, Chess::TileType tileType) 
    : position(pos), type(tileType)
{
    shape.setSize({Chess::TILESIZE, Chess::TILESIZE});
    shape.setPosition(position);
    
    switch(type) {
        case Chess::TileType::Active:
            shape.setFillColor(sf::Color(0, 0, 255, 128)); 
            break;
        case Chess::TileType::PossibleMove:
            shape.setFillColor(sf::Color::Green);
            break;
        case Chess::TileType::None:
            shape.setFillColor(sf::Color::White);
            break;
    }
}