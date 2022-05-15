#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "stb_image.h"

#include "shader.hpp"
#include "vec2.hpp"
#include "logger.hpp"
#include <string>

namespace jleg{
    class texture{
        public:
            GLuint id;
            vec2 size;
            vec2 offset;
            texture();
            texture(const char* _texture);
            void remove();
    };
};


#endif
// Texture(const char* image, GLenum tex_type, GLuint slot, GLenum format, GLenum pixel_type);
// void tex_unit(Shader& shader, const char* uniform, GLuint unit);
// void bind();
// void unbind();
// GLenum type;
// GLuint unit;
// GLuint ID;
