//
// Created by Titouan LEBOCQ on 03/05/2023.
//

#include "camera_supervisor.h"

sem_t *sem_camera;

void camera_handler(int sig) {
    sem_close(sem_camera);
    exit(EXIT_SUCCESS);
}

void camera_routine(routine_parameter_t p) {
    struct sigaction sa = {0};
    sigemptyset(&sa.sa_mask);
    sa.sa_handler = camera_handler;
    if (sigaction(SIGALRM, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }
    sa.sa_flags = 0;

    while (1) {
        sem_wait(sem_camera);
        p.p->theta++;
        sem_post(sem_camera);
        usleep(5000);
    }
}

pid_t start_camera_supervisor(Parameters *p) {
    sem_camera = get_semaphore(MUTEX_NAME);
    routine_parameter_t parameter = {0};
    parameter.sem = sem_camera;
    parameter.p = p;
    return create_child_process(camera_routine, parameter);
}