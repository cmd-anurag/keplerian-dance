#pragma once
#include <vector>
#include "core/Body.hpp"
#include "core/Physics.hpp"

class Simulation {
    public:
        Simulation();

        void update(double dt);
        
        const std::vector<Body>& getBodies() const;

    private:
        std::vector<Body> bodies;
        Physics physicsEngine;
};