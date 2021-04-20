/*  
 *  Created by michal-swiatek on 18.04.2021.
 *
 *  Github: https://github.com/michal-swiatek
 */

#ifndef WEHAPPYFEW_APPLICATION_H
#define WEHAPPYFEW_APPLICATION_H

#include <memory>

#include "Core/LayerStack.h"
#include "Events/EventManager.h"
#include "Events/ApplicationEvents.h"

#include "Core/Window.h"
#include "Platform/Platform.h"
#include "Core/EngineApi.h"


int main(int argc, char** argv);

namespace engine {

    class ENGINE_API Application
    {
    public:
        virtual ~Application();

        void OnEvent(Event& event);

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* overlay);

        void Close();

    protected:
        explicit Application(std::string name = "App");

    private:
        void Run();

        bool OnWindowClose(WindowCloseEvent& e);
        bool OnWindowResize(WindowResizeEvent& e);

        bool running = true;

        std::unique_ptr<Platform> platform;
        std::unique_ptr<Window> window;

        LayerStack layerStack;
        std::unique_ptr<EventManager> eventManager;

        static Application* instance;

        //  Allows EntryPoint to call Run()
        friend int ::main(int argc, char** argv);
    };

    std::unique_ptr<Application> CreateApplication();

}

#endif //WEHAPPYFEW_APPLICATION_H
