#include "core/Simulation.hpp"
#include "core/Constants.hpp"
#include <iostream>

Simulation::Simulation()
{
    using namespace Constants;

    Body sun;
    sun.color = sf::Color::Yellow;
    sun.mass = SUN_MASS;
    sun.velocity = {0,0};
    sun.position = {0,0};
    sun.radius = 0.15; // radius is just for visuals and not accurate to reality

    Body earth;
    earth.color = sf::Color::Blue;
    earth.mass = EARTH_MASS;
    earth.position = {AU, 0.0};
    earth.velocity = {0.0, 1.0};
    earth.radius = 0.07; // radius is just for visuals and not accurate to reality

    bodies.push_back(sun);
    bodies.push_back(earth);
}

void Simulation::update(double dt)
{
    physicsEngine.calculateForces(bodies);

    for(auto &body : bodies) {
        body.update(dt);
        // std::cout << "Body position: " << body.position.x << ", " << body.position.y << std::endl;
    }
}

const std::vector<Body>& Simulation::getBodies() const {
    return bodies;
}