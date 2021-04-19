/*  
 *  Created by michal-swiatek on 18.04.2021.
 *
 *  Github: https://github.com/michal-swiatek
 */

#include "pch.h"
#include "Core/Application.h"

namespace engine {

    Application* Application::instance = nullptr;

    Application::Application(std::string name)
    {
        assert(!instance && "Application already exists");
        instance = this;

        platform = DetectPlatform();

        window = platform->CreateWindow(WindowProperties(std::move(name)));
    }

    Application::~Application() {}

    void Application::Close()
    {
        running = false;
    }

    void Application::Run()
    {
        while (running)
        {
            window->Update();
        }
    }

}
