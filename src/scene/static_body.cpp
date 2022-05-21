#include "static_body.hpp"

namespace jleg{
    static_body::static_body(){
        this->name = "StaticBody";
    };

    static_body::static_body(vec2 _position, vec2 _size){
        this->name = "StaticBody";
        this->size = _size;
        this->position = _position;

        this->body = create_body(STATIC_BODY, this->position, this->size); //set to physics
    };

    void static_body::update(){
        // this->position = vec2(this->body->GetPosition()) * vec2(1.0f, -1.0f) * cell_size;
        this->position = get_body_position(this->body);
    };
};
