#include "node.hpp"

namespace jleg{
    node::node(){
        this->name = "Node";
    };

    void node::add_child(node *_node){
        std::cout << _node->name << std::endl;
        this->children.push_back(_node);
        _node->parent = this;
    };

    std::vector<node*> node::get_children(){
        return this->children;
    };

    node* node::get_parent(){
        return this->parent;
    };

    vec2 node::get_position(){
        return this->position;
    };

    void node::set_position(vec2 _vec2){
        this->position = _vec2;
    };

    void node::process(float delta){};
    void node::physics_process(float delta){};
    void node::update(){};

    glm::mat4 node::get_local_model_matrix(){
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(this->position.to_glm(), 0.0f));
        // model = glm::translate(model, glm::vec3(_sprite->tex.offset.to_glm(), 0.0f));
        // model = glm::scale(model, glm::vec3(_sprite->tex.size.to_glm(), 0.0f));
        return model;
    };

    glm::mat4 node::get_global_model_matrix(){
        glm::mat4 model = glm::mat4(1.0f);
        if (this->parent){
            model = this->parent->get_global_model_matrix() * this->get_local_model_matrix();
        }
        else {
            model = this->get_local_model_matrix();
        };
        return model;
    };
};
