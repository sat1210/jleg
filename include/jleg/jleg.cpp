#include "jleg.hpp"
#include "nlohmann/json.hpp"

namespace jleg{
    int screen_width;
    int screen_height;
    float screen_scale;
    std::string game_name;

    void init(){
        std::cout << "Jleg Engine work in progress build" << std::endl;

        std::ifstream config_file("res/configs/config.json");
        nlohmann::json config_json;
        config_file >> config_json;

        screen_width = config_json["screen_width"];
        screen_height = config_json["screen_height"];
        screen_scale = config_json["screen_scale"];
        game_name = config_json["game_name"];

        jleg::create_window();
    };
};
