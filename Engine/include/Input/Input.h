/*  
 *  Created by michal-swiatek on 20.04.2021.
 *
 *  Github: https://github.com/michal-swiatek
 */

#ifndef WEHAPPYFEW_INPUT_H
#define WEHAPPYFEW_INPUT_H

#include "Core/EngineApi.h"

#include "Input/KeyCodes.h"
#include "Input/MouseCodes.h"

namespace engine {

    class ENGINE_API Input
    {
    public:
        static bool IsKeyPressed(KeyCode key);
        static bool IsButtonPressed(MouseCode button);

        static float GetMouseX();
        static float GetMouseY();
    };

}

#endif //WEHAPPYFEW_INPUT_H
