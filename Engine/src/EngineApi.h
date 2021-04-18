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

#endif //WEHAPPYFEW_ENGINEAPI_H
