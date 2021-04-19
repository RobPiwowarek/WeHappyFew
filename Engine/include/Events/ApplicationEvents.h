/*
 *  Created by michal-swiatek on 19.04.2021.
 *
 *  Github: https://github.com/michal-swiatek
 *
 *  From Cherno game engine series: https://www.youtube.com/playlist?list=PLlrATfBNZ98dC-V-N3m0Go4deliWHPFwT
 */

#ifndef WEHAPPYFEW_APPLICATIONEVENTS_H
#define WEHAPPYFEW_APPLICATIONEVENTS_H

#include <sstream>

#include "Events/Event.h"

namespace engine {

    class ENGINE_API WindowResizeEvent : public Event
    {
    public:
        WindowResizeEvent(uint32_t width, uint32_t height) : width(width), height(height) {}

        unsigned int GetWidth() const { return width; }
        unsigned int GetHeight() const { return height; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "WindowResizeEvent: " << width << ", " << height;
            return ss.str();
        }

        EVENT_CLONE(WindowResizeEvent)
        EVENT_CLASS_TYPE(WindowResize)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)

    private:
        unsigned int width, height;
    };

    class ENGINE_API WindowCloseEvent : public Event
    {
    public:
        WindowCloseEvent() = default;

        EVENT_CLONE(WindowCloseEvent)
        EVENT_CLASS_TYPE(WindowClose)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class ENGINE_API AppTickEvent : public Event
    {
    public:
        AppTickEvent() = default;

        EVENT_CLONE(AppTickEvent)
        EVENT_CLASS_TYPE(AppTick)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class ENGINE_API AppUpdateEvent : public Event
    {
    public:
        AppUpdateEvent() = default;

        EVENT_CLONE(AppUpdateEvent)
        EVENT_CLASS_TYPE(AppUpdate)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class ENGINE_API AppRenderEvent : public Event
    {
    public:
        AppRenderEvent() = default;

        EVENT_CLONE(AppRenderEvent)
        EVENT_CLASS_TYPE(AppRender)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

}

#endif //WEHAPPYFEW_APPLICATIONEVENTS_H
