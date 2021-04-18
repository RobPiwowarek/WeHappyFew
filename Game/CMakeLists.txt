cmake_minimum_required(VERSION 3.19)
project(Game)

set(CMAKE_CXX_STANDARD 17)

# Set output directory to project directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${GAME_OUTPUT_DIRECTORY}")

#add_compile_definitions(USE_LOGS)

add_executable(game main.cpp)

target_include_directories(game PUBLIC ../Engine/include)
target_link_libraries(game engine)
