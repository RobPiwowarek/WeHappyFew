/*  
 *  Created by michal-swiatek on 18.04.2021.
 *
 *  Github: https://github.com/michal-swiatek
 *
 *  From Cherno game engine series: https://www.youtube.com/playlist?list=PLlrATfBNZ98dC-V-N3m0Go4deliWHPFwT
 */

#include "pch.h"
#include "Platform/GlfwWindow.h"

#include "Events/ApplicationEvents.h"
#include "Events/KeyEvents.h"
#include "Events/MouseEvents.h"

namespace engine {

    bool GlfwWindow::initialized = false;

    static void GlfwErrorCallback(int error, const char* description)
    {
        LOG_CORE_ERROR("GLFW Error ({0}): {1}", error, description);
    }

    GlfwWindow::GlfwWindow(WindowProperties properties) : Window(std::move(properties))
    {
        Init();
    }

    GlfwWindow::~GlfwWindow()
    {
        Quit();
    }

    void GlfwWindow::Init()
    {
        if (!initialized)
        {
            initialized = glfwInit();
            assert(initialized && "Unable to initialize GLFW");
            glfwSetErrorCallback(GlfwErrorCallback);
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        window = glfwCreateWindow(properties.width, properties.height, properties.title.c_str(), nullptr, nullptr);
        assert(window && "Unable to create window");

        glfwMakeContextCurrent(window);

        SetVSync(properties.vsync);
        SetFullScreen(properties.fullscreen);

//        glfwSetWindowUserPointer(window, &windowData);
        glfwSetWindowUserPointer(window, this);
        SetCallbacks();

        gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    }

    void GlfwWindow::SetCallbacks()
    {
        glfwSetWindowCloseCallback(window, [](GLFWwindow* windowPtr)
        {
            auto* win = (GlfwWindow*)glfwGetWindowUserPointer(windowPtr);

            WindowCloseEvent event;
            win->eventCallback(event);
        });

        glfwSetWindowSizeCallback(window, [](GLFWwindow* windowPtr, int width, int height)
        {
            auto* win = (GlfwWindow*)glfwGetWindowUserPointer(windowPtr);
            win->properties.width = width;
            win->properties.height = height;

            WindowResizeEvent event(width, height);
            win->eventCallback(event);
        });

        glfwSetKeyCallback(window, [](GLFWwindow* windowPtr, int key, int scancode, int action, int mods)
        {
            auto* win = (GlfwWindow*)glfwGetWindowUserPointer(windowPtr);

            switch (action)
            {
                case GLFW_PRESS:
                {
                    KeyPressedEvent event(static_cast<const KeyCode>(key), 0);
                    win->eventCallback(event);
                    break;
                }
                case GLFW_RELEASE:
                {
                    KeyReleasedEvent event(static_cast<const KeyCode>(key));
                    win->eventCallback(event);
                    break;
                }
                case GLFW_REPEAT:
                {
                    KeyPressedEvent event(static_cast<const KeyCode>(key), 1);
                    win->eventCallback(event);
                    break;
                }
                default:
                    break;
            }
        });

        glfwSetCharCallback(window, [](GLFWwindow* callbackWindow, unsigned int keycode)
        {
            auto* windowPtr = (GlfwWindow*)glfwGetWindowUserPointer(callbackWindow);

            KeyTypedEvent event(static_cast<const KeyCode>(keycode));
            windowPtr->eventCallback(event);
        });

        glfwSetMouseButtonCallback(window, [](GLFWwindow* windowPtr, int button, int action, int mods)
        {
            auto* win = (GlfwWindow*)glfwGetWindowUserPointer(windowPtr);

            switch (action)
            {
                case GLFW_PRESS:
                {
                    MouseButtonPressedEvent event(static_cast<const MouseCode>(button));
                    win->eventCallback(event);
                    break;
                }
                case GLFW_RELEASE:
                {
                    MouseButtonReleasedEvent event(static_cast<const MouseCode>(button));
                    win->eventCallback(event);
                    break;
                }
            }
        });

        glfwSetScrollCallback(window, [](GLFWwindow* windowPtr, double xOffset, double yOffset)
        {
            auto* win = (GlfwWindow*)glfwGetWindowUserPointer(windowPtr);

            MouseScrolledEvent event((float)xOffset, (float)yOffset);
            win->eventCallback(event);
        });

        glfwSetCursorPosCallback(window, [](GLFWwindow* windowPtr, double xPos, double yPos)
        {
            auto* win = (GlfwWindow*)glfwGetWindowUserPointer(windowPtr);

            MouseMovedEvent event((float)xPos, (float)yPos);
            win->eventCallback(event);
        });
    }

    void GlfwWindow::Quit()
    {
        glfwDestroyWindow(window);
        window = nullptr;

        glfwTerminate();
        initialized = false;
    }

    void GlfwWindow::Update()
    {
        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    void GlfwWindow::SetFullScreen(bool fullscreen)
    {
        if (fullscreen)
            glfwSetWindowMonitor(window, glfwGetPrimaryMonitor(), 50, 50, properties.width, properties.height, properties.refreshRate);
        else
            glfwSetWindowMonitor(window, nullptr, 50, 50, properties.width, properties.height, properties.refreshRate);

        properties.fullscreen = fullscreen;
    }

    void GlfwWindow::SetVSync(bool vsync)
    {
        if (vsync)
            glfwSwapInterval(1);
        else
            glfwSwapInterval(0);

        properties.vsync = vsync;
    }

}
