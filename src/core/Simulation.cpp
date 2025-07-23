#include "core/Simulation.hpp"
#include "core/Constants.hpp"
#include <iostream>

Simulation::Simulation()
{
    using namespace Constants;

    Body sun;
    sun.name = "Sol";
    sun.texture = &assetManager.getTexture("../assets/sprites/sun.png");
    sun.mass = SUN_MASS;
    sun.velocity = {0,0};
    sun.position = {0,0};
    sun.radius = 0.15; // radius is just for visuals and not accurate to reality

    Body earth;
    earth.name = "Terra";
    earth.texture = &assetManager.getTexture("../assets/sprites/earth.png");
    earth.mass = EARTH_MASS;
    earth.position = {AU, 0.0};
    earth.velocity = {0.0, 1.0};
    earth.radius = 0.07; // radius is just for visuals and not accurate to reality

    Body mars;
    mars.name = "Mars";
    mars.texture = &assetManager.getTexture("../assets/sprites/mars.png");
    mars.mass = MARS_MASS;
    mars.position = {AU * 1.524, 0.0};
    mars.velocity = {0.0, 0.810041};
    mars.radius = 0.06;

    bodies.push_back(sun);
    bodies.push_back(earth);
    bodies.push_back(mars);
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
