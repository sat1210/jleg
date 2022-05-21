#ifndef LOG_HPP
#define LOG_HPP

#include <fstream>
#include <string>
#include <iostream>


namespace jleg{
    extern std::ofstream log_file;
    void log(std::string line);
};

#endif
