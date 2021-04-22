/*  
 *  Created by michal-swiatek on 22.04.2021.
 *
 *  Github: https://github.com/michal-swiatek
 */

#include "pch.h"
#include "Platform/OpenGL/OpenGlRenderer.h"

#include <glad/glad.h>

namespace engine {

    void OpenGlRenderer::Init() {}
    void OpenGlRenderer::Quit() {}

    void OpenGlRenderer::SetClearColor(const glm::vec4 &color)
    {
        glClearColor(color.r, color.g, color.b, color.a);
    }

    void OpenGlRenderer::Clear()
    {
        glClear(GL_COLOR_BUFFER_BIT);
    }

}
