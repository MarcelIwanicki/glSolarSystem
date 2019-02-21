#ifndef GLSOLARSYSTEM_CONSTANTS_H
#define GLSOLARSYSTEM_CONSTANTS_H

namespace Constants {

    constexpr float R_SCALE = 1.0f / 2000.0f;
    constexpr int R_SUN = 695508 * R_SCALE;
    constexpr int R_MERCURY = 2440 * R_SCALE;
    constexpr int R_VENUS = 6052 * R_SCALE;
    constexpr int R_EARTH = 6371 * R_SCALE;
    constexpr int R_MARS = 3390 * R_SCALE;
    constexpr int R_JUPITER = 69911 * R_SCALE;
    constexpr int R_SATURN = 58232 * R_SCALE;
    constexpr int R_URANUS = 25362 * R_SCALE;
    constexpr int R_NEPTUNE = 24622 * R_SCALE;

    constexpr float D_SCALE = 4.0f / 5.0f;
    constexpr int D_FROM_EARTH_SUN = -1000 * D_SCALE;
    constexpr int D_FROM_EARTH_MERCURY = -150 * D_SCALE;
    constexpr int D_FROM_EARTH_VENUS = -100 * D_SCALE;
    constexpr int D_FROM_EARTH_EARTH = 0 * D_SCALE;
    constexpr int D_FROM_EARTH_MARS = 100 * D_SCALE;
    constexpr int D_FROM_EARTH_JUPITER = 400 * D_SCALE;
    constexpr int D_FROM_EARTH_SATURN = 800 * D_SCALE;
    constexpr int D_FROM_EARTH_URANUS = 1200 * D_SCALE;
    constexpr int D_FROM_EARTH_NEPTUNE = 1450 * D_SCALE;

    constexpr float ORIGIN_X = D_FROM_EARTH_SUN;
    constexpr float ORIGIN_Z = -25.0f;

    constexpr int D_FROM_SUN_MERCURY = ORIGIN_X - D_FROM_EARTH_MERCURY;
    constexpr int D_FROM_SUN_VENUS = ORIGIN_X - D_FROM_EARTH_VENUS;
    constexpr int D_FROM_SUN_EARTH = ORIGIN_X - D_FROM_EARTH_EARTH;
    constexpr int D_FROM_SUN_MARS = ORIGIN_X - D_FROM_EARTH_MARS;
    constexpr int D_FROM_SUN_JUPITER = ORIGIN_X - D_FROM_EARTH_JUPITER;
    constexpr int D_FROM_SUN_SATURN = ORIGIN_X - D_FROM_EARTH_SATURN;
    constexpr int D_FROM_SUN_URANUS = ORIGIN_X - D_FROM_EARTH_URANUS;
    constexpr int D_FROM_SUN_NEPTUNE = ORIGIN_X - D_FROM_EARTH_NEPTUNE;

    constexpr float ORBITAL_SPEED_SCALE = 1e-6f;
    constexpr float ORBITAL_SPEED_MERCURY = 47.87f * ORBITAL_SPEED_SCALE;
    constexpr float ORBITAL_SPEED_VENUS = 35.02f * ORBITAL_SPEED_SCALE;
    constexpr float ORBITAL_SPEED_EARTH = 29.78f * ORBITAL_SPEED_SCALE;
    constexpr float ORBITAL_SPEED_MARS = 24.077f * ORBITAL_SPEED_SCALE;
    constexpr float ORBITAL_SPEED_JUPITER = 13.07f * ORBITAL_SPEED_SCALE;
    constexpr float ORBITAL_SPEED_SATURN = 9.69f * ORBITAL_SPEED_SCALE;
    constexpr float ORBITAL_SPEED_URANUS = 6.81f * ORBITAL_SPEED_SCALE;
    constexpr float ORBITAL_SPEED_NEPTUNE = 5.43f * ORBITAL_SPEED_SCALE;

    constexpr float ANGULAR_SPEED_SCALE = 100.0f;
    constexpr float ANGULAR_SPEED_SUN = -2.02 * 1e-6 * ANGULAR_SPEED_SCALE;
    constexpr float ANGULAR_SPEED_MERCURY = -1.24 * 1e-6 * ANGULAR_SPEED_SCALE;
    constexpr float ANGULAR_SPEED_VENUS = 1.64 * 1e-6 * ANGULAR_SPEED_SCALE;
    constexpr float ANGULAR_SPEED_EARTH = -7.29 * 1e-5 * ANGULAR_SPEED_SCALE;
    constexpr float ANGULAR_SPEED_MARS = -7.09 * 1e-5 * ANGULAR_SPEED_SCALE;
    constexpr float ANGULAR_SPEED_JUPITER = -1.77 * 1e-4 * ANGULAR_SPEED_SCALE;
    constexpr float ANGULAR_SPEED_SATURN = -1.64 * 1e-4 * ANGULAR_SPEED_SCALE;
    constexpr float ANGULAR_SPEED_URANUS = 1.04 * 1e-4 * ANGULAR_SPEED_SCALE;
    constexpr float ANGULAR_SPEED_NEPTUNE = -1.08 * 1e-4 * ANGULAR_SPEED_SCALE;
}

#endif //GLSOLARSYSTEM_CONSTANTS_H
