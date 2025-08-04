#pragma once
#include<utility>
#include "math/Vector2D.hpp"
#include "core/Constants.hpp"

// this is a somewhat temporary way of doing it, i'll refactor it later

namespace Utils {
    // this returns the orbital velocity of the planet at the perihilion assuming the central mass is at 0,0 and perihelion lies along the +x axis
    inline std::pair<Vector2D, Vector2D> calculateOrbitalVelocity(double a, double e)
    {
        // perihelion (closest approach)
        double r = a * (1 - e);
        // orbital velocity at r
        double v = sqrt(Constants::G * Constants::SUN_MASS * (2 / r - 1 / a));

        return {
            {r, 0.0},
            {0.0, v}
        };
    }
}