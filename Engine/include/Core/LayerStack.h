/*  
 *  Created by michal-swiatek on 20.04.2021.
 *
 *  Github: https://github.com/michal-swiatek
 */

#ifndef WEHAPPYFEW_LAYERSTACK_H
#define WEHAPPYFEW_LAYERSTACK_H

#include <vector>

#include "Core/Layer.h"
#include "Core/EngineApi.h"

namespace engine {

    class ENGINE_API LayerStack
    {
    public:
        LayerStack() = default;
        ~LayerStack();

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* overlay);
        void PopLayer(Layer* layer);
        void PopOverlay(Layer* overlay);

        std::vector<Layer*>::iterator begin() { return layers.begin(); }
        std::vector<Layer*>::iterator end() { return layers.end(); }
        std::vector<Layer*>::reverse_iterator rbegin() { return layers.rbegin(); }
        std::vector<Layer*>::reverse_iterator rend() { return layers.rend(); }

        std::vector<Layer*>::const_iterator begin() const { return layers.begin(); }
        std::vector<Layer*>::const_iterator end()	const { return layers.end(); }
        std::vector<Layer*>::const_reverse_iterator rbegin() const { return layers.rbegin(); }
        std::vector<Layer*>::const_reverse_iterator rend() const { return layers.rend(); }

    private:
        std::vector<Layer*> layers;

        unsigned int layerInsertIndex = 0;
    };

}

#endif //WEHAPPYFEW_LAYERSTACK_H
