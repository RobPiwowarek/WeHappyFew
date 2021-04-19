/*
 *  Created by michal-swiatek on 19.04.2021.
 *
 *  Github: https://github.com/michal-swiatek
 */

#ifndef WEHAPPYFEW_LINEARALLOCATOR_H
#define WEHAPPYFEW_LINEARALLOCATOR_H

#include <memory>
#include <cstddef>

#include "Core/EngineApi.h"

namespace engine {

    class ENGINE_API LinearAllocator
    {
    public:
        LinearAllocator(std::byte* bufferStart, std::byte* bufferEnd)
            : bufferStart(bufferStart), bufferSize(bufferEnd - bufferStart)
        {
            Clear();
        }

        ~LinearAllocator()
        {
            Clear();
        }

        template <class T, class... Args>
        T* New(Args&&... args)
        {
            auto ptr = std::align(alignof(T), sizeof(T), currentPos, bufferSize);

            if (ptr)
            {
                currentPos = reinterpret_cast<std::byte*>(currentPos) + sizeof(T);
                bufferSize -= sizeof(T);
                new (ptr) T(std::forward<Args>(args)...);
            }

            return ptr;
        }

        inline void Clear() { currentPos = bufferStart; }

    private:
        std::byte* bufferStart;
        std::size_t bufferSize;

        void* currentPos;
    };

}

#endif //WEHAPPYFEW_LINEARALLOCATOR_H
