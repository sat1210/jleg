#ifndef INPUT_HPP
#define INPUT_HPP
#include "visuals.hpp"
#include "logger.hpp"
#include <string>
#include <map>
#include "vec2.hpp"

namespace jleg{
    extern std::map<std::string, int> key_map;
    bool is_action_pressed(std::string name);
    // vec2 get_global_mouse_position(){};
};

#endif
