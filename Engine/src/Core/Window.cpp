/*  
 *  Created by michal-swiatek on 18.04.2021.
 *
 *  Github: https://github.com/michal-swiatek
 */

#include "Core/Window.h"

engine::WindowProperties::WindowProperties(std::string title,
                                           uint32_t width,
                                           uint32_t height,
                                           uint32_t refreshRate,
                                           bool fullscreen,
                                           bool vsync) :
                                           title(std::move(title)), width(width), height(height),
                                           refreshRate(refreshRate), fullscreen(fullscreen), vsync(vsync) {}

engine::Window::Window(WindowProperties properties) : properties(std::move(properties)) {}
