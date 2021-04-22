/*
 *  Created by michal-swiatek on 19.04.2021.
 *
 *  Github: https://github.com/michal-swiatek
 */

#ifndef WEHAPPYFEW_WINDOWSPLATFORM_H
#define WEHAPPYFEW_WINDOWSPLATFORM_H

#include "Core/EngineApi.h"
#include "Platform/Platform.h"

namespace engine {

    class ENGINE_API WindowsPlatform : public Platform
    {
    public:
        std::unique_ptr<Window> CreateNewWindow(WindowProperties properties) override;
        std::unique_ptr<GraphicsContext> CreateGraphicsContext(void* windowHandle) override;
        std::unique_ptr<Renderer> CreateRenderer() override;
    };

}

#endif //WEHAPPYFEW_WINDOWSPLATFORM_H
