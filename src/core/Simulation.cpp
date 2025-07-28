#include "core/Simulation.hpp"
#include "core/Constants.hpp"
#include "math/Utils.hpp"
#include <iostream>

Simulation::Simulation()
{
    using namespace Constants;

    // NOTE - Radii for each planets are for visual clarity only and do not reflect their true size, (it would be really hard to see)

    Body sun;
    sun.name = "Sol";
    sun.texture = &assetManager.getTexture("../assets/sprites/sun.png");
    sun.mass = SUN_MASS;
    sun.velocity = {0,0};
    sun.position = {0,0};
    sun.radius = 0.15;

    Body mercury;
    mercury.name = "Mercury";
    mercury.texture = &assetManager.getTexture("../assets/sprites/mercury.png");
    mercury.mass = MERCURY_MASS;
    auto [mercuryPosition, mercuryVelocity] = Utils::calculateOrbitalVelocity(MERCURY_SEMI_MAJOR_AXIS, MERCURY_ECCENTRICITY);
    mercury.position = mercuryPosition;
    mercury.velocity = -mercuryVelocity;
    mercury.radius = 0.04;

    Body venus;
    venus.name = "Venus";
    venus.texture = &assetManager.getTexture("../assets/sprites/venus.png");
    venus.mass = VENUS_MASS;
    auto [venusPosition, venusVelocity] = Utils::calculateOrbitalVelocity(VENUS_SEMI_MAJOR_AXIS, VENUS_ECCENTRICITY);
    venus.position = venusPosition;
    venus.velocity = -venusVelocity;
    venus.radius = 0.06;

    Body earth;
    earth.name = "Terra";
    earth.texture = &assetManager.getTexture("../assets/sprites/earth.png");
    earth.mass = EARTH_MASS;
    auto [earthPosition, earthVelocity] = Utils::calculateOrbitalVelocity(EARTH_SEMI_MAJOR_AXIS, EARTH_ECCENTRICITY);
    earth.position = earthPosition;
    earth.velocity = -earthVelocity;
    earth.radius = 0.07;

    Body mars;
    mars.name = "Mars";
    mars.texture = &assetManager.getTexture("../assets/sprites/mars.png");
    mars.mass = MARS_MASS;
    auto [marsPosition, marsVelocity] = Utils::calculateOrbitalVelocity(MARS_SEMI_MAJOR_AXIS, MARS_ECCENTRICITY);
    mars.position = marsPosition;
    mars.velocity = -marsVelocity;
    mars.radius = 0.06;

    Body jupiter;
    jupiter.name = "Jupiter";
    jupiter.texture = &assetManager.getTexture("../assets/sprites/jupiter.png");
    jupiter.mass = JUPITER_MASS;
    auto [jupiterPosition, jupiterVelocity] = Utils::calculateOrbitalVelocity(JUPITER_SEMI_MAJOR_AXIS, JUPITER_ECCENTRICITY);
    jupiter.position = jupiterPosition;
    jupiter.velocity = -jupiterVelocity;
    jupiter.radius = 0.3;

    Body saturn;
    saturn.name = "Saturn";
    saturn.texture = &assetManager.getTexture("../assets/sprites/saturn.png");
    saturn.mass = SATURN_MASS;
    auto [saturnPosition, saturnVelocity] = Utils::calculateOrbitalVelocity(SATURN_SEMI_MAJOR_AXIS, SATURN_ECCENTRICITY);
    saturn.position = saturnPosition;
    saturn.velocity = -saturnVelocity;
    saturn.radius = 0.6;

    Body uranus;
    uranus.name = "Uranus";
    uranus.texture = &assetManager.getTexture("../assets/sprites/uranus.png");
    uranus.mass = URANUS_MASS;
    auto [uranusPosition, uranusVelocity] = Utils::calculateOrbitalVelocity(URANUS_SEMI_MAJOR_AXIS, URANUS_ECCENTRICITY);
    uranus.position = uranusPosition;
    uranus.velocity = -uranusVelocity;
    uranus.radius = 0.4;

    Body neptune;
    neptune.name = "Neptune";
    neptune.texture = &assetManager.getTexture("../assets/sprites/neptune.png");
    neptune.mass = NEPTUNE_MASS;
    auto [neptunePosition, neptuneVelocity] = Utils::calculateOrbitalVelocity(NEPTUNE_SEMI_MAJOR_AXIS, NEPTUNE_ECCENTRICITY);
    neptune.position = neptunePosition;
    neptune.velocity = -neptuneVelocity;
    neptune.radius = 0.4;

    bodies.push_back(sun);
    bodies.push_back(mercury);
    bodies.push_back(venus);
    bodies.push_back(earth);
    bodies.push_back(mars);
    bodies.push_back(jupiter);
    bodies.push_back(saturn);
    bodies.push_back(uranus);
    bodies.push_back(neptune);
}

void Simulation::update(double dt)
{
    // --- Velocity Verlet Integration ---

    // Step 1: Update all body positions by a full step.
    // This uses the velocity and acceleration from the *previous* frame.
    for(auto &body : bodies) {
        body.position += body.velocity * dt + (body.acceleration * 0.5 * dt * dt);
    }

    // Step 2: Store the "old" accelerations before we recalculate them.
    std::vector<Vector2D> oldAccelerations;
    oldAccelerations.reserve(bodies.size());
    for(const auto &body : bodies) {
        oldAccelerations.push_back(body.acceleration);
    }

    // Step 3: Calculate forces at the NEW positions.
    // This updates each body's "acceleration" member to the new value.
    physicsEngine.calculateForces(bodies);

    // Step 4: Update all body velocities using the AVERAGE of the old and new accelerations.
    // This is the key step that makes the simulation stable.
    for(size_t i = 0; i < bodies.size(); ++i) {
        bodies[i].velocity += (oldAccelerations[i] + bodies[i].acceleration) * 0.5 * dt;
    }

    
    // for(auto &body : bodies) {
    //     body.getTrail().addVertex(body.position);
    // }
}

const std::vector<Body>& Simulation::getBodies() const {
    return bodies;
}

std::vector<Body>& Simulation::getNonConstBodies() {
    return bodies;
}