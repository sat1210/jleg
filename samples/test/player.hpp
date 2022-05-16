#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "jleg/jleg.hpp"

namespace game{
    class player : public jleg::character_body{
        public:
            player();
            player(jleg::vec2 _position, jleg::vec2 _size);
            void physics_process(float delta);
            jleg::vec2 vel;
            float damp = 0.8f;
            // void update();
        private:
            bool first_jump = false;
    };
};

#endif
