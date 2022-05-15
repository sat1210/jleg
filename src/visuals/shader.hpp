#ifndef SHADER_HPP
#define SHADER_HPP

#include <iostream>
#include "glad/glad.h"
#include <string>

#include <fstream> //check
#include <sstream> //check
#include <cerrno> //check

std::string get_file_contents(const char* filename);

namespace jleg{
    class shader{
        public:
            GLuint id; //reference
            shader();
            shader(const char* vertex_file, const char* fragment_file);
            void activate();
            void remove();
    };
};

#endif
