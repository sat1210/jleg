#ifndef VEC2I_HPP
#define VEC2I_HPP

#include <string>
#include <iostream>

namespace jleg{
    class vec2i{
        public:
            int x;
            int y;
            vec2i();
            vec2i(int _x, int _y);
            std::string printable();
            vec2i operator+(vec2i _by);
            vec2i operator*(int _by);
            vec2i operator*(vec2i _by);
    };
};

#endif
