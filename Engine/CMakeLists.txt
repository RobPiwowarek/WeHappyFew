cmake_minimum_required(VERSION 3.19)
project(Engine)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${ENGINE_OUTPUT_DIRECTORY}")

include_directories(include)
add_compile_definitions(ENGINE_BUILD_DLL)

add_library(engine SHARED src/Core/Application.cpp src/Core/Log.cpp)

target_include_directories(engine PUBLIC 3rd-party/spdlog/include)
add_custom_command(TARGET engine POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy
                   ${ENGINE_OUTPUT_DIRECTORY}/libengine.dll
                   ${GAME_OUTPUT_DIRECTORY})
