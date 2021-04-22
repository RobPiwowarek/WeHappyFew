/*  
 *  Created by michal-swiatek on 22.04.2021.
 *
 *  Github: https://github.com/michal-swiatek
 */

#ifndef WEHAPPYFEW_OPENGLINDEXBUFFER_H
#define WEHAPPYFEW_OPENGLINDEXBUFFER_H

#include "Core/EngineApi.h"
#include "Rendering/Buffers.h"

namespace engine {

    class ENGINE_API OpenGlIndexBuffer : public IndexBuffer
    {
    public:
        OpenGlIndexBuffer(uint32_t* indices, uint32_t count);
        ~OpenGlIndexBuffer() override;

        void Bind() override;
        void UnBind() override;

        [[nodiscard]] uint32_t GetCount() const override;

    private:
        uint32_t vbo{};
        uint32_t count;
    };

}

#endif //WEHAPPYFEW_OPENGLINDEXBUFFER_H
