#include "tilemap.hpp"

namespace jleg{
    tilemap::tilemap(){
        this->name = "TileMap";
    };

    tilemap::tilemap(vec2 _position){
        this->name = "TileMap";
        this->position = _position;
        for (int i = 0; i < 256; i++){
            vec2 tile_pos;
            tile_pos.x = (float)(i % this->size.x);
            tile_pos.y = -(float)(i / this->size.x);
            tile_pos = tile_pos * 16.0f;
            // this->tile_bodies[i] = create_body(STATIC_BODY, this->position + tile_pos, vec2(16.0f, 16.0f));
            // this->tile_bodies[i] = create_body(STATIC_BODY, this->position + tile_pos, vec2(16.0f, 16.0f));
            this->tile_bodies[i] = create_body(STATIC_BODY, this->position*vec2(1.0f, -1.0f) + vec2(8.0f, -8.0f) + tile_pos, vec2(16.0f, 16.0f));
        };
    };


    void tilemap::set_cell(vec2i _pos, int _id){
        this->tile_data[_pos.y * this->size.x + _pos.x] = _id;
    };

    void tilemap::set_texture(int id, texture _tex){
        this->textures.push_back(_tex);
        // this->textures[id] = _tex;
    };


    void tilemap::update(){
        for (int i = 0; i < 256; i++){
            int tile_id = this->tile_data[i];
            if (tile_id != -1){
                texture tex = this->textures[tile_id];
                vec2 tile_pos;
                tile_pos.x = (float)(i % this->size.x);
                tile_pos.y = (float)(i / this->size.x);
                tile_pos = tile_pos * 16.0f;
                glm::mat4 model = glm::mat4(1.0f);
                model = glm::translate(model, glm::vec3(tile_pos.to_glm(), 0.0f));
                this->drawer.draw(tex, this->get_global_model_matrix()*model);
            };
        };
    };
    // void tilemap::update(){
    //     for (tilemap_chunk16 chunk : this->chunks){
    //         for (int tile : chunk.tile_data){
    //             if (tile != -1){
    //                 drawer.draw();
    //                 this->drawer.draw(this->tex, this->get_global_model_matrix());
    //             };
    //         };
    //     };
    // };

};