#include "math.hpp"

namespace jleg{
    float min(float _a, float _b){
        if (_a < _b){
            return _a;
        }
        else{
            return _b;
        };
    };

    float abs(float value){
        if (value < 0){
            return -value;
        }
        else{
            return value;
        };
    };
};
