#ifndef VISUALS_HPP
#define VISUALS_HPP

//graphics libraries
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "string"
//nodes
#include "node.hpp"
#include "camera.hpp"
#include "character_body.hpp"
#include "static_body.hpp"
#include "sprite.hpp"
#include "scene_graph.hpp"
//visuals
#include "shader.hpp"
#include "sprite_drawer.hpp"
#include "texture.hpp"
//other componenets
#include "physics.hpp"
#include "game.hpp"
#include <iostream>

namespace jleg{
    extern GLFWwindow* window;
    extern std::vector<jleg::sprite*> sprites;
    extern shader shader_program;
    extern sprite_drawer drawer;
    extern camera cam;
    extern node* root_node;
    extern glm::mat4 proj;

    extern int screen_width;
    extern int screen_height;
    extern float screen_scale;
    extern std::string game_name;

    // extern int FRAME_RATE = 60;

    void register_sprite(jleg::sprite* _sprite);
    void start_loop(jleg::scene_graph _graph);
    int create_window();
};

#endif
