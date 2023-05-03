//
// Created by Titouan LEBOCQ on 03/05/2023.
//

#ifndef OPERATING_SYSTEM_IPC_AND_SYNCHRONISATION_CAMERA_SUPERVISOR_H
#define OPERATING_SYSTEM_IPC_AND_SYNCHRONISATION_CAMERA_SUPERVISOR_H

#include <sys/types.h>
#include <sys/semaphore.h>
#include <signal.h>

#include "../util.h"
#include "../IPC/ipc.h"
#include "../process/handling.h"

pid_t start_camera_supervisor(Parameters *p);

#endif //OPERATING_SYSTEM_IPC_AND_SYNCHRONISATION_CAMERA_SUPERVISOR_H
