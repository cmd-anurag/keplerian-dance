#pragma once
#include "math/Vector2D.hpp"
#include "graphics/OrbitTrail.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

// a celestial body
class Body {
    private:
        OrbitTrail trail;

    public:
        Vector2D position;
        Vector2D velocity;
        Vector2D acceleration;

        double mass;
        double visualRadius;
        double actualRadius;
        double semiMajorAxis;
        double orbitalPeriod; 
        double rotationalPeriod;// since calculating them in a 2d sim is meaningless , these values are hardcoded in earth hours and respresent sidereal day
        double escapeVelocity;
        double gravityAtSurface;
        int surfaceTemperature;
        int moonCount;

        std::string name;
        std::string description;
        std::string nicknames;

        sf::Texture* texture = nullptr;

        Body();
        Body(Vector2D Position, Vector2D Velocity, Vector2D Acceleration, double Mass, double Radius, std::string &Name, sf::Color Colour);

        // physics methods.
        void applyForce(const Vector2D &force);
        void resetAcceleration();
        Vector2D calculateGravitationalForce(const Body& other) const;
        
        // trails.
        const OrbitTrail& getTrail() const;
        OrbitTrail& getTrail() { return trail; }

        // collisions.
        bool isColliding(const Body &other) const;
        void handleCollision(Body &other);

        // utiliy.
        double kineticEnergy() const;
        double potentialEnergy(const Body& other) const;
        double angularMomentum(const Body& other) const;
        double calculateOrbitalPeriod(const Body& other) const;
        double calculateGravityAtSurface() const;
        double calculateEscapeVelocity() const;
        bool isInView(const sf::View &view) const;
};