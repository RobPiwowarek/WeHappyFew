/*
 *  Created by michal-swiatek on 19.04.2021.
 *
 *  Github: https://github.com/michal-swiatek
 */

#include "Platform/Windows/WindowsPlatform.h"

#include "Platform/GlfwWindow.h"
#include "Platform/OpenGL/OpenGlContext.h"
#include "Platform/OpenGL/OpenGlRenderer.h"

namespace engine {

    std::unique_ptr<Window> WindowsPlatform::CreateNewWindow(WindowProperties properties)
    {
        return std::make_unique<GlfwWindow>(std::move(properties));
    }

    std::unique_ptr<GraphicsContext> WindowsPlatform::CreateGraphicsContext(void* windowHandle)
    {
        return std::make_unique<OpenGlContext>(static_cast<GLFWwindow*>(windowHandle));
    }

    std::unique_ptr<Renderer> WindowsPlatform::CreateRenderer()
    {
        return std::make_unique<OpenGlRenderer>();
    }

}
