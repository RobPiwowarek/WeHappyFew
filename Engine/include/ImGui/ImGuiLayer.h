/*  
 *  Created by michal-swiatek on 20.04.2021.
 *
 *  Github: https://github.com/michal-swiatek
 */

#ifndef WEHAPPYFEW_IMGUILAYER_H
#define WEHAPPYFEW_IMGUILAYER_H

#include "Core/EngineApi.h"
#include "Core/Layer.h"

#include "Events/ApplicationEvents.h"
#include "Events/KeyEvents.h"
#include "Events/MouseEvents.h"

namespace engine {

    class ENGINE_API ImGuiLayer : public Layer
    {
    public:
        ImGuiLayer();
        ~ImGuiLayer() override = default;

        void OnAttach() override;
        void OnDetach() override;
        void OnEvent(Event& e) override;

        void Begin();
        void End();

        inline void BlockEvents(bool block) { blockEvents = block; }

        void SetDarkThemeColors();

    private:
        bool blockEvents = true;
        bool showWindow = true;
        float time = 0.0f;

        //  TODO: Remove
        float backgroundColor[4] = {0, 0, 0.4, 0};
    };

}

#endif //WEHAPPYFEW_IMGUILAYER_H
