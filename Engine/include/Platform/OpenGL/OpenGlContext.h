/*  
 *  Created by michal-swiatek on 22.04.2021.
 *
 *  Github: https://github.com/michal-swiatek
 */

#ifndef WEHAPPYFEW_OPENGLCONTEXT_H
#define WEHAPPYFEW_OPENGLCONTEXT_H

#include "Core/EngineApi.h"
#include "Rendering/GraphicsContext.h"

struct GLFWwindow;

namespace engine {

    class ENGINE_API OpenGlContext : public GraphicsContext
    {
    public:
        explicit OpenGlContext(GLFWwindow* windowHandle);

        void Init() override;
        void SwapBuffers() override;

    private:
        GLFWwindow* window;
    };

}

#endif //WEHAPPYFEW_OPENGLCONTEXT_H
