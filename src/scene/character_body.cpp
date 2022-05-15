#include "character_body.hpp"

namespace jleg{
    character_body::character_body(){
        //do nothing
    };

    character_body::character_body(vec2 _position, vec2 _size){
        this->size = _size;
        this->position = _position;

        this->body = create_body(CHARACTER_BODY, this->position, this->size);
    };

    void character_body::update(){
        this->position = vec2(this->body->GetPosition()) * vec2(1.0f, -1.0f) * cell_size;
    };
};
