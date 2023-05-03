//
// Created by Titouan LEBOCQ on 03/05/2023.
//

#include "environment_supervisor.h"

sem_t *sem_environment;
Parameters *p_env;

void environment_handler(int sig) {
    sem_wait(sem_environment);
    printf("Setup earth\n");
    p_env->gravity = 9.81;
    p_env->color.r = 255;
    p_env->color.g = 255;
    p_env->color.b = 0;
    sem_post(sem_environment);
    sem_close(sem_environment);
    exit(EXIT_SUCCESS);
}

void env_routine(routine_parameter_t p) {
    struct sigaction sa = {0};
    sigemptyset(&sa.sa_mask);
    sa.sa_handler = environment_handler;
    if (sigaction(SIGALRM, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }
    sa.sa_flags = 0;

    p_env = p.p;

    // setup earth
    sem_wait(sem_environment);
    printf("Setup earth\n");
    // p.p->gravity = 9.81;
    p.p->gravity = 10;
    p.p->color.r = 255;
    p.p->color.g = 255;
    p.p->color.b = 0;
    sem_post(sem_environment);
    sleep(10);
    // setup mars
    sem_wait(sem_environment);
    printf("Setup mars\n");
    // p.p->gravity = 3.71;
    p.p->gravity = 4;
    p.p->color.r = 0;
    p.p->color.g = 255;
    p.p->color.b = 0;
    sem_post(sem_environment);
    sleep(10);
    // setup jupyter
    sem_wait(sem_environment);
    printf("Setup jupyter\n");
    // p.p->gravity = 27.79;
    p.p->gravity = 28;
    p.p->color.r = 0;
    p.p->color.g = 0;
    p.p->color.b = 255;
    sem_post(sem_environment);
    sleep(10);
}

pid_t start_environment_supervisor(Parameters *p) {
    sem_environment = get_semaphore(MUTEX_NAME);
    routine_parameter_t parameter = {0};
    parameter.sem = sem_environment;
    parameter.p = p;
    return create_child_process(env_routine, parameter);
}