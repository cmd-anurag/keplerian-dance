#pragma once
#include <vector>
#include "core/Body.hpp"

class Physics {
    public:
        void calculateForces(std::vector<Body> &bodies);
};

