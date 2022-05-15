#include "camera.hpp"

jleg::camera::camera(){
    //do nothing
};

jleg::camera::camera(int _width, int _height, jleg::vec2 _position){
    this->width = _width;
    this->height = _height;
    this->position = _position;
    glm::mat4 proj = glm::mat4(1.0f);
    proj = glm::ortho(0.0f, (float)this->width, (float)this->height, 0.0f, -1.0f, 1.0f);
    this->cam_matrix = proj;
};

void jleg::camera::matrix(shader& shader, const char* uniform){
    glm::mat4 _matrix = this->cam_matrix;
    _matrix = glm::translate(_matrix, glm::vec3(this->position.to_glm(), 0.0f));

    glUniformMatrix4fv(glGetUniformLocation(shader.id, uniform), 1, GL_FALSE, glm::value_ptr(_matrix));
};
