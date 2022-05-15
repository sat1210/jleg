#ifndef INPUT_HPP
#define INPUT_HPP
#include "visuals.hpp"
#include "logger.hpp"
#include <string>
#include <map>

namespace jleg{
    extern std::map<std::string, int> key_map;
    bool is_action_pressed(std::string name);
};

#endif
