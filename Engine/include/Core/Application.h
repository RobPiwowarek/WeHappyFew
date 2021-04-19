/*  
 *  Created by michal-swiatek on 18.04.2021.
 *
 *  Github: https://github.com/michal-swiatek
 */

#ifndef WEHAPPYFEW_APPLICATION_H
#define WEHAPPYFEW_APPLICATION_H

#include <memory>

#include "EngineApi.h"
#include "Window.h"
#include "Platform/Platform.h"

int main(int argc, char** argv);

namespace engine {

    class ENGINE_API Application
    {
    public:
        virtual ~Application();

        void Close();

    protected:
        explicit Application(std::string name = "App");

    private:
        void Run();

        bool running = true;

        std::unique_ptr<Platform> platform;
        std::unique_ptr<Window> window;

        static Application* instance;

        //  Allows EntryPoint to call Run()
        friend int ::main(int argc, char** argv);
    };

    std::unique_ptr<Application> CreateApplication();

}

#endif //WEHAPPYFEW_APPLICATION_H
