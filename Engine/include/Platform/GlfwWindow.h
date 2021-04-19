/*  
 *  Created by michal-swiatek on 18.04.2021.
 *
 *  Github: https://github.com/michal-swiatek
 *
 *  From Cherno game engine series: https://www.youtube.com/playlist?list=PLlrATfBNZ98dC-V-N3m0Go4deliWHPFwT
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

        void Update() override;

        void SetFullScreen(bool fullscreen) override;
        void SetVSync(bool vsync) override;

        inline void SetEventCallback(const EventCallback &callback) override { windowData.eventCallback = callback; }

    private:
        void Init();
        void Quit();

        void SetCallbacks();

    private:
        GLFWwindow* window = nullptr;

        static bool initialized;

        struct WindowData
        {
            EventCallback eventCallback;
            WindowProperties& properties;

            explicit WindowData(WindowProperties& properties) : properties(properties) {}
        };

        WindowData windowData;
    };

}

#endif //WEHAPPYFEW_GLFWWINDOW_H
