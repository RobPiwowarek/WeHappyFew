/*  
 *  Created by michal-swiatek on 22.04.2021.
 *
 *  Github: https://github.com/michal-swiatek
 */

#ifndef WEHAPPYFEW_GRAPHICSCONTEXT_H
#define WEHAPPYFEW_GRAPHICSCONTEXT_H

#include "Core/EngineApi.h"

namespace engine {

    class ENGINE_API GraphicsContext
    {
    public:
        virtual ~GraphicsContext() = default;

        virtual void Init() = 0;
        virtual void SwapBuffers() = 0;
    };

}

#endif //WEHAPPYFEW_GRAPHICSCONTEXT_H
