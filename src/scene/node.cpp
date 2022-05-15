#include "node.hpp"

jleg::node::node(){
    // do nothing
};

void jleg::node::add_child(node *_node){
    this->children.push_back(_node);
    _node->parent = this;
};

std::vector<jleg::node*> jleg::node::get_children(){
    return this->children;
};

jleg::vec2 jleg::node::get_pos(){
    return this->position;
};

void jleg::node::set_pos(jleg::vec2 _vec2){
    this->position = _vec2;
};

void jleg::node::process(float delta){};
void jleg::node::physics_process(float delta){};
void jleg::node::update(){};
// bool jleg::node::renderable(){
//     return false;
// };
