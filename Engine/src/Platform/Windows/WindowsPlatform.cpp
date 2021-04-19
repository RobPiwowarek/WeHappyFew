/*
 *  Created by michal-swiatek on 19.04.2021.
 *
 *  Github: https://github.com/michal-swiatek
 */

#include "Platform/Windows/WindowsPlatform.h"

#include "Platform/GlfwWindow.h"

namespace engine {

    std::unique_ptr<Window> WindowsPlatform::CreateWindow(WindowProperties properties)
    {
            return std::make_unique<GlfwWindow>(std::move(properties));
    }

}
