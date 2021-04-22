/*  
 *  Created by michal-swiatek on 22.04.2021.
 *
 *  Github: https://github.com/michal-swiatek
 */

#include "pch.h"
#include "Platform/OpenGL/OpenGlIndexBuffer.h"

#include <glad/glad.h>

namespace engine {

    OpenGlIndexBuffer::OpenGlIndexBuffer(uint32_t *indices, uint32_t count) : count(count)
    {
        glCreateBuffers(1, &vbo);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(uint32_t), indices, GL_STATIC_DRAW);
    }

    OpenGlIndexBuffer::~OpenGlIndexBuffer()
    {
        glDeleteBuffers(1, &vbo);
    }

    void OpenGlIndexBuffer::Bind()
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo);
    }

    void OpenGlIndexBuffer::UnBind()
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

    uint32_t OpenGlIndexBuffer::GetCount() const
    {
        return count;
    }

}
