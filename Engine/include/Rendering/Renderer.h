/*  
 *  Created by michal-swiatek on 22.04.2021.
 *
 *  Github: https://github.com/michal-swiatek
 */

#ifndef WEHAPPYFEW_RENDERER_H
#define WEHAPPYFEW_RENDERER_H

#include <memory>
#include <glm/vec4.hpp>

#include "Core/EngineApi.h"
#include "Rendering/RendererAPI.h"

namespace engine {

    class ENGINE_API Renderer
    {
    public:
        Renderer();
        virtual ~Renderer() = default;

        virtual void Init();
        virtual void Quit();

        virtual void SetClearColor(const glm::vec4& color);
        virtual void Clear();

        void SetRendererApi(RendererAPI* api) { rendererApi.reset(api); }

        inline static Renderer& Get() { return *instance; }

    private:
        std::unique_ptr<RendererAPI> rendererApi;

        static Renderer* instance;
    };

}

#endif //WEHAPPYFEW_RENDERER_H
