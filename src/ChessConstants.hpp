#ifndef CHESSCONSTANTS_HPP
#define CHESSCONSTANTS_HPP


#include <SFML/Graphics.hpp>

namespace Chess {

    const sf::Color lightTileColor = sf::Color(255, 206, 158);
    const sf::Color darkTileColor = sf::Color(209, 139, 71);

    const float TILESIZE = 100.f;

    enum PieceType {
        Pawn,
        Knight,
        Bishop,
        Rook,
        Queen,
        King
    };

    enum PieceColor {
        White,
        Black
    };

    enum TileType {
        None,
        Active,
        PossibleMove
    };
    


    static void CreateBackGround(sf::RenderWindow& window) {
        for (float i = 0; i < 8; i++)
        {
            for (float j = 0; j < 8; j++)
            {
                // Create a Tile
                sf::RectangleShape tile(sf::Vector2f(TILESIZE, TILESIZE));
                sf::Vector2f pos(i * TILESIZE, j * TILESIZE);
                tile.setPosition(pos);
                tile.setOrigin({0.f, 0.f});
                tile.setFillColor(((int)(i + j)) % 2 == 0 ? lightTileColor : darkTileColor);

                window.draw(tile);
            }
            
        }
        
    }
}

#endif // CHESSCONSTANTS_HPP