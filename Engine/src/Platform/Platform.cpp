/*
 *  Created by michal-swiatek on 19.04.2021.
 *
 *  Github: https://github.com/michal-swiatek
 */

#include "pch.h"
#include "Platform/Platform.h"

#include "Platform/Windows/WindowsPlatform.h"

namespace engine {

    std::unique_ptr<Platform> Platform::instance = nullptr;

    void Platform::DetectPlatform()
    {
#if defined(WIN32) || defined(WIN64)
        instance = std::make_unique<WindowsPlatform>();
#else
#error "Platform not suppoerted"
#endif
    }

    Platform & Platform::Get()
    {
        return *instance;
    }

}
