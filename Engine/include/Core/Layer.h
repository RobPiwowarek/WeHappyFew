/*  
 *  Created by michal-swiatek on 20.04.2021.
 *
 *  Github: https://github.com/michal-swiatek
 */

#ifndef WEHAPPYFEW_LAYER_H
#define WEHAPPYFEW_LAYER_H

#include "Events/Event.h"
#include "Core/EngineApi.h"

namespace engine {

    class ENGINE_API Layer
    {
    public:
        explicit Layer(std::string name = "Layer");
        virtual ~Layer() = default;

        virtual void OnAttach();
        virtual void OnDetach();
        virtual void OnUpdate();
        virtual void OnImGuiRender();
        virtual void OnEvent(Event& event);

        [[nodiscard]] inline const std::string& GetName() const { return debugName; }

    protected:
        std::string debugName;
    };

}

#endif //WEHAPPYFEW_LAYER_H
