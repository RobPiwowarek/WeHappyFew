cmake_minimum_required(VERSION 3.19)
project(WeHappyFew)

set(CMAKE_CXX_STANDARD 17)

# Set output directory to project directory
set(ENGINE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/Engine/bin/$<CONFIG>")
set(GAME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/Game/bin/$<CONFIG>")

add_subdirectory(Engine)
add_subdirectory(Game)

add_dependencies(game engine)
