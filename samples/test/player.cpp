#include "player.hpp"

namespace game{
    player::player(){
        //do nothing
    };
    player::player(jleg::vec2 _position, jleg::vec2 _size){
        this->size = _size;
        this->position = _position;

        this->body = jleg::create_body(jleg::CHARACTER_BODY, this->position, this->size);
    };
    void player::physics_process(float delta){
        jleg::vec2 new_vel = this->get_velocity();
        float dir = 0.0;
        if (jleg::is_key_pressed("d")){
            dir += 1.0f;
        };
        if (jleg::is_key_pressed("a")){
            dir += -1.0f;
        };
        if (jleg::is_key_pressed("w")){
            if (!this->first_jump){
                new_vel.y = 16.0f;
            };
            this->first_jump = true;
        }
        else {
            this->first_jump = false;
        };
        new_vel.x += dir * 4.0f;
        new_vel.x = new_vel.x * this->damp;
        this->set_velocity(new_vel);
        // if (jleg::is_mouse_pressed("mouse1")){
        //     this->set_position(jleg::get_mouse_position());
        // };
    };
};
