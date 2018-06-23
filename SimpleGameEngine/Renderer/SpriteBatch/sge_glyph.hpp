//
// Created by Janusz Majchrzak on 30/10/2017.
//

#ifndef SGE_ZOMBIEGAME_SGE_GLYPH_HPP
#define SGE_ZOMBIEGAME_SGE_GLYPH_HPP

#include <GL/glew.h>
#include "../Vertex/sge_vertex.hpp"

namespace SGE
{
    struct Glyph
    {
        GLuint texture = 0;

        float depth = 0;

        Vertex topLeft;

        Vertex bottomLeft;

        Vertex topRight;

        Vertex bottomRight;
    };
}

#endif //SGE_ZOMBIEGAME_SGE_GLYPH_HPP