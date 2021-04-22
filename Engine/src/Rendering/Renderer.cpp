/*  
 *  Created by michal-swiatek on 22.04.2021.
 *
 *  Github: https://github.com/michal-swiatek
 */

#include "pch.h"
#include "Rendering/Renderer.h"

namespace engine {

    Renderer* Renderer::instance = nullptr;

    Renderer::Renderer()
    {
        assert(!instance && "Only one Renderer can be created for Application");
        instance = this;
    }

    void Renderer::Init()
    {
        rendererApi->Init();
    }

    void Renderer::Quit()
    {
        rendererApi->Quit();
    }

    void Renderer::SetClearColor(const glm::vec4 &color)
    {
        rendererApi->SetClearColor(color);
    }

    void Renderer::Clear()
    {
        rendererApi->Clear();
    }

}
