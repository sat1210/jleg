#include "texture.hpp"

jleg::texture::texture(){

};

jleg::texture::texture(const char* _texture){
    int width_img, height_img, num_col_ch;
    stbi_set_flip_vertically_on_load(true);
    unsigned char* bytes = stbi_load(_texture, &width_img, &height_img, &num_col_ch, 0);


    glGenTextures(1, &id);
    glActiveTexture(0);
    glBindTexture(GL_TEXTURE_2D, id);


    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);


    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width_img, height_img, 0, GL_RGBA, GL_UNSIGNED_BYTE, bytes);
    glGenerateMipmap(GL_TEXTURE_2D);


    stbi_image_free(bytes);
    glBindTexture(GL_TEXTURE_2D, 0);


    this->size = vec2((float) width_img, (float) height_img);
    this->offset = vec2(this->size.x * -0.5f, this->size.y * -0.5f);

};

void jleg::texture::remove(){
    glDeleteTextures(1, &id);
};
// glDeleteTextures(1, &ID);
// this->offset = vec2(this->size.x * -0.5f, this->size.y * -0.5f);

// type = tex_type;
// int width_img, height_img, num_col_ch;
// stbi_set_flip_vertically_on_load(true);
// unsigned char* bytes = stbi_load(image, &width_img, &height_img, &num_col_ch, 0);
//
// glGenTextures(1, &ID);
// glActiveTexture(GL_TEXTURE0 + slot);
// unit = slot;
// glBindTexture(tex_type, ID);
//
// glTexParameteri(tex_type, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
// glTexParameteri(tex_type, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//
// glTexParameteri(tex_type, GL_TEXTURE_WRAP_S, GL_REPEAT);
// glTexParameteri(tex_type, GL_TEXTURE_WRAP_T, GL_REPEAT);
//
// glTexImage2D(tex_type, 0, GL_RGBA, width_img, height_img, 0, format, pixel_type, bytes);
// glGenerateMipmap(tex_type);
//
// stbi_image_free(bytes);
// glBindTexture(tex_type, 0);

// void Texture::tex_unit(Shader& shader, const char* uniform, GLuint unit){
//     GLuint texuni = glGetUniformLocation(shader.ID, uniform);
//     shader.activate();
//     glUniform1i(texuni, unit);
// }

// void Texture::bind(){
//     glActiveTexture(GL_TEXTURE0 + unit);
//     glBindTexture(type, ID);
// }
//
// void Texture::unbind(){
//     glBindTexture(type, 0);
// }


// Texture::Texture(const char* image, GLenum tex_type, GLuint slot, GLenum format, GLenum pixel_type){
// cout << to_string(width_img) << to_string(height_img) << to_string(num_col_ch);
