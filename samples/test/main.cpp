#include "jleg/jleg.hpp"
#include "player.hpp"
#include <iostream>
#include <fstream>
#include "nlohmann/json.hpp"

namespace game{
    jleg::sprite platform;
    jleg::sprite knight;
    game::player _player;
    jleg::static_body ground;
    jleg::node root_node;
    bool first_jump = false;
};

int main(){
    std::ifstream config_file("res/configs/config.json");
    nlohmann::json config_json;
    config_file >> config_json;


    jleg::init();
    // jleg::create_window();

    jleg::scene_graph graph;
    game::root_node = jleg::node();
    graph.root_node = &game::root_node;
    game::platform = jleg::sprite("res/textures/platform.png"); //mvoe to scene?
    game::knight = jleg::sprite("res/textures/player.png"); //mvoe to scene?
    game::ground = jleg::static_body(jleg::vec2(game::platform.tex.size.x / 2.0f, -128.0f), game::platform.tex.size);
    game::_player = game::player(jleg::vec2(128.0f, 0.0f), game::knight.tex.size); //not included in visuals.cpp
    game::root_node.add_child(&game::_player);
    game::root_node.add_child(&game::ground);
    game::ground.add_child(&game::platform);
    game::_player.add_child(&game::knight);
    jleg::register_sprite(&game::platform);
    jleg::register_sprite(&game::knight);
    std::cout << &game::_player << std::endl;
    std::cout << &game::root_node.get_children().front() << std::endl;
    std::cout << &game::root_node.get_children().back() << std::endl;
    jleg::start_loop(graph);
};
