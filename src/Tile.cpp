#include "Tile.hpp"
#include "ChessConstant.hpp"
#include <SFML/Graphics.hpp>


Tile::Tile() {
    this->pos = {0,0};
    this->type = TileType::DEFAULT;
    this->color = sf::Color::White;

    sf::RectangleShape newShape;
    newShape.setSize({ChessConstant::TILE_SIZE,ChessConstant::TILE_SIZE});
    newShape.setPosition(this->pos);
    newShape.setFillColor(this->color);
    this->shape = newShape;
};

Tile::Tile(sf::Vector2f tilePosition, ChessConstant::TileColor tileColor, TileType tileType)
    : pos(tilePosition), type(tileType) {
    
    switch (tileColor)
    {
    case ChessConstant::TileColor::LIGHT:
        this->color = sf::Color(221, 207, 130, 255);
        break;
    case ChessConstant::TileColor::DARK:
        this->color = sf::Color(185, 144, 68, 255);
        break;
    case ChessConstant::TileColor::BLUE:
        this->color = sf::Color(0, 81, 255, 85);
        break;
    case ChessConstant::TileColor::GREEN:
        this->color = sf::Color(0, 255, 30, 135);
        break;
    case ChessConstant::TileColor::RED:
        this->color = sf::Color(255, 0, 0, 115);
        break;
    }
    
    sf::RectangleShape newShape;
    newShape.setSize({1.f,1.f});
    newShape.setPosition(tilePosition);
    newShape.setFillColor(this->color);
    this->shape = newShape;
};

void Tile::setShape(sf::RectangleShape newShape){
    this->shape = newShape;
};
void Tile::setPosition(sf::Vector2f newPos){
    this->pos = newPos;
};
void Tile::setType(TileType newType){
    this->type = newType;
};
void Tile::setColor(ChessConstant::TileColor newColor){
    switch (newColor)
    {
    case ChessConstant::TileColor::LIGHT:
        this->color = sf::Color(221, 207, 130, 255);
        break;
    case ChessConstant::TileColor::DARK:
        this->color = sf::Color(185, 144, 68, 255);
        break;
    case ChessConstant::TileColor::BLUE:
        this->color = sf::Color(0, 81, 255, 85);
        break;
    case ChessConstant::TileColor::GREEN:
        this->color = sf::Color(0, 255, 30, 135);
        break;
    case ChessConstant::TileColor::RED:
        this->color = sf::Color(255, 0, 0, 115);
        break;
    }
};

void Tile::setTile(sf::Vector2f tilePosition, ChessConstant::TileColor tileColor, TileType tileType) {
    setPosition(tilePosition);
    setColor(tileColor);
    setType(tileType);

    sf::RectangleShape newShape;
    newShape.setSize({ChessConstant::TILE_SIZE,ChessConstant::TILE_SIZE});
    newShape.setPosition(tilePosition);
    newShape.setFillColor(this->color);
    setShape(newShape);
}

void Tile::draw(sf::RenderWindow& win) {
    win.draw(getShape());
};