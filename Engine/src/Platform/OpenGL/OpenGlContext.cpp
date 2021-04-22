/*  
 *  Created by michal-swiatek on 22.04.2021.
 *
 *  Github: https://github.com/michal-swiatek
 */

#include "pch.h"
#include "Platform/OpenGL/OpenGlContext.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace engine {

    OpenGlContext::OpenGlContext(GLFWwindow *windowHandle) : window(windowHandle)
    {
        assert(window && "Window handle is nullptr");
    }

    void OpenGlContext::Init()
    {
        glfwMakeContextCurrent(window);
        int result = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        assert(result && "Failed to initialize Glad");
    }

    void OpenGlContext::SwapBuffers()
    {
        glfwSwapBuffers(window);
    }

}
