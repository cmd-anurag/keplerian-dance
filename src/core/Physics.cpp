#include "core/Physics.hpp"
#include <cmath>


void Physics::calculateForces(std::vector<Body> &bodies)
{

    for(auto& body : bodies)
    {
        body.resetAcceleration();
    }

    for(int i = 0; i < bodies.size(); ++i)
    {
        for(int j = i+1; j < bodies.size(); ++j)
        {
            auto &body1 = bodies.at(i);
            auto &body2 = bodies.at(j);

            Vector2D force = body1.calculateGravitationalForce(body2);

            body1.applyForce(force);
            body2.applyForce(force * -1);
        }
    }

}