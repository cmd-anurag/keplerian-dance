#include "core/Body.hpp"
#include "core/Constants.hpp"

Body::Body()
{
    position = Vector2D::getZeroVector();
    velocity = Vector2D::getZeroVector();
    acceleration = Vector2D::getZeroVector();
    mass = 1;
    radius = 1;
    name = "Default Body";
}

Body::Body(Vector2D Position, Vector2D Velocity, Vector2D Acceleration, double Mass, double Radius, std::string &Name, sf::Color Colour)
{
    position = Position;
    velocity = Velocity;
    acceleration = Acceleration;
    mass = Mass;
    radius = Radius;
    name = Name;
}

void Body::applyForce(const Vector2D &force)
{
    acceleration += force / mass;
}

void Body::resetAcceleration()
{
    acceleration = {0,0};
}

// it calculate the force on THIS body due to the OTHER body ie force which OTHER body exerts on THIS body
Vector2D Body::calculateGravitationalForce(const Body &other) const
{
    double squaredDistance = Vector2D::getSquaredDistanceBetween(position, other.position);
    squaredDistance = std::max(0.01, squaredDistance);
    double forceMagnitude = (Constants::G * mass * other.mass) / (squaredDistance);
    Vector2D forceDirection = (other.position - position).normalized();

    return forceDirection * forceMagnitude;
}



const OrbitTrail& Body::getTrail() const
{
    return trail;
}

bool Body::isColliding(const Body &other) const
{
    double squaredDistance = Vector2D::getSquaredDistanceBetween(position, other.position);
    double radiusSum = radius + other.radius;
    
    return squaredDistance < radiusSum * radiusSum;
}

void Body::handleCollision(Body &other)
{
    // do nothing for now, will be implemented later
}

double Body::kineticEnergy() const
{
    return 0.5 * mass * velocity.magnitudeSquared();
}

double Body::potentialEnergy(const Body& other) const
{
    double distance = (position - other.position).magnitude();
    if(distance == 0) return 0.0;

    return -Constants::G * mass * other.mass / distance;
}

double Body::angularMomentum(const Body &other) const
{
    Vector2D r = position - other.position;
    double L = -mass * r.crossProduct(velocity);
    return L;
}
bool Body::isInView(const sf::View &view) const
{
    sf::Vector2f center = view.getCenter();
    sf::Vector2f size = view.getSize();

    float left  = center.x - size.x / 2.0f;
    float right = center.x + size.x / 2.0f;
    float up    = center.y - size.y / 2.0f;
    float down  = center.y + size.y / 2.0f;

    float x = static_cast<float>(position.x);
    float y = static_cast<float>(position.y);
    float r = static_cast<float>(radius);

    return (x + r > left) && (x - r < right) && (y + r > up) && (y - r < down);
}