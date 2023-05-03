#include <stdio.h>
#include "IPC/ipc.h"
#include "util.h"

int main() {
    shared_memory sm;
    sem_t *sem;

    sem = get_semaphore(MUTEX_NAME);
    sm = get_shared_memory_segment(PARAM_PATH, sizeof(Parameters));

    sem_close(sem);
    close_shared_memory(sm);
    return 0;
}
