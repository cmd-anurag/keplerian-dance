#include "core/Simulation.hpp"
#include "core/Constants.hpp"
#include "math/Utils.hpp"
#include <iostream>

Simulation::Simulation()
{
    using namespace Constants;

    Body sun;
    sun.name = "Sun";
    sun.description = "The blazing heart of the solar system.\nIts immense gravity binds every orbiting body,\nand its energy fuels the rhythms of planets and life.\nA sphere of fusion, burning for billions of years.";
    sun.texture = &assetManager.getTexture("../assets/sprites/sun.png");
    sun.mass = SUN_MASS;
    sun.velocity = {0,0};
    sun.position = {0,0};
    sun.visualRadius = 0.15;
    sun.actualRadius = SUN_RADIUS;
    sun.rotationalPeriod = 587;

    Body mercury;
    mercury.name = "Mercury";
    mercury.description = "The swiftest and innermost planet.\nIts surface scorched by daylight and frozen in night.\nWith no atmosphere to soften its extremes,\nit stands as a silent, cratered relic of the early solar system.";
    mercury.texture = &assetManager.getTexture("../assets/sprites/mercury.png");
    mercury.mass = MERCURY_MASS;
    auto [mercuryPosition, mercuryVelocity] = Utils::calculateOrbitalVelocity(MERCURY_SEMI_MAJOR_AXIS, MERCURY_ECCENTRICITY);
    mercury.position = mercuryPosition;
    mercury.velocity = -mercuryVelocity;
    mercury.actualRadius = MERCURY_RADIUS;
    mercury.visualRadius = 0.04;
    mercury.semiMajorAxis = MERCURY_SEMI_MAJOR_AXIS;
    mercury.getTrail().setMinDistance(mercury.semiMajorAxis * 0.01f);
    mercury.rotationalPeriod = 1407.5;

    Body venus;
    venus.name = "Venus";
    venus.description = "A world drowned in golden haze, where sunlight\nmelts into a sky of acid and storm.\nIts surface, a pressure-cooked wasteland of volcanic plains,\nremains hidden beneath clouds that never break.";
    venus.texture = &assetManager.getTexture("../assets/sprites/venus.png");
    venus.mass = VENUS_MASS;
    auto [venusPosition, venusVelocity] = Utils::calculateOrbitalVelocity(VENUS_SEMI_MAJOR_AXIS, VENUS_ECCENTRICITY);
    venus.position = venusPosition;
    venus.velocity = -venusVelocity;
    venus.actualRadius = VENUS_RADIUS;
    venus.visualRadius = 0.06;
    venus.semiMajorAxis = VENUS_SEMI_MAJOR_AXIS;
    venus.getTrail().setMinDistance(VENUS_SEMI_MAJOR_AXIS * 0.01f);
    venus.rotationalPeriod = -5832.5; // a negative sign means retrograde rotation

    Body earth;
    earth.name = "Earth";
    earth.description = "The only known world with life, oceans, and oxygen.\nA delicate balance of atmosphere and water makes Earth a rare\noasis in a vast, empty cosmos.\nIt's our home, and so far, the only one we've got.";
    earth.texture = &assetManager.getTexture("../assets/sprites/earth.png");
    earth.mass = EARTH_MASS;
    auto [earthPosition, earthVelocity] = Utils::calculateOrbitalVelocity(EARTH_SEMI_MAJOR_AXIS, EARTH_ECCENTRICITY);
    earth.position = earthPosition;
    earth.velocity = -earthVelocity;
    earth.actualRadius = EARTH_RADIUS;
    earth.visualRadius = 0.07;
    earth.semiMajorAxis = EARTH_SEMI_MAJOR_AXIS;
    earth.getTrail().setMinDistance(EARTH_SEMI_MAJOR_AXIS * 0.01f);
    earth.rotationalPeriod = 24;

    Body mars;
    mars.name = "Mars";
    mars.description = "A dry and barren world, its surface etched\nby canyons deeper than any on Earth.\nThin air and bitter cold blanket its rusted sands, where\nrovers now chase the whispers of lost water.";
    mars.texture = &assetManager.getTexture("../assets/sprites/mars.png");
    mars.mass = MARS_MASS;
    auto [marsPosition, marsVelocity] = Utils::calculateOrbitalVelocity(MARS_SEMI_MAJOR_AXIS, MARS_ECCENTRICITY);
    mars.position = marsPosition;
    mars.velocity = -marsVelocity;
    mars.actualRadius = MARS_RADIUS;
    mars.visualRadius = 0.06;
    mars.semiMajorAxis = MARS_SEMI_MAJOR_AXIS;
    mars.getTrail().setMinDistance(MARS_SEMI_MAJOR_AXIS * 0.01f);
    mars.rotationalPeriod = 24.6;

    Body jupiter;
    jupiter.name = "Jupiter";
    jupiter.description = "The largest planet and the colossal guardian of the solar system,\nso vast it bends the paths of comets and light.\nIts storms could swallow worlds whole,\nand its presence holds moons like a miniature solar system.";
    jupiter.texture = &assetManager.getTexture("../assets/sprites/jupiter.png");
    jupiter.mass = JUPITER_MASS;
    auto [jupiterPosition, jupiterVelocity] = Utils::calculateOrbitalVelocity(JUPITER_SEMI_MAJOR_AXIS, JUPITER_ECCENTRICITY);
    jupiter.position = jupiterPosition;
    jupiter.velocity = -jupiterVelocity;
    jupiter.actualRadius = JUPITER_RADIUS;
    jupiter.visualRadius = 0.3;
    jupiter.semiMajorAxis = JUPITER_SEMI_MAJOR_AXIS;
    jupiter.getTrail().setMinDistance(JUPITER_SEMI_MAJOR_AXIS * 0.01f);
    jupiter.rotationalPeriod = 9.9;

    Body saturn;
    saturn.name = "Saturn";
    saturn.description = "Wrapped in icy rings stretching far beyond the planet,\nthis gas giant hides a core deep beneath its haze.\nWinds roar faster than sound through its golden atmosphere,\nwhile dozens of moons orbit in complex, shifting patterns.";
    saturn.texture = &assetManager.getTexture("../assets/sprites/saturn.png");
    saturn.mass = SATURN_MASS;
    auto [saturnPosition, saturnVelocity] = Utils::calculateOrbitalVelocity(SATURN_SEMI_MAJOR_AXIS, SATURN_ECCENTRICITY);
    saturn.position = saturnPosition;
    saturn.velocity = -saturnVelocity;
    saturn.actualRadius = SATURN_RADIUS;
    saturn.visualRadius = 0.6;
    saturn.semiMajorAxis = SATURN_SEMI_MAJOR_AXIS;
    saturn.getTrail().setMinDistance(SATURN_SEMI_MAJOR_AXIS * 0.01f);
    saturn.rotationalPeriod = 10.7;

    Body uranus;
    uranus.name = "Uranus";
    uranus.description = "Tilted on its side with poles facing the Sun,\nit rolls through space in quiet defiance.\nIts pale blue clouds hide an icy core,\nand faint rings circle a world few have truly seen.";
    uranus.texture = &assetManager.getTexture("../assets/sprites/uranus.png");
    uranus.mass = URANUS_MASS;
    auto [uranusPosition, uranusVelocity] = Utils::calculateOrbitalVelocity(URANUS_SEMI_MAJOR_AXIS, URANUS_ECCENTRICITY);
    uranus.position = uranusPosition;
    uranus.velocity = -uranusVelocity;
    uranus.actualRadius = URANUS_RADIUS;
    uranus.visualRadius = 0.4;
    uranus.semiMajorAxis = URANUS_SEMI_MAJOR_AXIS;
    uranus.getTrail().setMinDistance(URANUS_SEMI_MAJOR_AXIS * 0.01f);
    uranus.rotationalPeriod = -17.2;

    Body neptune;
    neptune.name = "Neptune";
    neptune.description = "Far beyond the warmth of the Sun it circles,\na deep blue world lashed by supersonic winds, and a faint \nglow that hints at heat from within its core.\nSince its discovery in 1846, it has completed only one orbit around the sun";
    neptune.texture = &assetManager.getTexture("../assets/sprites/neptune.png");
    neptune.mass = NEPTUNE_MASS;
    auto [neptunePosition, neptuneVelocity] = Utils::calculateOrbitalVelocity(NEPTUNE_SEMI_MAJOR_AXIS, NEPTUNE_ECCENTRICITY);
    neptune.position = neptunePosition;
    neptune.velocity = -neptuneVelocity;
    neptune.actualRadius = NEPTUNE_RADIUS;
    neptune.visualRadius = 0.4;
    neptune.semiMajorAxis = NEPTUNE_SEMI_MAJOR_AXIS;
    neptune.getTrail().setMinDistance(NEPTUNE_SEMI_MAJOR_AXIS * 0.01f);
    neptune.rotationalPeriod = 16.1;

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