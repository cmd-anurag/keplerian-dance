#pragma once

namespace Constants {
    // --- SIMULATION UNITS ---
    // These are the units we will use for all physics calculations.

    constexpr double G = 1.0;

    constexpr double SUN_MASS = 1.0;

    constexpr double EARTH_MASS = 3.0e-6; // (Actual is ~1/333,000)
    constexpr double MARS_MASS = 0.107 * EARTH_MASS;

    constexpr double AU = 1.0;

    // --- TIME ---
    // How many simulation time units pass in one update step.
    // This value requires tuning to make the simulation stable and run at a decent speed.
    constexpr double TIMESTEP = 0.01;
}