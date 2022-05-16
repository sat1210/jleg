#include "jleg/jleg.hpp"
#include "player.hpp"
#include <iostream>

// void jleg::game_render_loop(){
//     //do nothing
// };

namespace game{
    jleg::sprite platform;
    jleg::sprite knight;
    game::player _player;
    jleg::static_body ground;
    jleg::node root_node;
    bool first_jump = false;
};

// void jleg::game_physics_loop(){
//     float dir = 0.0;
//     if (is_action_pressed("d")){
//         dir += 1.0f;
//     };
//     if (is_action_pressed("a")){
//         dir += -1.0f;
//     };
//     if (is_action_pressed("w")){
//         if (!game::first_jump){
//             game::player.body->SetLinearVelocity(b2Vec2(game::player.body->GetLinearVelocity().x, 16.0f));
//         };
//         game::first_jump = true;
//     }
//     else {
//         game::first_jump = false;
//     };
//     game::player.body->SetLinearVelocity(b2Vec2(dir * 8.0f, game::player.body->GetLinearVelocity().y));
// };

int main(){
    std::cout << "game start" << std::endl;

    jleg::create_window();

    jleg::scene_graph graph;
    game::root_node = jleg::node();
    graph.root_node = &game::root_node;
    game::platform = jleg::sprite("res/textures/platform.png"); //mvoe to scene?
    game::knight = jleg::sprite("res/textures/player.png"); //mvoe to scene?
    game::ground = jleg::static_body(jleg::vec2(game::platform.tex.size.x / 2.0f, -128.0f), game::platform.tex.size);
    // game::player = jleg::character_body(jleg::vec2(128.0f, 0.0f), game::knight.tex.size);
    game::_player = game::player(jleg::vec2(128.0f, 0.0f), game::knight.tex.size); //not included in visuals.cpp
    //game loop cant call player.physics_process because it doesnt know
    //wtf a player is
    game::root_node.add_child(&game::_player);
    game::root_node.add_child(&game::ground);
    game::ground.add_child(&game::platform);
    game::_player.add_child(&game::knight);
    jleg::register_sprite(&game::platform);
    jleg::register_sprite(&game::knight);

    std::cout << &game::_player << std::endl;
    std::cout << &game::root_node.get_children().front() << std::endl;
    std::cout << &game::root_node.get_children().back() << std::endl;
    // jleg::log(game::_player);
    // jleg::log(game::root_node.get_children().front());

    jleg::start_loop(graph);
};
