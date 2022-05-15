#include "input.hpp"

namespace jleg{
    std::map<std::string, int> key_map = {
        {"w", GLFW_KEY_W},
        {"a", GLFW_KEY_A},
        {"s", GLFW_KEY_S},
        {"d", GLFW_KEY_D},
    };
    bool is_action_pressed(std::string name){
        return glfwGetKey(window, key_map[name]) == GLFW_PRESS;
    };
};
