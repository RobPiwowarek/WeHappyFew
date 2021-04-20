/*
 *  Created by michal-swiatek on 19.04.2021.
 *
 *  Github: https://github.com/michal-swiatek
 */

#ifndef WEHAPPYFEW_EVENTMANAGER_H
#define WEHAPPYFEW_EVENTMANAGER_H

#include <vector>

#include "Events/Event.h"
#include "Events/EventHandler.h"
#include "Core/LayerStack.h"

#include "Core/EngineApi.h"
#include "Memory/LinearAllocator.h"

namespace engine {

    class ENGINE_API EventManager
    {
    public:
        EventManager();
        ~EventManager();

        void BufferEvent(Event& event);
        void DispatchEvents(LayerStack& layerStack);

    private:
        void CLearEvents();

        std::vector<Event*> events;

        //  TODO: Implement static event type deduction
//        std::vector<std::byte> buffer;
//        LinearAllocator alloc;
    };

}

#endif //WEHAPPYFEW_EVENTMANAGER_H
