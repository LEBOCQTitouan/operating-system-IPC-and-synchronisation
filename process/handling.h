//
// Created by Titouan LEBOCQ on 03/05/2023.
//

#ifndef OPERATING_SYSTEM_IPC_AND_SYNCHRONISATION_HANDLING_H
#define OPERATING_SYSTEM_IPC_AND_SYNCHRONISATION_HANDLING_H

#include <sys/types.h>
#include <sys/semaphore.h>
#include "../IPC/ipc.h"
#include "../util.h"

typedef struct {
    Parameters *p;
    sem_t *sem;
}routine_parameter_t;

/**
 * Define a function called by a child process.
 */
typedef void (*routine_t)(routine_parameter_t);

/**
 * Util func used to create child processes
 * @param r the child env_routine
 * @param sem the semaphore used for accessing the shared memory
 * @param sm the shared memory
 * @return the pid of the created process
 */
pid_t create_child_process(routine_t r, routine_parameter_t parameter);

#endif //OPERATING_SYSTEM_IPC_AND_SYNCHRONISATION_HANDLING_H
