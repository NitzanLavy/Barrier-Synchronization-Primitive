#ifndef BARRIER_H_
#define BARRIER_H_

#include <semaphore.h>

class Barrier {
    sem_t barrier1;
    sem_t barrier2;
    sem_t mutex1;
    unsigned int n;
    unsigned int counter;
public:
    Barrier(unsigned int num_of_threads);
    void wait();
    unsigned int waitingThreads();
    ~Barrier();
};

#endif // BARRIER_H_

