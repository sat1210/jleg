#include "jleg/jleg.hpp"
#include "player.hpp"
#include <iostream>
#include <fstream>
#include "nlohmann/json.hpp"

namespace game{
    jleg::sprite platform;
    jleg::sprite knight;
    jleg::sprite trees;
    jleg::texture tile;
    jleg::sprite tile_sprite;
    game::player _player;
    jleg::static_body ground;
    jleg::node root_node;
    // jleg::tileset test_tileset;
    jleg::tilemap test_tilemap(jleg::vec2(256.0f, 128.0f));
    // jleg::tilemap test_tilemap(jleg::vec2(256.0f, 128.0f));
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
    game::trees = jleg::sprite("res/textures/trees.png"); //mvoe to scene?
    game::tile = jleg::texture("res/textures/tile.png"); //mvoe to scene?
    game::tile_sprite.tex = game::tile;

    // game::test_tilemap.set_position(jleg::vec2(256.0f, 128.0f));
    // game::test_tilemap = jleg::tilemap(jleg::vec2(256.0f, 128.0f));
    // game::test_tilemap = jleg::tilemap(jleg::vec2(256.0f, 128.0f));
    game::ground = jleg::static_body(jleg::vec2(game::platform.tex.size.x / 2.0f, -128.0f), game::platform.tex.size);
    game::_player = game::player(jleg::vec2(128.0f, 0.0f), game::knight.tex.size); //not included in visuals.cpp

    game::root_node.add_child(&game::test_tilemap);
    game::root_node.add_child(&game::_player);
    game::root_node.add_child(&game::ground);
    game::root_node.add_child(&game::trees);
    game::root_node.add_child(&game::tile_sprite);
    // game::root_node.add_child(&game::tile);


    game::trees.set_position(jleg::vec2(128.0f, 48.0f));
    // game::tile.set_position(jleg::vec2(128.0f, 48.0f));
    game::ground.add_child(&game::platform);
    game::_player.add_child(&game::knight);
    game::test_tilemap.set_texture(0, game::tile);
    jleg::register_sprite(&game::platform);
    jleg::register_sprite(&game::knight);
    jleg::register_sprite(&game::trees);
    jleg::register_sprite(&game::tile_sprite);
    // jleg::register_sprite(&game::tile);
    game::test_tilemap.drawer = game::knight.drawer;

    // std::cout << &game::_player << std::endl;
    // std::cout << &game::root_node.get_children().front() << std::endl;
    // std::cout << &game::root_node.get_children().back() << std::endl;
    jleg::start_loop(graph);
};
