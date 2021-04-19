/*
 *  Created by michal-swiatek on 19.04.2021.
 *
 *  Github: https://github.com/michal-swiatek
 *
 *  From Cherno game engine series: https://www.youtube.com/playlist?list=PLlrATfBNZ98dC-V-N3m0Go4deliWHPFwT
 */

#ifndef WEHAPPYFEW_MOUSEEVENTS_H
#define WEHAPPYFEW_MOUSEEVENTS_H

#include <sstream>

#include "Events/Event.h"
#include "Input/MouseCodes.h"

namespace engine {

    class ENGINE_API MouseMovedEvent : public Event
    {
    public:
        MouseMovedEvent(const float x, const float y) : mouseX(x), mouseY(y) {}

        float GetX() const { return mouseX; }
        float GetY() const { return mouseY; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseMovedEvent: " << mouseX << ", " << mouseY;
            return ss.str();
        }

        EVENT_CLONE(MouseMovedEvent)
        EVENT_CLASS_TYPE(MouseMoved)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

    private:
        float mouseX, mouseY;
    };

    class ENGINE_API MouseScrolledEvent : public Event
    {
    public:
        MouseScrolledEvent(const float xOffset, const float yOffset)
                : xOffset(xOffset), yOffset(yOffset) {}

        float GetXOffset() const { return xOffset; }
        float GetYOffset() const { return yOffset; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseScrolledEvent: " << GetXOffset() << ", " << GetYOffset();
            return ss.str();
        }

        EVENT_CLONE(MouseScrolledEvent)
        EVENT_CLASS_TYPE(MouseScrolled)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

    private:
        float xOffset, yOffset;
    };

    class ENGINE_API MouseButtonEvent : public Event
    {
    public:
        MouseCode GetMouseButton() const { return button; }

        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput | EventCategoryMouseButton)

    protected:
        MouseButtonEvent(const MouseCode button) : button(button) {}

        MouseCode button;
    };

    class ENGINE_API MouseButtonPressedEvent : public MouseButtonEvent
    {
    public:
        MouseButtonPressedEvent(const MouseCode button) : MouseButtonEvent(button) {}

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseButtonPressedEvent: " << (int)button;
            return ss.str();
        }

        EVENT_CLONE(MouseButtonPressedEvent)
        EVENT_CLASS_TYPE(MouseButtonPressed)
    };

    class ENGINE_API MouseButtonReleasedEvent : public MouseButtonEvent
    {
    public:
        MouseButtonReleasedEvent(const MouseCode button) : MouseButtonEvent(button) {}

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseButtonReleasedEvent: " << (int)button;
            return ss.str();
        }

        EVENT_CLONE(MouseButtonReleasedEvent)
        EVENT_CLASS_TYPE(MouseButtonReleased)
    };

}

#endif //WEHAPPYFEW_MOUSEEVENTS_H
