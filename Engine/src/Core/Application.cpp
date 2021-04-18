/*  
 *  Created by michal-swiatek on 18.04.2021.
 *
 *  Github: https://github.com/michal-swiatek
 */

#include "pch.h"
#include "Core/Application.h"

#include "Platform/Platform.h"

using namespace engine;

Application::Application(std::string name)
{
    auto platform = DetectPlatform();

    window = platform->CreateWindow(WindowProperties(std::move(name)));
}

Application::~Application() {}

void Application::Run()
{

}
