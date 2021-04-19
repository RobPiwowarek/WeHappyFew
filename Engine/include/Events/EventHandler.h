/*
 *  Created by michal-swiatek on 19.04.2021.
 *
 *  Github: https://github.com/michal-swiatek
 *
 *  From Cherno game engine series: https://www.youtube.com/playlist?list=PLlrATfBNZ98dC-V-N3m0Go4deliWHPFwT
 */

#ifndef WEHAPPYFEW_EVENTHANDLER_H
#define WEHAPPYFEW_EVENTHANDLER_H

#include "Events/Event.h"
#include "Core/EngineApi.h"

namespace engine {

    class ENGINE_API EventHandler
    {
    public:
        explicit EventHandler(Event& event) : event(event) {}

        template<class AcceptedEvent, class F>
        bool Handle(const F& func)
        {
            if (event.GetEventType() == AcceptedEvent::GetStaticType())
            {
                event.handled |= func(static_cast<AcceptedEvent&>(event));
                return true;
            }
            return false;
        }

    private:
        Event& event;
    };

}

#endif //WEHAPPYFEW_EVENTHANDLER_H
