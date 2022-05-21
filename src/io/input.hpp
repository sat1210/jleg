#ifndef INPUT_HPP
#define INPUT_HPP
#include "visuals.hpp"
#include "log.hpp"
#include <string>
#include <map>
#include "vec2.hpp"


namespace jleg{
    extern std::map<std::string, int> key_map;
    bool is_key_pressed(std::string name);
    vec2 get_mouse_position();
    bool is_mouse_pressed(std::string name);
};

#endif
