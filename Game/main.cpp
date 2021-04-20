/*  
 *  Created by michal-swiatek on 18.04.2021.
 *
 *  Github: https://github.com/michal-swiatek
 */

#include <Engine.h>

class ProxyLayer : public engine::Layer
{
public:
    void OnEvent(engine::Event& event) override
    {
        if (!event.IsInCategory(engine::EventCategoryMouse))
            LOG_INFO("{0}", event.ToString());

        auto handler = engine::EventHandler(event);

        handler.Handle<engine::KeyPressedEvent>([](auto& e){ return true; });
        handler.Handle<engine::KeyReleasedEvent>([](auto& e){ return true; });
    }
};

class Game : public engine::Application
{
public:
    Game()
    {
        PushLayer(new ProxyLayer());
    }
};

std::unique_ptr<engine::Application> engine::CreateApplication()
{
    return std::make_unique<Game>();
}
