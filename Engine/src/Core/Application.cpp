/*  
 *  Created by michal-swiatek on 18.04.2021.
 *
 *  Github: https://github.com/michal-swiatek
 */

#include "pch.h"
#include "Core/Application.h"

namespace engine {

    using namespace std::placeholders;

    Application* Application::instance = nullptr;

    Application::Application(std::string name)
    {
        assert(!instance && "Application already exists");
        instance = this;

        platform = DetectPlatform();

        window = std::move(platform->CreateWindow(WindowProperties(name)));

        eventManager = std::make_unique<EventManager>();
//        window->SetEventCallback([this](Event& e) { eventManager->OnEvent(e); });
        window->SetEventCallback([this](Event& e){ this->OnEvent(e); });
    }

    Application::~Application() {}

    void Application::OnEvent(Event &event)
    {
        auto handler = EventHandler(event);

        handler.Handle<WindowCloseEvent>([this](auto& e){ return this->OnWindowClose(e); });
        handler.Handle<WindowResizeEvent>([this](auto& e){ return this->OnWindowResize(e); });

        eventManager->OnEvent(event);
    }

    void Application::Close()
    {
        running = false;
    }

    void Application::Run()
    {
        while (running)
        {
            window->Update();

            eventManager->DispatchEvents();
        }
    }

    bool Application::OnWindowClose(WindowCloseEvent &e)
    {
        Close();
        return true;
    }

    bool Application::OnWindowResize(WindowResizeEvent &e)
    {
        return false;
    }

}
