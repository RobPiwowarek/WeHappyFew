cmake_minimum_required(VERSION 3.17)
project(WeHappyFew)

set(CMAKE_CXX_STANDARD 17)

# Set output directory to project directory
set(ENGINE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/Engine/bin/$<CONFIG>")
set(GAME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/Game/bin/$<CONFIG>")

# Logs slow down compilation
#add_compile_definitions(USE_LOGS)

# uncomment to time compilation time on gcc
#set(SHOW_COMPILE_TIME 1)
if (SHOW_COMPILE_TIME AND CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    add_compile_options(-ftime-report)
endif()

add_subdirectory(Engine)
add_subdirectory(Game)

add_dependencies(game engine)
