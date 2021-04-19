/*
 *  Created by michal-swiatek on 19.04.2021.
 *
 *  Github: https://github.com/michal-swiatek
 *
 *  From Cherno game engine series: https://www.youtube.com/playlist?list=PLlrATfBNZ98dC-V-N3m0Go4deliWHPFwT
 */

#ifndef WEHAPPYFEW_KEYEVENTS_H
#define WEHAPPYFEW_KEYEVENTS_H

#include <sstream>

#include "Events/Event.h"
#include "Input/KeyCodes.h"

namespace engine {

    class ENGINE_API KeyEvent : public Event
    {
    public:
        KeyCode GetKeyCode() const { return keyCode; }

        EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

    protected:
        KeyEvent(KeyCode keycode) : keyCode(keycode) {}

        KeyCode keyCode;
    };

    class ENGINE_API KeyPressedEvent : public KeyEvent
    {
    public:
        KeyPressedEvent(const KeyCode keycode, const uint16_t repeatCount)
                : KeyEvent(keycode), repeatCount(repeatCount) {}

        uint16_t GetRepeatCount() const { return repeatCount; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyPressedEvent: " << (int)keyCode << " (" << repeatCount << " repeats)";
            return ss.str();
        }

        EVENT_CLONE(KeyPressedEvent)
        EVENT_CLASS_TYPE(KeyPressed)

    private:
        uint16_t repeatCount;
    };

    class ENGINE_API KeyReleasedEvent : public KeyEvent
    {
    public:
        KeyReleasedEvent(const KeyCode keycode) : KeyEvent(keycode) {}

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyReleasedEvent: " << (int)keyCode;
            return ss.str();
        }

        EVENT_CLONE(KeyReleasedEvent)
        EVENT_CLASS_TYPE(KeyReleased)
    };

    class ENGINE_API KeyTypedEvent : public KeyEvent
    {
    public:
        KeyTypedEvent(const KeyCode keycode) : KeyEvent(keycode) {}

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyTypedEvent: " << (int)keyCode;
            return ss.str();
        }

        EVENT_CLONE(KeyTypedEvent)
        EVENT_CLASS_TYPE(KeyTyped)
    };

}

#endif //WEHAPPYFEW_KEYEVENTS_H
