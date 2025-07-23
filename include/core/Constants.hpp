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

    // ------------------------------ Mercury ----------------------------
    constexpr double MERCURY_MASS = 0.055 * EARTH_MASS;

    // ------------------------------ Mars ------------------------------
    constexpr double MARS_MASS = 0.107 * EARTH_MASS;
    constexpr double MARS_SEMI_MAJOR_AXIS = 1.524;
    constexpr double MARS_ECCENTRICITY = 0.0935;
    
    // i'll add the data for other planets later

}