/*  
 *  Created by michal-swiatek on 22.04.2021.
 *
 *  Github: https://github.com/michal-swiatek
 */

#include "pch.h"
#include "Platform/OpenGL/OpenGlVertexBuffer.h"

#include <glad/glad.h>

namespace engine {

    OpenGlVertexBuffer::OpenGlVertexBuffer(float *vertices, uint32_t size)
    {
        glCreateBuffers(1, &vbo);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
    }

    OpenGlVertexBuffer::~OpenGlVertexBuffer()
    {
        glDeleteBuffers(1, &vbo);
    }

    void OpenGlVertexBuffer::Bind()
    {
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
    }

    void OpenGlVertexBuffer::UnBind()
    {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

}
