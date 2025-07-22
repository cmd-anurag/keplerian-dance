#pragma once
#include "math/Vector2D.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

// a celestial body
class Body {
    private:
        sf::VertexArray trail {sf::LineStrip};

    public:
        Vector2D position;
        Vector2D velocity;
        Vector2D acceleration;
        double mass;
        double radius;
        
        std::string name;
        sf::Color color;

        Body();
        Body(Vector2D Position, Vector2D Velocity, Vector2D Acceleration, double Mass, double Radius, std::string &Name, sf::Color Colour);

        // physics methods.
        void update(double dt);
        void applyForce(const Vector2D &force);
        void resetAcceleration();
        Vector2D calculateGravitationalForce(const Body& other) const;

        // trails.
        void addVertexToTrail();
        void popVertexFromTrail();
        const sf::VertexArray& getTrail() const;

        // collisions.
        bool isColliding(const Body &other) const;
        void handleCollision(Body &other);

        // utiliy.
        double kineticEnergy() const;
        double potentialEnergy(const Body& other) const;
        bool isInView(const sf::View &view) const;
};