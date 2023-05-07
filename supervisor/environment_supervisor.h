//
// Created by Titouan LEBOCQ on 03/05/2023.
//

#ifndef OPERATING_SYSTEM_IPC_AND_SYNCHRONISATION_ENVIRONMENT_SUPERVISOR_H
#define OPERATING_SYSTEM_IPC_AND_SYNCHRONISATION_ENVIRONMENT_SUPERVISOR_H

#include <sys/types.h>
#include <sys/semaphore.h>
#include <signal.h>
#include <time.h>

#include "../util.h"
#include "../IPC/ipc.h"
#include "../process/handling.h"

enum planet {
    EARTH,
    MARS,
    JUPYTER
};

Vector create_vector(float x, float y, float z);

void setup_environment(Parameters *p, enum planet planet);

pid_t start_environment_supervisor(Parameters *p);

#endif //OPERATING_SYSTEM_IPC_AND_SYNCHRONISATION_ENVIRONMENT_SUPERVISOR_H
