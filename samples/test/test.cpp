#include "jleg/jleg.hpp"
#include <iostream>

#include "test.hpp"

void jleg::game_render_loop(){
    //do nothing
};

namespace game{
    jleg::sprite platform;
    jleg::sprite knight;
    jleg::character_body player;
    jleg::static_body ground;
    jleg::node root_node;
    bool first_jump = false;
};

void jleg::game_physics_loop(){
    vec2 player_position = vec2(game::player.body->GetPosition());
    vec2 ground_position = vec2(game::ground.body->GetPosition());
    game::platform.position = ground_position * vec2(1.0f, -1.0f) * jleg::cell_size;
    game::knight.position = player_position * vec2(1.0f, -1.0f) * jleg::cell_size;
    std::cout << game::knight.position.x << " " << game::knight.position.y << std::endl;
    float dir = 0.0;
    if (is_action_pressed("d")){
        dir += 1.0f;
    };
    if (is_action_pressed("a")){
        dir += -1.0f;
    };
    if (is_action_pressed("w")){
        if (!game::first_jump){
            game::player.body->SetLinearVelocity(b2Vec2(game::player.body->GetLinearVelocity().x, 16.0f));
        };
        game::first_jump = true;
    }
    else {
        game::first_jump = false;
    };
    game::player.body->SetLinearVelocity(b2Vec2(dir * 8.0f, game::player.body->GetLinearVelocity().y));
};

int main(){
    std::cout << "game start" << std::endl;

    jleg::create_window();

    jleg::scene_graph graph;
    game::root_node = jleg::node();
    graph.root_node = &game::root_node;
    game::platform = jleg::sprite("res/textures/platform.png"); //mvoe to scene?
    game::knight = jleg::sprite("res/textures/player.png"); //mvoe to scene?
    game::ground = jleg::static_body(jleg::vec2(game::platform.tex.size.x / 2.0f, -128.0f), game::platform.tex.size);
    game::player = jleg::character_body(jleg::vec2(128.0f, 0.0f), game::knight.tex.size);
    game::root_node.add_child(&game::ground);
    game::root_node.add_child(&game::player);
    game::ground.add_child(&game::platform);
    game::player.add_child(&game::knight);
    jleg::register_sprite(&game::platform);
    jleg::register_sprite(&game::knight);

    jleg::start_loop(graph);
};
