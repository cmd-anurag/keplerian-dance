#pragma once
#include "math/Vector2D.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

// a celestial body
class Body {
    private:
        sf::VertexArray trail {sf::LineStrip};
        sf::Color color;

    public:
        Vector2D position;
        Vector2D velocity;
        Vector2D acceleration;
        double mass;
        double radius;
        
        std::string name;
        sf::CircleShape shape;

        Body();
        Body(Vector2D Position, Vector2D Velocity, Vector2D Acceleration, double Mass, double Radius, std::string &Name, sf::Color Colour);

        // physics methods.
        void updatePosition(double dt);
        void updateVelocity(double dt);
        void applyForce(const Vector2D &force);
        void resetAcceleration();
        Vector2D calculateGravitationalForce(const Body& other) const;

        // visual stuff.
        void updateShape();
        void render(sf::RenderWindow &window);
        void setColor(const sf::Color &color);

        // trails.
        void addVertexToTrail();
        void popVertexFromTrail();
        void renderTrail(sf::RenderWindow &window);

        // collisions.
        bool isColliding(const Body &other) const;
        void handleCollision(Body &other);

        // utiliy.
        double kineticEnergy() const;
        double potentialEnergy(const Body& other) const;
        bool isInView(const sf::View &view) const;
};