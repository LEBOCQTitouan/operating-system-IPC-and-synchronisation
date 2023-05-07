//
// Created by Titouan LEBOCQ on 03/05/2023.
//

#include "camera_supervisor.h"

void turn_camera(Parameters *p, int angle) {
    p->theta = angle;
}

void change_distance(Parameters *p, float distance) {
    p->distance = distance;
}

void turn_routine(routine_parameter_t p) {
    sem_t *sem = get_semaphore(MUTEX_NAME);
    while (1) {
        sem_wait(sem);
        turn_camera(p.p, p.p->theta+1);
        sem_post(sem);
        usleep(5000);
    }
}

void random_distance_routine(routine_parameter_t p) {
    // TODO but cant find correct values
}

void camera_routine(routine_parameter_t p) {
    create_child_process(turn_routine, p);
    create_child_process(random_distance_routine, p);
}

pid_t start_camera_supervisor(Parameters *p) {
    routine_parameter_t parameter = {0};
    parameter.p = p;
    return create_child_process(camera_routine, parameter);
}