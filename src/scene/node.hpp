#ifndef NODE_HPP
#define NODE_HPP

#include <vector>
#include "vec2.hpp"
#include "transform.hpp"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "glm/gtx/rotate_vector.hpp"
#include "glm/gtx/vector_angle.hpp"

namespace jleg{
    class node{
        public:
            node *parent = nullptr;
            std::vector<node*> children;
            jleg::vec2 position;
            jleg::vec2 transform;
            int id;
            node();
            jleg::vec2 get_pos();

            void set_pos(jleg::vec2 _vec2);
            void add_child(node *_node);
            virtual void process(float delta);
            virtual void physics_process(float delta);
            virtual void update();
            std::vector<node*> get_children();
            glm::mat4 get_local_model_matrix();
            glm::mat4 get_global_model_matrix();
    };
};

#endif
