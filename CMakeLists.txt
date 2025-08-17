cmake_minimum_required(VERSION 3.28)
project(ChessGame)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# SFML Configuration
include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.1
    GIT_SHALLOW ON)
FetchContent_MakeAvailable(SFML)

# Main executable
add_executable(ChessGame 
    src/main.cpp
    src/Tile.cpp
    src/Piece.cpp
    src/Board.cpp
)
target_compile_features(ChessGame PRIVATE cxx_std_17)
target_link_libraries(ChessGame PRIVATE sfml-graphics sfml-window)

# Ensure DLLs are copied to output directory (only for MSVC)
if(WIN32 AND MSVC)
    add_custom_command(TARGET ChessGame POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/assets
        ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/assets
    )
endif()