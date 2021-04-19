/*  
 *  Created by michal-swiatek on 18.04.2021.
 *
 *  Github: https://github.com/michal-swiatek
 */

#ifndef WEHAPPYFEW_ENGINE_INCLUDE_CORE_WINDOW_H_
#define WEHAPPYFEW_ENGINE_INCLUDE_CORE_WINDOW_H_

#include <string>
#include <memory>
#include <functional>

#include "EngineApi.h"
#include "Events/Event.h"

namespace engine {

    struct ENGINE_API WindowProperties
    {
        std::string title;
        uint32_t width;
        uint32_t height;
        uint32_t refreshRate;
        bool fullscreen;
        bool vsync;

        explicit WindowProperties(std::string title,
                            uint32_t width = 720,
                            uint32_t height = 480,
                            uint32_t refreshRate = 60,
                            bool fullscreen = false,
                            bool vsync = false);
    };

    class ENGINE_API Window
    {
    protected:
        using EventCallback = std::function<void(Event&)>;

    public:
        virtual ~Window() = default;

        virtual void Update() = 0;

        //  Set properties
        virtual void SetFullScreen(bool fullscreen) = 0;
        virtual void SetVSync(bool vsync) = 0;

        virtual void SetEventCallback(const EventCallback& callback) = 0;

        //  Get window properties
        [[nodiscard]] inline const WindowProperties& GetProperties() const { return properties; }

    protected:
        explicit Window(WindowProperties properties);

        WindowProperties properties;
    };

}

#endif //WEHAPPYFEW_ENGINE_INCLUDE_CORE_WINDOW_H_
