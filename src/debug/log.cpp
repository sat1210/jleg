#include "log.hpp"

namespace jleg{
    std::ofstream log_file("latest.log");
    void log(std::string line){
        std::cout << line << std::endl;
        log_file << line << std::endl;
    };
};
