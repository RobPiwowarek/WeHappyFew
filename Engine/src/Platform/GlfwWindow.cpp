/*  
 *  Created by michal-swiatek on 18.04.2021.
 *
 *  Github: https://github.com/michal-swiatek
 */

#include "pch.h"
#include "Platform/GlfwWindow.h"

namespace engine {

    bool GlfwWindow::initialized = false;

    GlfwWindow::GlfwWindow(WindowProperties properties) : Window(std::move(properties))
    {
        Init();
    }

    GlfwWindow::~GlfwWindow()
    {
        Quit();
    }

    void GlfwWindow::Update()
    {
        glfwPollEvents();
    }

    void GlfwWindow::SetFullScreen(bool fullscreen)
    {
        if (fullscreen)
            glfwSetWindowMonitor(window, glfwGetPrimaryMonitor(), 50, 50, properties.width, properties.height, properties.refreshRate);
        else
            glfwSetWindowMonitor(window, nullptr, 50, 50, properties.width, properties.height, properties.refreshRate);

        properties.fullscreen = fullscreen;
    }

    void GlfwWindow::SetVSync(bool vsync)
    {
        if (vsync)
            glfwSwapInterval(1);
        else
            glfwSwapInterval(0);

        properties.vsync = vsync;
    }

    void GlfwWindow::Init()
    {
        if (!initialized)
        {
            initialized = glfwInit();
            assert(initialized && "Unable to initialize GLFW");
        }

        window = glfwCreateWindow(properties.width, properties.height, properties.title.c_str(), nullptr, nullptr);
        assert(window && "Unable to create window");

        SetVSync(properties.vsync);
        SetFullScreen(properties.fullscreen);

        glfwMakeContextCurrent(window);
    }

    void GlfwWindow::Quit()
    {
        glfwDestroyWindow(window);
        window = nullptr;

        glfwTerminate();
        initialized = false;
    }

}
