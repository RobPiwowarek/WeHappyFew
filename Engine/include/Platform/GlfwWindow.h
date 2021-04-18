/*  
 *  Created by michal-swiatek on 18.04.2021.
 *
 *  Github: https://github.com/michal-swiatek
 */

#ifndef WEHAPPYFEW_GLFWWINDOW_H
#define WEHAPPYFEW_GLFWWINDOW_H

#include <GLFW/glfw3.h>

#include "Core/Window.h"

namespace engine {

    class ENGINE_API GlfwWindow : public Window
    {
    public:
        explicit GlfwWindow(WindowProperties properties);
        ~GlfwWindow() override;

        void SetFullScreen(bool fullscreen) override;
        void SetVSync(bool vsync) override;

    private:
        void Init();
        void Quit();

    private:
        GLFWwindow* window = nullptr;

        static bool initialized;
    };

}

#endif //WEHAPPYFEW_GLFWWINDOW_H
