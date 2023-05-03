//
// Created by Titouan LEBOCQ on 03/05/2023.
//

#ifndef OPERATING_SYSTEM_IPC_AND_SYNCHRONISATION_UTIL_H
#define OPERATING_SYSTEM_IPC_AND_SYNCHRONISATION_UTIL_H

#define PARAM_PATH      "/calembredaine"
#define MUTEX_NAME      "/vent-sem_environment"
#define NB_PARTICLES    1000
#define PI              3.14159

#define DISTANCE_INIT   4.0
#define DISTANCE_MAX    15
#define PARTICLE_MASS   1
#define DELTA_T         0.01

#define NO_WIND         0.0
#define SMALL_WIND      0.4
#define MEDIUM_WIND     1.5
#define STRONG_WIND     2.5

typedef struct {
    float x;
    float y;
    float z;
} Vector;

typedef struct {
    int r;
    int g;
    int b;
} Color;

typedef struct {
    Vector position;
    Vector velocity;
    Vector sumOfForces;       /**< sum of all forces applied on the particle */
} Particle;

/**
* @brief Parameters to control the windy fountain interface. */
typedef struct parameters_t {
    float gravity;            /**< 9.81 m/s^2 on Earth */
    float mass;               /**< mass of particles */
    Vector forceOfWind;       /**< force of the wind */
    float distance;           /**< distance from the camera to the fountain */
    int theta;
    int phi;
    Color color;
    Particle listOfParticles[NB_PARTICLES];
} Parameters;

#endif //OPERATING_SYSTEM_IPC_AND_SYNCHRONISATION_UTIL_H
