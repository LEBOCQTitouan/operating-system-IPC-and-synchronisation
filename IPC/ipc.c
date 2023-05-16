//
// Created by Titouan LEBOCQ on 03/05/2023.
//
#include "ipc.h"

shared_memory get_shared_memory_segment(char *path, size_t size) {
    shared_memory new_shared_memory = {0};

    // trying to create a shared memory file
    new_shared_memory.fd = shm_open(path, O_CREAT|O_EXCL, S_IRUSR|S_IWUSR);
    if (new_shared_memory.fd < 0) {
        if (errno != EEXIST) {
            perror("shm_open (creation)");
            exit(EXIT_FAILURE);
        }
        // trying to open an already existing shared memory
        new_shared_memory.fd = shm_open(path, O_RDWR, S_IRUSR|S_IWUSR);
        if (new_shared_memory.fd < 0) {
            perror("shm_open (opening existing file)");
            exit(EXIT_FAILURE);
        }
    } else {
        // set the size of the shared memory file to the given length
        new_shared_memory.fd = shm_open(path, O_CREAT|O_RDWR, S_IRUSR|S_IWUSR);
        if (ftruncate(new_shared_memory.fd, (off_t)size) == -1) {
            perror("ftruncate");
            exit(EXIT_FAILURE);
        }
    }
    // map a file to memory
    if (
        (new_shared_memory.mem_ptr = mmap(
            NULL,                   // address of start of the page
            size,
            PROT_READ | PROT_WRITE, // page access mode
            MAP_SHARED,             // segment type
            new_shared_memory.fd,
            0                       // projection offset
        )) == MAP_FAILED
    ) {
        perror("mmap");
        exit(EXIT_FAILURE);
    }

    new_shared_memory.size = size;
    return new_shared_memory;
}

int close_shared_memory(shared_memory sm) {
    if (munmap(sm.mem_ptr, sm.size) == -1) {
        perror("munmap");
        return EXIT_FAILURE;
    }
    if (close(sm.fd) == -1) {
        perror("close");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

sem_t *get_semaphore(char *path) {
    sem_t *sem_ptr;
    sem_ptr = sem_open(path, O_CREAT, S_IRUSR | S_IWUSR, 1); // trying to create a new semaphore
    if (
        sem_ptr == SEM_FAILED
        && errno != EEXIST
    ) {
        perror("sem_open (creation)");
        exit(EXIT_FAILURE);
    }

    // trying to open an already existing semaphore
    if (
        sem_ptr == SEM_FAILED
        && errno == EEXIST
        && (sem_ptr = sem_open(path, O_RDWR, S_IRUSR | S_IWUSR, 1)) != EXIT_SUCCESS
    ) {
        perror("sem_open (already existing one)");
        exit(EXIT_FAILURE);
    }

    return sem_ptr;
}
