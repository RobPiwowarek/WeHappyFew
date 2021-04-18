/*  
 *  Created by michal-swiatek on 18.04.2021.
 *
 *  Github: https://github.com/michal-swiatek
 */

#include <Engine.h>

class Game : public engine::Application
{
};

std::unique_ptr<engine::Application> engine::CreateApplication()
{
    return std::make_unique<Game>();
}
