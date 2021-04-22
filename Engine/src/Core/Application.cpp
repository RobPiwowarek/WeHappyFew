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

        Platform::DetectPlatform();
        auto& platform = Platform::Get();

        window = platform.CreateNewWindow(WindowProperties(std::move(name)));
        window->SetEventCallback([this](Event& e){ this->OnEvent(e); });

        renderer = platform.CreateRenderer();

        eventManager = std::make_unique<EventManager>();

        imGuiLayer = new ImGuiLayer();
        PushOverlay(imGuiLayer);
    }

    Application::~Application() {}

    void Application::OnEvent(Event &event)
    {
        auto handler = EventHandler(event);

        handler.Handle<WindowCloseEvent>(BIND_EVENT_CALLBACK(Application::OnWindowClose));
        handler.Handle<WindowResizeEvent>(BIND_EVENT_CALLBACK(Application::OnWindowResize));

        if (!event.handled)
            eventManager->BufferEvent(event);
    }

    void Application::Run()
    {
        while (running)
        {
            renderer->SetClearColor({0, 0, 0.4, 0});
            renderer->Clear();

            for (auto* layer : layerStack)
                layer->OnUpdate();

            imGuiLayer->Begin();
            for (auto* layer : layerStack)
                layer->OnImGuiRender();
            imGuiLayer->End();

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
        layerStack.PushOverlay(overlay);
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
