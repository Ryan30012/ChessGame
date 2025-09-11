#ifndef CHESSCONSTANT_HPP
#define CHESSCONSTANT_HPP

#include <SFML/Window.hpp>
#include <vector>

namespace ChessConstant {


    enum TileColor {
        LIGHT,
        DARK,
        BLUE,
        GREEN,
        RED
    };

    enum TileType {
        DEFAULT,
        ACTIVE,
        MOVE,
        CHECK
    };

    const float WINDOW_SIZE = 800;

    const float TILE_SIZE = 100; // 1 / 8 of window size

    enum PieceType {
        PAWN,
        ROOK,
        KNIGHT,
        BISHOP,
        QUEEN,
        KING
    };    

};



#endif