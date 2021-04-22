/*  
 *  Created by michal-swiatek on 22.04.2021.
 *
 *  Github: https://github.com/michal-swiatek
 */

#include "pch.h"
#include "Rendering/Buffers.h"

#include "Platform/OpenGL/OpenGlVertexBuffer.h"
#include "Platform/OpenGL/OpenGlIndexBuffer.h"

namespace engine {

    VertexBuffer* VertexBuffer::Create(float *vertices, uint32_t size)
    {
        return new OpenGlVertexBuffer(vertices, size);
    }

    IndexBuffer* IndexBuffer::Create(uint32_t *indices, uint32_t count)
    {
        return new OpenGlIndexBuffer(indices, count);
    }

}
