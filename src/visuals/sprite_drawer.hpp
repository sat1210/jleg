#ifndef SPRITE_DRAWER_HPP
#define SPRITE_DRAWER_HPP

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "shader.hpp"
#include <vector>
#include "vec2.hpp"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "glm/gtx/rotate_vector.hpp"
#include "glm/gtx/vector_angle.hpp"

#include "logger.hpp"
#include <string>
#include "texture.hpp"

namespace jleg{
    class sprite_drawer{
        public:
            GLfloat vertices[20] = {
               0.0f, 1.0f, 0.0f,		0.0f, 0.0f,
               0.0f, 0.0f, 0.0f,		0.0f, 1.0f,
               1.0f, 0.0f, 0.0f,		1.0f, 1.0f,
               1.0f, 1.0f, 0.0f,	    1.0f, 0.0f
           };
            GLuint indices[6] = {
                0, 1, 2,
                0, 2, 3
            };
            // std::vector<sprite*> sprites;//change
            GLuint vao, vbo, ebo;
            shader* sprite_shader;
            sprite_drawer();
            sprite_drawer(shader* _shader);
            // void draw(jleg::sprite* _sprite, glm::mat4 _model);//change
            void draw(texture _texture, glm::mat4 _model);//change
    };
};

#endif
