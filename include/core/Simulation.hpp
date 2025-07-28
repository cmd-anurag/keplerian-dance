#pragma once
#include <vector>
#include "core/Body.hpp"
#include "core/Physics.hpp"
#include "graphics/AssetManager.hpp"

class Simulation {
    public:
        Simulation();

        void update(double dt);
        
        const std::vector<Body>& getBodies() const;
        std::vector<Body>& getNonConstBodies();

    private:
        std::vector<Body> bodies;
        Physics physicsEngine;
        AssetManager assetManager;
};