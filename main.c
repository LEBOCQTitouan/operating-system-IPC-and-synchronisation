#include <stdio.h>
#include <signal.h>
#include "IPC/ipc.h"
#include "util.h"
#include "supervisor/camera_supervisor.h"
#include "supervisor/environment_supervisor.h"

int main() {
    shared_memory sm;
    sm = get_shared_memory_segment(PARAM_PATH, sizeof(Parameters));

    sem_t *sem = get_semaphore(MUTEX_NAME);
    sem_post(sem); // initialize semaphore for this manager

    Parameters *p = (Parameters*)sm.mem_ptr;
    pid_t camera = start_camera_supervisor(p);
    pid_t environment = start_environment_supervisor(p);

    sleep(30);
    kill(camera, SIGALRM);
    kill(environment, SIGALRM);

    close_shared_memory(sm);
    return 0;
}
