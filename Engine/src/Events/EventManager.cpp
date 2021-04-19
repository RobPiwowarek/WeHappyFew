/*
 *  Created by michal-swiatek on 19.04.2021.
 *
 *  Github: https://github.com/michal-swiatek
 */

#include "pch.h"
#include "Events/EventManager.h"

namespace engine {

    EventManager::EventManager()
//        : buffer(bufferSize), alloc(buffer.data(), buffer.data() + bufferSize)
    {
        events.reserve(128);    //  TODO: Create constant
    }

    EventManager::~EventManager()
    {
        CLearEvents();
    }

    void EventManager::OnEvent(Event &event)
    {
        events.push_back(event.Clone());
    }

    void EventManager::DispatchEvents()
    {
        CLearEvents();
    }

    void EventManager::RemoveEvent(Event *&event)
    {
        delete event;   //  EventManager owns cloned events
        std::swap(event, events.back());
        events.pop_back();
    }

    void EventManager::CLearEvents()
    {
        for (auto event : events)
            delete event;

        events.clear();
    }

}
