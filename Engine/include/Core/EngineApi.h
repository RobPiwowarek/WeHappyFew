/*  
 *  Created by michal-swiatek on 18.04.2021.
 *
 *  Github: https://github.com/michal-swiatek
 */

#ifndef WEHAPPYFEW_ENGINEAPI_H
#define WEHAPPYFEW_ENGINEAPI_H

#ifdef ENGINE_BUILD_DLL
    #define ENGINE_API __declspec(dllexport)
#else
    #define ENGINE_API __declspec(dllimport)
#endif

#define BIT(x) (1 << x)

#define BIND_EVENT_FUNCTION(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

#endif //WEHAPPYFEW_ENGINEAPI_H
