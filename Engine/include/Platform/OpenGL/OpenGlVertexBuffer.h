/*  
 *  Created by michal-swiatek on 22.04.2021.
 *
 *  Github: https://github.com/michal-swiatek
 */

#ifndef WEHAPPYFEW_OPENGLVERTEXBUFFER_H
#define WEHAPPYFEW_OPENGLVERTEXBUFFER_H

#include "Core/EngineApi.h"
#include "Rendering/Buffers.h"

namespace engine {

    class ENGINE_API OpenGlVertexBuffer : public VertexBuffer
    {
    public:
        OpenGlVertexBuffer(float* vertices, uint32_t size);
        ~OpenGlVertexBuffer() override;

        void Bind() override;
        void UnBind() override;

    private:
        uint32_t vbo {};
    };

}

#endif //WEHAPPYFEW_OPENGLVERTEXBUFFER_H
