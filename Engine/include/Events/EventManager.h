/*
 *  Created by michal-swiatek on 19.04.2021.
 *
 *  Github: https://github.com/michal-swiatek
 */

#ifndef WEHAPPYFEW_EVENTMANAGER_H
#define WEHAPPYFEW_EVENTMANAGER_H

#include <memory>
#include <vector>
#include <functional>

#include "Core/EngineApi.h"
#include "Events/Event.h"
#include "Events/EventHandler.h"
#include "Memory/LinearAllocator.h"

namespace engine {

    class ENGINE_API EventManager
    {
    public:
        EventManager();
        ~EventManager();

        void ReceiveEvent(Event& event);
        void DispatchEvents();

    private:
        void RemoveEvent(Event*& event);
        void CLearEvents();

        std::vector<Event*> events;

        //  TODO: Implement static event type deduction
//        std::vector<std::byte> buffer;
//        LinearAllocator alloc;
    };

}

#endif //WEHAPPYFEW_EVENTMANAGER_H
