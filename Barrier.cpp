
#include "Barrier.h"

Barrier::Barrier(unsigned int num_of_threads) {
    this->n = num_of_threads;
    sem_init(&this->barrier1,0,0);
    sem_init(&this->barrier2,0,1);
    sem_init(&this->mutex1,0,1);
    this->counter = 0;
}

void Barrier::wait() {

    sem_wait(&this->mutex1);
        this->counter++;
        if(this->counter == this->n){
            sem_wait(&this->barrier2);
            sem_post(&this->barrier1);
        }
    sem_post(&this->mutex1);

    sem_wait(&this->barrier1);
    sem_post(&this->barrier1);

    sem_wait(&this->mutex1);
        this->counter--;
        if(this->counter == 0){
            sem_wait(&this->barrier1);
            sem_post(&this->barrier2);
        }
    sem_post(&this->mutex1);

    sem_wait(&this->barrier2);
    sem_post(&this->barrier2);

}

unsigned int Barrier::waitingThreads() {
    unsigned int temp;
    sem_wait(&this->mutex1);
        temp = this->counter;
    sem_post(&this->mutex1);
    return temp;
}

Barrier::~Barrier() {
    sem_destroy(&this->barrier1);
    sem_destroy(&this->barrier2);
    sem_destroy(&this->mutex1);
}