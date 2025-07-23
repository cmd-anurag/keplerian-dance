#pragma once

namespace Constants {
    // --- SIMULATION UNITS ---
    // These are the units we will use for all physics calculations.

    constexpr double G = 1.0;

    constexpr double SUN_MASS = 1.0;

    constexpr double AU = 1.0;

    // --- TIME ---
    // How many simulation time units pass in one update step.
    // This value requires tuning to make the simulation stable and run at a decent speed.
    constexpr double TIMESTEP = 0.01;


    // Planet Specific Data

    // ------------------------------ Earth ------------------------------
    constexpr double EARTH_MASS = 3.0e-6;
    constexpr double EARTH_SEMI_MAJOR_AXIS = AU;
    constexpr double EARTH_ECCENTRICITY = 0.01671;

    // ------------------------------ Mercury ------------------------------
    constexpr double MERCURY_MASS = 0.055 * EARTH_MASS;
    constexpr double MERCURY_SEMI_MAJOR_AXIS = 0.387098 * AU;
    constexpr double MERCURY_ECCENTRICITY = 0.20563;

    // ------------------------------ Venus ------------------------------
    constexpr double VENUS_MASS = 0.815 * EARTH_MASS;
    constexpr double VENUS_SEMI_MAJOR_AXIS = 0.7233 * AU;
    constexpr double VENUS_ECCENTRICITY = 0.0068;

    // ------------------------------ Mars ------------------------------
    constexpr double MARS_MASS = 0.107 * EARTH_MASS;
    constexpr double MARS_SEMI_MAJOR_AXIS = 1.524 * AU;
    constexpr double MARS_ECCENTRICITY = 0.0935;

    // ------------------------------ Jupiter ------------------------------
    constexpr double JUPITER_MASS = 317.83 * EARTH_MASS;
    constexpr double JUPITER_SEMI_MAJOR_AXIS = 5.204 * AU;
    constexpr double JUPITER_ECCENTRICITY = 0.0483;

    // ------------------------------ Saturn ------------------------------
    constexpr double SATURN_MASS = 95.16 * EARTH_MASS;
    constexpr double SATURN_SEMI_MAJOR_AXIS = 9.573 * AU;
    constexpr double SATURN_ECCENTRICITY = 0.0565;

    // ------------------------------ URANUS ------------------------------
    constexpr double URANUS_MASS = 14.53 * EARTH_MASS;
    constexpr double URANUS_SEMI_MAJOR_AXIS = 19.19126 * AU;
    constexpr double URANUS_ECCENTRICITY = 0.04717;

    // ------------------------------ NEPTUNE ------------------------------
    constexpr double NEPTUNE_MASS = 17.15 * EARTH_MASS;
    constexpr double NEPTUNE_SEMI_MAJOR_AXIS = 30.178 * AU;
    constexpr double NEPTUNE_ECCENTRICITY = 0.00867;


    
    // i'll add the data for other planets later

}