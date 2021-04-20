cmake_minimum_required(VERSION 3.17)
project(Engine)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${ENGINE_OUTPUT_DIRECTORY}")

include_directories(include)
add_compile_definitions(ENGINE_BUILD_DLL)

# Build only GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(3rd-party/spdlog)
add_subdirectory(3rd-party/GLFW)
add_subdirectory(3rd-party/glad)

add_library(engine SHARED src/Core/Application.cpp src/Core/Log.cpp src/Core/Window.cpp src/Platform/GlfwWindow.cpp src/Platform/Windows/WindowsPlatform.cpp src/Platform/Platform.cpp src/Events/EventManager.cpp src/Core/Layer.cpp src/Core/LayerStack.cpp)

target_link_libraries(engine glfw spdlog glad)

target_include_directories(engine PUBLIC 3rd-party/spdlog/include 3rd-party/GLFW/include 3rd-party/glad/include)
target_precompile_headers(engine PRIVATE include/pch.h)

# Copy .dll file after build
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    add_custom_command(TARGET engine POST_BUILD
                       COMMAND ${CMAKE_COMMAND} -E copy
                       ${ENGINE_OUTPUT_DIRECTORY}libengine.dll
                       ${GAME_OUTPUT_DIRECTORY})
elseif(MSVC)
    add_custom_command(TARGET engine POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy
            ${ENGINE_OUTPUT_DIRECTORY}engine.dll
            ${GAME_OUTPUT_DIRECTORY})
endif()

add_dependencies(engine spdlog)
add_dependencies(engine glfw)
add_dependencies(engine glad)
