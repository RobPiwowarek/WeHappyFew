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

        window = platform->CreateNewWindow(WindowProperties(std::move(name)));
        window->SetEventCallback([this](Event& e){ this->OnEvent(e); });

        eventManager = std::make_unique<EventManager>();
    }

    Application::~Application() {}

    void Application::OnEvent(Event &event)
    {
        if (!event.IsInCategory(EventCategoryMouse))
            LOG_CORE_TRACE("{0}", event.ToString());

        auto handler = EventHandler(event);

        handler.Handle<WindowCloseEvent>([this](auto& e){ return this->OnWindowClose(e); });
        handler.Handle<WindowResizeEvent>([this](auto& e){ return this->OnWindowResize(e); });

        if (!event.handled)
            eventManager->BufferEvent(event);
    }

    void Application::Run()
    {
        while (running)
        {
            window->Update();

            eventManager->DispatchEvents(layerStack);
        }
    }

    void Application::PushLayer(Layer *layer)
    {
        layerStack.PushLayer(layer);
    }

    void Application::PushOverlay(Layer *overlay)
    {
        layerStack.PopOverlay(overlay);
    }

    void Application::Close()
    {
        running = false;
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
