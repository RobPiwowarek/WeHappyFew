/*  
 *  Created by michal-swiatek on 20.04.2021.
 *
 *  Github: https://github.com/michal-swiatek
 */

#include "pch.h"
#include "Input/Input.h"

#include <GLFW/glfw3.h>

#include "Core/Application.h"

namespace engine {

    bool Input::IsKeyPressed(KeyCode key) {
        auto* window = static_cast<GLFWwindow*>(Application::GetInstance().GetWindow().GetNativeWindow());
        auto state = glfwGetKey(window, static_cast<int32_t>(key));
        return state == GLFW_PRESS || state == GLFW_REPEAT;
    }

    bool Input::IsButtonPressed(const MouseCode button)
    {
        auto* window = static_cast<GLFWwindow*>(Application::GetInstance().GetWindow().GetNativeWindow());
        auto state = glfwGetMouseButton(window, static_cast<int32_t>(button));
        return state == GLFW_PRESS;
    }

    float Input::GetMouseX()
    {
        auto* window = static_cast<GLFWwindow*>(Application::GetInstance().GetWindow().GetNativeWindow());
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);

        return (float)xpos;
    }

    float Input::GetMouseY()
    {
        auto* window = static_cast<GLFWwindow*>(Application::GetInstance().GetWindow().GetNativeWindow());
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);
        
        return (float)ypos;
    }

}
