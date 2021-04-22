/*  
 *  Created by michal-swiatek on 22.04.2021.
 *
 *  Github: https://github.com/michal-swiatek
 */

#ifndef WEHAPPYFEW_BUFFERS_H
#define WEHAPPYFEW_BUFFERS_H

#include "Core/EngineApi.h"

namespace engine {

    class ENGINE_API VertexBuffer
    {
    public:
        virtual ~VertexBuffer() = default;

        virtual void Bind() = 0;
        virtual void UnBind() = 0;

        static VertexBuffer* Create(float* vertices, uint32_t size);
    };

    class ENGINE_API IndexBuffer
    {
    public:
        virtual ~IndexBuffer() = default;

        virtual void Bind() = 0;
        virtual void UnBind() = 0;

        [[nodiscard]] virtual uint32_t GetCount() const = 0;

        static IndexBuffer* Create(uint32_t* indices, uint32_t count);
    };

}

#endif //WEHAPPYFEW_BUFFERS_H
