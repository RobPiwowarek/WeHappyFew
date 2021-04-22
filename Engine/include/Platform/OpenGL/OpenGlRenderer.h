/*  
 *  Created by michal-swiatek on 22.04.2021.
 *
 *  Github: https://github.com/michal-swiatek
 */

#ifndef WEHAPPYFEW_OPENGLRENDERER_H
#define WEHAPPYFEW_OPENGLRENDERER_H

#include "Core/EngineApi.h"
#include "Rendering/Renderer.h"

namespace engine {

    class ENGINE_API OpenGlRenderer : public Renderer
    {
    public:
        void Init() override;
        void Quit() override;

        void SetClearColor(const glm::vec4 &color) override;
        void Clear() override;
    };

}

#endif //WEHAPPYFEW_OPENGLRENDERER_H
