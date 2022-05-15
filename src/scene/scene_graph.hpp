#ifndef SCENE_GRAPH_HPP
#define SCENE_GRAPH_HPP

#include "node.hpp"

namespace jleg{
    class scene_graph{
        public:
            node* root_node;
            node* get_root_node();
    };
};

#endif
