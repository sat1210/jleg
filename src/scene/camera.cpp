#include "camera.hpp"

namespace jleg{
    camera::camera(){
        //do nothing
    };

    camera::camera(int _width, int _height, vec2 _position){
        this->width = _width;
        this->height = _height;
        this->position = _position;
        glm::mat4 proj = glm::mat4(1.0f);
        proj = glm::ortho(0.0f, (float)this->width, (float)this->height, 0.0f, -1.0f, 1.0f);
        this->cam_matrix = proj;
    };

    // void camera::matrix(shader& shader, const char* uniform){
    //
    //
    //     // glUniformMatrix4fv(glGetUniformLocation(shader.id, uniform), 1, GL_FALSE, glm::value_ptr(_matrix));
    // };

    void camera::update(){ // todo: debug this
        glm::mat4 _matrix = this->cam_matrix;
        _matrix = glm::translate(_matrix, glm::vec3(this->position.to_glm(), 0.0f));
        jleg::proj = _matrix;
    };
};
