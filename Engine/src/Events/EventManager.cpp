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

    void EventManager::BufferEvent(Event &event)
    {
        events.push_back(event.Clone());
    }

    void EventManager::DispatchEvents(LayerStack& layerStack)
    {
        //  Dispatch all events across supplied layers
        for (auto* event : events)
        {
            for (auto it = layerStack.rbegin(); it != layerStack.rend(); ++it)
            {
                (*it)->OnEvent(*event);

                if (event->handled)
                    break;
            }
        }

        //  Unhandled events are ignored
        CLearEvents();
    }

    void EventManager::CLearEvents()
    {
        for (auto event : events)
            delete event;

        events.clear();
    }

}
