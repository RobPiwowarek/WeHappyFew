/*
 *  Created by michal-swiatek on 19.04.2021.
 *
 *  Github: https://github.com/michal-swiatek
 *
 *  From Cherno game engine series: https://www.youtube.com/playlist?list=PLlrATfBNZ98dC-V-N3m0Go4deliWHPFwT
 */

#ifndef WEHAPPYFEW_EVENT_H
#define WEHAPPYFEW_EVENT_H

#include <string>

#include "Core/EngineApi.h"

namespace engine {

    enum class EventType
    {
        None = 0,
        WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
        AppTick, AppUpdate, AppRender,
        KeyPressed, KeyReleased, KeyTyped,
        MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
    };

    enum EventCategory
    {
        None = 0,
        EventCategoryApplication    = BIT(0),
        EventCategoryInput          = BIT(1),
        EventCategoryKeyboard       = BIT(2),
        EventCategoryMouse          = BIT(3),
        EventCategoryMouseButton    = BIT(4)
    };

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::type; }\
                                virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

#define EVENT_CLONE(type) virtual Event* Clone() override { return new type(*this); }

    class ENGINE_API Event
    {
    public:
        virtual ~Event() = default;

        bool handled = false;

        virtual EventType GetEventType() const = 0;
        virtual const char* GetName() const = 0;
        virtual int GetCategoryFlags() const = 0;
        virtual std::string ToString() const { return GetName(); }

        //  Prototype pattern
        virtual Event* Clone() = 0;

        inline bool IsInCategory(EventCategory category)
        {
            return GetCategoryFlags() & category;
        }
    };

    inline std::ostream& operator << (std::ostream& os, const Event& e)
    {
        return os << e.ToString();
    }

}

#endif //WEHAPPYFEW_EVENT_H
