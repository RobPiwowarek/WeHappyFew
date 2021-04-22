/*  
 *  Created by michal-swiatek on 18.04.2021.
 *
 *  Github: https://github.com/michal-swiatek
 */

#ifndef WEHAPPYFEW_PLATFORM_H
#define WEHAPPYFEW_PLATFORM_H

#include <memory>

#include "Core/Window.h"
#include "Rendering/GraphicsContext.h"

namespace engine {

    class ENGINE_API Platform
    {
    public:
        virtual std::unique_ptr<Window> CreateNewWindow(WindowProperties properties) = 0;
        virtual std::unique_ptr<GraphicsContext> CreateGraphicsContext(void* windowHandle) = 0;

        static void DetectPlatform();
        static Platform& Get();

    private:
        static std::unique_ptr<Platform> instance;
    };

}

#endif //WEHAPPYFEW_PLATFORM_H
