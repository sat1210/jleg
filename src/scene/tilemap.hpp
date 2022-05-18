#include <vector>
#include "node.hpp"
#include "texture.hpp"
#include "vec2.hpp"
#include "vec2i.hpp"
#include "sprite_drawer.hpp"
#include "physics.hpp"

namespace jleg{
    // class tileset{//ideally we should use texture atlas' but this is jleg so fuck tthat shit
    //     public:
    //         std::vector<texture> textures;
    //         std::vector<bool> collision;
    //         void set_texture(int id, texture _tex);
    //         void set_collision(int id, bool colliding);
    //     // id=0 ground tiles //collision yes or no
    //     // id=1 trees?
    // };
    // class tilemap_chunk16{
    //     int tile_data[256]; //16 by 16 tiles
    //     tilemap_chunk16(){
    //         for (int i = 0, i < 256, i++){
    //             tile_data[i] = -1;
    //         };
    //     };
    //     //maybe it would represent id?
    //     bool check_visibility();
    // };
    class tilemap : public node{
        public:
            tilemap();
            tilemap(vec2 _position);
            vec2i size = vec2i(16, 16);
            // tileset tiles;
            int tile_data[256];
            std::vector<texture> textures;
            b2Body* tile_bodies[256];
            void set_texture(int id, texture _tex);
            // std::vector<int> tile_data;
            sprite_drawer drawer;
            void set_cell(vec2i _pos, int _id);
            void update();
    };
};
