#pragma once
#include <string>
#include <sstream>
#include <iomanip>
#include "core/Constants.hpp"

const double VELOCITY_RATIO = 29.78801315;
const double ACCL_RATIO = 0.00593008;

namespace Format
{
    inline std::string toRealDistance(double simDistance)
    {
        std::stringstream ss;
        ss << std::fixed << std::setprecision(0) << (simDistance * 1.496e8) << " km";
        return ss.str();
    }
    inline std::string toRealMass(double simMass)
    {
        std::stringstream ss;
        ss << std::scientific << std::setprecision(3) << (simMass * 1.989e30) << " kg";
        return ss.str();
    }
    inline std::string toRealTime(double simTime)
    {
        std::stringstream ss;
        double earthYears = simTime / (2 * M_PI);
        double earthDays = earthYears * 365.25;
        ss << std::fixed << std::setprecision(2) << earthDays << " earth days";
        return ss.str();
    }

    inline std::string toRealVelocity(double simVelocity)
    {
        std::stringstream ss;
        ss << std::fixed << std::setprecision(2) << (simVelocity * VELOCITY_RATIO) << " km/s";
        return ss.str();
    }

    inline std::string toRealAcceleration(double simAcceleration)
    {
        std::stringstream ss;
        ss << std::scientific << std::setprecision(3) << (simAcceleration * ACCL_RATIO) << " m/s/s";
        return ss.str();
    }
}