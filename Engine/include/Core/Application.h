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

namespace engine {

    class ENGINE_API Application
    {
    public:
        void Run();

    protected:
        explicit Application(std::string name = "App");
        virtual ~Application();

    private:
        std::unique_ptr<Window> window;
    };

    std::unique_ptr<Application> CreateApplication();

}

#endif //WEHAPPYFEW_APPLICATION_H
