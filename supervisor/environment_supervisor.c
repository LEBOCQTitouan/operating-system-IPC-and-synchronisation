//
// Created by Titouan LEBOCQ on 03/05/2023.
//

#include "environment_supervisor.h"

void setup_environment(Parameters *p, enum planet planet) {
    switch (planet) {
        case EARTH:
            p->gravity = 9.81;
            p->color.r = 255;
            p->color.g = 255;
            p->color.b = 0;
            break;
        case MARS:
            p->gravity = 3.71;
            p->color.r = 0;
            p->color.g = 255;
            p->color.b = 0;
            break;
        case JUPYTER:
            p->gravity = 27.79;
            p->color.r = 0;
            p->color.g = 0;
            p->color.b = 255;
            break;
    }
}


Vector create_vector(float x, float y, float z) {
    Vector v = {x, y, z};
    return v;
}

void env_routine(routine_parameter_t p) {
    sem_t *sem = get_semaphore(MUTEX_NAME);
    srand(time(NULL));

    while (1) {
        sem_wait(sem);
        enum planet random_planet = rand() % 3;
        setup_environment(p.p, random_planet);
        Vector random_wind = create_vector(rand() % 10, rand() % 10, rand() % 10);
        p.p->forceOfWind = random_wind;
        sem_post(sem);
        sleep(5);
    }
}

pid_t start_environment_supervisor(Parameters *p) {
    routine_parameter_t parameter = {0};
    parameter.p = p;
    return create_child_process(env_routine, parameter);
}