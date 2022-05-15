#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "glm/gtx/rotate_vector.hpp"
#include "glm/gtx/vector_angle.hpp"

#include "shader.hpp"
#include "node.hpp"
#include "vec2.hpp"

namespace jleg{
    class camera : public node{
        public:
            vec2 zoom;
            glm::mat4 cam_matrix = glm::mat4(1.0f);
            int width;
            int height;
            bool current = false;

            camera();
            camera(int _width, int _height, jleg::vec2 _position);
            void matrix(shader& shader, const char* uniform);
    };
};

#endif
