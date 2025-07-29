#include "core/Simulation.hpp"
#include "core/Constants.hpp"
#include "math/Utils.hpp"
#include <iostream>

Simulation::Simulation()
{
    using namespace Constants;

    // NOTE - Radii for each planets are for visual clarity only and do not reflect their true size, (it would be really hard to see)

    Body sun;
    sun.name = "Sun";
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
    mercury.getTrail().setMinDistance(MERCURY_SEMI_MAJOR_AXIS * 0.01f);

    Body venus;
    venus.name = "Venus";
    venus.texture = &assetManager.getTexture("../assets/sprites/venus.png");
    venus.mass = VENUS_MASS;
    auto [venusPosition, venusVelocity] = Utils::calculateOrbitalVelocity(VENUS_SEMI_MAJOR_AXIS, VENUS_ECCENTRICITY);
    venus.position = venusPosition;
    venus.velocity = -venusVelocity;
    venus.radius = 0.06;
    venus.getTrail().setMinDistance(VENUS_SEMI_MAJOR_AXIS * 0.01f);

    Body earth;
    earth.name = "Earth";
    earth.texture = &assetManager.getTexture("../assets/sprites/earth.png");
    earth.mass = EARTH_MASS;
    auto [earthPosition, earthVelocity] = Utils::calculateOrbitalVelocity(EARTH_SEMI_MAJOR_AXIS, EARTH_ECCENTRICITY);
    earth.position = earthPosition;
    earth.velocity = -earthVelocity;
    earth.radius = 0.07;
    earth.getTrail().setMinDistance(EARTH_SEMI_MAJOR_AXIS * 0.01f);

    Body mars;
    mars.name = "Mars";
    mars.texture = &assetManager.getTexture("../assets/sprites/mars.png");
    mars.mass = MARS_MASS;
    auto [marsPosition, marsVelocity] = Utils::calculateOrbitalVelocity(MARS_SEMI_MAJOR_AXIS, MARS_ECCENTRICITY);
    mars.position = marsPosition;
    mars.velocity = -marsVelocity;
    mars.radius = 0.06;
    mars.getTrail().setMinDistance(MARS_SEMI_MAJOR_AXIS * 0.01f);

    Body jupiter;
    jupiter.name = "Jupiter";
    jupiter.texture = &assetManager.getTexture("../assets/sprites/jupiter.png");
    jupiter.mass = JUPITER_MASS;
    auto [jupiterPosition, jupiterVelocity] = Utils::calculateOrbitalVelocity(JUPITER_SEMI_MAJOR_AXIS, JUPITER_ECCENTRICITY);
    jupiter.position = jupiterPosition;
    jupiter.velocity = -jupiterVelocity;
    jupiter.radius = 0.3;
    jupiter.getTrail().setMinDistance(JUPITER_SEMI_MAJOR_AXIS * 0.01f);

    Body saturn;
    saturn.name = "Saturn";
    saturn.texture = &assetManager.getTexture("../assets/sprites/saturn.png");
    saturn.mass = SATURN_MASS;
    auto [saturnPosition, saturnVelocity] = Utils::calculateOrbitalVelocity(SATURN_SEMI_MAJOR_AXIS, SATURN_ECCENTRICITY);
    saturn.position = saturnPosition;
    saturn.velocity = -saturnVelocity;
    saturn.radius = 0.6;
    saturn.getTrail().setMinDistance(SATURN_SEMI_MAJOR_AXIS * 0.01f);

    Body uranus;
    uranus.name = "Uranus";
    uranus.texture = &assetManager.getTexture("../assets/sprites/uranus.png");
    uranus.mass = URANUS_MASS;
    auto [uranusPosition, uranusVelocity] = Utils::calculateOrbitalVelocity(URANUS_SEMI_MAJOR_AXIS, URANUS_ECCENTRICITY);
    uranus.position = uranusPosition;
    uranus.velocity = -uranusVelocity;
    uranus.radius = 0.4;
    uranus.getTrail().setMinDistance(URANUS_SEMI_MAJOR_AXIS * 0.01f);

    Body neptune;
    neptune.name = "Neptune";
    neptune.texture = &assetManager.getTexture("../assets/sprites/neptune.png");
    neptune.mass = NEPTUNE_MASS;
    auto [neptunePosition, neptuneVelocity] = Utils::calculateOrbitalVelocity(NEPTUNE_SEMI_MAJOR_AXIS, NEPTUNE_ECCENTRICITY);
    neptune.position = neptunePosition;
    neptune.velocity = -neptuneVelocity;
    neptune.radius = 0.4;
    neptune.getTrail().setMinDistance(NEPTUNE_SEMI_MAJOR_AXIS * 0.01f);

    // there is a slight problem, since i initialize the sun with 0 velocity and all planets at their perihilion with tangential 
    // "upward" velocity , this causes the system to have a non zero momentum in -y direction at start. This results in the sun 
    // itself drifting "upwards"
    // to fix it, i'm adding a counter velocity in the opposite direction such that the net momentum of the system is 0.

    Vector2D totalMomentum = Vector2D::getZeroVector();
    totalMomentum += mercury.velocity * mercury.mass;
    totalMomentum += venus.velocity * venus.mass;
    totalMomentum += earth.velocity * earth.mass;
    totalMomentum += mars.velocity * mars.mass;
    totalMomentum += jupiter.velocity * jupiter.mass;
    totalMomentum += saturn.velocity * saturn.mass;
    totalMomentum += uranus.velocity * uranus.mass;
    totalMomentum += neptune.velocity * neptune.mass;

    Vector2D sunInitialVelocity = -totalMomentum / SUN_MASS;
    sun.velocity = sunInitialVelocity;

    // fixed

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

    for(auto &body : bodies) {
        body.position += body.velocity * dt + (body.acceleration * 0.5 * dt * dt);
    }
    std::vector<Vector2D> oldAccelerations;
    oldAccelerations.reserve(bodies.size());
    for(const auto &body : bodies) {
        oldAccelerations.push_back(body.acceleration);
    }
    physicsEngine.calculateForces(bodies);
    for(size_t i = 0; i < bodies.size(); ++i) {
        bodies[i].velocity += (oldAccelerations[i] + bodies[i].acceleration) * 0.5 * dt;
    }

    for(auto &body : bodies) {
        body.getTrail().addVertex(body.position);
    }
}

const std::vector<Body>& Simulation::getBodies() const {
    return bodies;
}
std::vector<Body>& Simulation::getBodies() {
    return bodies;
}