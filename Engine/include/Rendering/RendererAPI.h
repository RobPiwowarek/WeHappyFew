/*  
 *  Created by michal-swiatek on 22.04.2021.
 *
 *  Github: https://github.com/michal-swiatek
 */

#ifndef WEHAPPYFEW_RENDERERAPI_H
#define WEHAPPYFEW_RENDERERAPI_H

#include "Core/EngineApi.h"

namespace engine {

    class ENGINE_API RendererAPI
    {
    public:
        virtual ~RendererAPI() = default;

        virtual void Init() = 0;
        virtual void Quit() = 0;

        virtual void SetClearColor(const glm::vec4& color) = 0;
        virtual void Clear() = 0;
    };

}

#endif //WEHAPPYFEW_RENDERERAPI_H
