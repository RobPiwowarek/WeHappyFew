/*  
 *  Created by michal-swiatek on 20.04.2021.
 *
 *  Github: https://github.com/michal-swiatek
 */

#include "pch.h"
#include "Core/Layer.h"

namespace engine {

    Layer::Layer(std::string name) : debugName(std::move(name)) {}

    void Layer::OnAttach() {}
    void Layer::OnDetach() {}
    void Layer::OnUpdate() {}
    void Layer::OnImGuiRender() {}
    void Layer::OnEvent(Event &event) {}

}
