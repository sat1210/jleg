#ifndef TILEMAP_HPP
#define TILEMAP_HPP

#include <vector>
#include "node.hpp"
#include "texture.hpp"
#include "vec2.hpp"
#include "vec2i.hpp"
#include "sprite_drawer.hpp"
#include "physics.hpp"
#include "visuals.hpp"

namespace jleg{
    //https://en.wikipedia.org/wiki/Binary_space_partitioning
    //or only edges need collision, interior doesnt need collisions since no contact
    class tilemap : public node{ //add bsp and meshing for improved performance
        public:
            tilemap();
            tilemap(vec2 _position);
            vec2i size = vec2i(16, 16);
            // tileset tiles;
            //tile data is initialised with random numbers
            int tile_data[256];//upper left to bottom right
            std::vector<texture> textures;
            b2Body* tile_bodies[256];
            void set_texture(int id, texture _tex);
            sprite_drawer drawer; //set global renderer somewhere
            void set_cell(vec2i _pos, int _id);
            void update();
    };
};

#endif
