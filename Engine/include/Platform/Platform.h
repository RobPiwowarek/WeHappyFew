/*  
 *  Created by michal-swiatek on 18.04.2021.
 *
 *  Github: https://github.com/michal-swiatek
 */

#ifndef WEHAPPYFEW_PLATFORM_H
#define WEHAPPYFEW_PLATFORM_H

#include <memory>

#include "Core/Window.h"

namespace engine {

    class ENGINE_API Platform
    {
    public:
        virtual std::unique_ptr<Window> CreateWindow(WindowProperties properties) = 0;
    };

    std::unique_ptr<Platform> DetectPlatform();

}

#endif //WEHAPPYFEW_PLATFORM_H
