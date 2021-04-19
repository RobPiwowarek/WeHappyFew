//
// Created by swiat on 19.04.2021.
//

#include "pch.h"
#include "Platform/Platform.h"

#include "Platform/Windows/WindowsPlatform.h"

std::unique_ptr<engine::Platform> engine::DetectPlatform()
{
#if defined(WIN32) || defined(WIN64)
    return std::make_unique<WindowsPlatform>();
#else
    #error "Platform not suppoerted"
#endif
}
