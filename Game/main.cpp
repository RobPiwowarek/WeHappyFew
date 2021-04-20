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
