#include "character_body.hpp"

namespace jleg{
    character_body::character_body(){
        this->name = "CharacterBody";
    };

    character_body::character_body(vec2 _position, vec2 _size){
        this->name = "CharacterBody";
        this->size = _size;
        this->position = _position;

        this->body = create_body(CHARACTER_BODY, this->position, this->size);
    };

    void character_body::update(){
        this->position = vec2(this->body->GetPosition()) * vec2(1.0f, -1.0f) * cell_size;
    };

    void character_body::set_velocity(jleg::vec2 _velocity){
        this->body->SetLinearVelocity(_velocity.to_box2d());
    };

    vec2 character_body::get_velocity(){
        return vec2(this->body->GetLinearVelocity());
    };

    void character_body::process(float delta){
        //do nothing
    };
    void character_body::physics_process(float delta){
        //do nothing
    };
};
