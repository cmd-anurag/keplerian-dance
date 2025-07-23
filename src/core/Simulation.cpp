#include "core/Simulation.hpp"
#include "core/Constants.hpp"
#include "math/Utils.hpp"
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
    auto [earthPosition, earthVelocity] = Utils::calculateOrbitalVelocity(EARTH_SEMI_MAJOR_AXIS, EARTH_ECCENTRICITY);
    earth.position = earthPosition;
    earth.velocity = -earthVelocity;
    earth.radius = 0.07; // radius is just for visuals and not accurate to reality

    Body mars;
    mars.name = "Mars";
    mars.texture = &assetManager.getTexture("../assets/sprites/mars.png");
    mars.mass = MARS_MASS;
    auto [marsPosition, marsVelocity] = Utils::calculateOrbitalVelocity(MARS_SEMI_MAJOR_AXIS, MARS_ECCENTRICITY);
    mars.position = marsPosition;
    mars.velocity = -marsVelocity;
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