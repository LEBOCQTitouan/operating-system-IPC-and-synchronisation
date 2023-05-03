//
// Created by Titouan LEBOCQ on 03/05/2023.
//

#include "handling.h"

pid_t create_child_process(routine_t r, routine_parameter_t parameter) {
    pid_t pid;

    if ((pid = fork()) < 0) {
        perror("fork() error");
        exit(EXIT_FAILURE);
    }
    if (pid == 0) { // starting child env_routine
        r(parameter);
        exit(EXIT_SUCCESS);
    }

    return pid;
}