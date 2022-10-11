#include "input.hpp"

namespace jleg{
    std::map<std::string, int> key_map = {
        {"a", GLFW_KEY_A},
        {"d", GLFW_KEY_D},
        {"s", GLFW_KEY_S},
        {"w", GLFW_KEY_W},
        {"mouse1", GLFW_MOUSE_BUTTON_1},
        {"mouse2", GLFW_MOUSE_BUTTON_2},
    };

    bool is_key_pressed(std::string name){
        return glfwGetKey(window, key_map[name]) == GLFW_PRESS;
    };

    vec2 get_mouse_position(){
        double mouse_x, mouse_y;
        glfwGetCursorPos(window, &mouse_x, &mouse_y);
        return vec2(mouse_x, mouse_y) / jleg::screen_scale;
    };

    bool is_mouse_pressed(std::string name){
        return glfwGetMouseButton(window, key_map[name]) == GLFW_PRESS;
    };
};
