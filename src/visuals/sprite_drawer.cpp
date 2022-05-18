#include "sprite_drawer.hpp"

jleg::sprite_drawer::sprite_drawer(){
    //do nothing
}

jleg::sprite_drawer::sprite_drawer(shader* _shader){
    glGenVertexArrays(1, &this->vao);
    glGenBuffers(1, &this->vbo);
    glGenBuffers(1, &this->ebo);

    glBindVertexArray(this->vao);

    glBindBuffer(GL_ARRAY_BUFFER, this->vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(this->vertices), this->vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(this->indices), this->indices, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void*)0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void*)(3 * sizeof(float)));

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    this->sprite_shader = _shader;
};


void jleg::sprite_drawer::draw(texture _texture, glm::mat4 _model){
    glActiveTexture(0);
    glBindTexture(GL_TEXTURE_2D, _texture.id);
    glUniform1i(glGetUniformLocation(this->sprite_shader->id, "tex"), 0);

    //calculate model matrix
    glm::mat4 model = _model;
    // model = glm::translate(model, glm::vec3(_sprite->position.to_glm(), 0.0f));
    // model = glm::translate(model, glm::vec3(_texture.offset.to_glm(), 0.0f));
    if (_texture.centered){
        model = glm::translate(model, glm::vec3(_texture.size.to_glm() * -0.5f, 0.0f));
    };
    model = glm::scale(model, glm::vec3(_texture.size.to_glm(), 0.0f));

    glUniformMatrix4fv(glGetUniformLocation(sprite_shader->id, "model"), 1, GL_FALSE, glm::value_ptr(model));

    glBindVertexArray(this->vao);

    glDrawElements(GL_TRIANGLES, sizeof(this->indices) / sizeof(GLuint), GL_UNSIGNED_INT, 0);
};
