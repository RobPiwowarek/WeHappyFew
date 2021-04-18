/*  
 *  Created by michal-swiatek on 18.04.2021.
 *
 *  Github: https://github.com/michal-swiatek
 */

#ifndef WEHAPPYFEW_ENTRYPOINT_H
#define WEHAPPYFEW_ENTRYPOINT_H

#include <memory>

extern std::unique_ptr<engine::Application> engine::CreateApplication();

int main(int argc, char** argv)
{
    auto app = engine::CreateApplication();

    app->Run();

    return 0;
}

#endif //WEHAPPYFEW_ENTRYPOINT_H
