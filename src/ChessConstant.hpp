#ifndef CHESSCONSTANT_HPP
#define CHESSCONSTANT_HPP

#include <SFML/Window.hpp>

namespace ChessConst {

    sf::Color lightTile = sf::Color(221, 207, 130, 255);
    sf::Color darkTile = sf::Color(185, 144, 68, 255);
    sf::Color activeTile = sf::Color(0, 81, 255, 85);
    sf::Color moveTile = sf::Color(0, 255, 30, 135);
    sf::Color checkTile = sf::Color(255, 0, 0, 115);

    enum TileType {
        DEFAULT,
        ACTIVE,
        MOVE,
        CHECK
    };

    const float WINDOW_SIZE = 800f;

    const float TILE_SIZE = 100f; // 1 / 8 of window size

    enum PieceType {
        PAWN,
        ROOK,
        KNIGHT,
        BISHOP,
        QUEEN,
        KING
    };

}



#endif