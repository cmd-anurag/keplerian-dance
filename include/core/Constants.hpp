#pragma once

// these constants are "trust me bro" so revisions are required

constexpr double G = 1.0f;      // the universal gravitational constant

constexpr double EARTH_MASS = 1.0f;     // earth's mass taken as 1
constexpr double SUN_MASS = 333000.0f;  // sun's mass relative to earth's mass

constexpr double WORLD_UNIT_KM = 1e6;   // 1 world unit = 1 million kms
constexpr double WORLD_UNIT_TO_PIXELS = 100.0f; // 1 world unit = 100 pixels on screen

constexpr double SECONDS_PER_STEP = 86400.0f; // 1 step in sim equals a day in real life

constexpr double AU = 149.6f; // 1 AU , distance from sun to earth.