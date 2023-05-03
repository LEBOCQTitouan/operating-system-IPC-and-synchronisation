//
// Created by Titouan LEBOCQ on 03/05/2023.
//

#ifndef OPERATING_SYSTEM_IPC_AND_SYNCHRONISATION_IPC_H
#define OPERATING_SYSTEM_IPC_AND_SYNCHRONISATION_IPC_H

#include <sys/fcntl.h>
#include <sys/stat.h>       // For mode constants
#include <sys/mman.h>       // For O_* constants

#include <sys/semaphore.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>          // error handling

/**
 * Struct used to handle shared memory
 */
typedef struct {
    int fd;         // shared memory file descriptor
    void *mem_ptr;  // pointer to the shared memory
    size_t size;    // size of the shared memory element
} shared_memory;

/**
 * Function used to get a shared memory segment
 * @param path path to the shared memory segment
 * @param size size of the shared memory segment
 * @return the pointer to the shared memory segment
 */
shared_memory get_shared_memory_segment(char *path, size_t size);

/**
 * Function used to close an opened shared memory segment
 * @param sm the memory segment to close
 * @return the exit status of the function
 */
int close_shared_memory(shared_memory sm);

/**
 * Allow to someone to create a semaphore
 * @param path of the semaphore file
 * @return a ptr to the created semaphore
 */
sem_t *get_semaphore(char *path);

#endif //OPERATING_SYSTEM_IPC_AND_SYNCHRONISATION_IPC_H
