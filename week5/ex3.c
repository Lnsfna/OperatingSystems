#include <stdio.h>
#include <time.h>
#include <pthread.h>

#define size 10
int count = 0;
char buffer[size];
int i = 0;
pthread_mutex_t lock;
pthread_cond_t cond_c, cond_p;

_Noreturn void *producer(void *prd)
{

    while (1) {
        pthread_mutex_lock(&lock);

        if (count == size){
            pthread_cond_wait(&cond_p, &lock);
        }
        buffer[count] = 'p';
        count++;

        if (count == 1){
            pthread_cond_signal(&cond_c);
            pthread_mutex_unlock(&lock);
        }
    }
}

_Noreturn void *consumer(void *cns)
{
    while (1) { 
        pthread_mutex_lock(&lock);
        if (count == 0){
            pthread_cond_wait(&cond_c, &lock);
        }
        buffer[count] = 'c';
        count--;
        if (count == size - 1){
            pthread_cond_signal(&cond_p);
            pthread_mutex_unlock(&lock);
        }
    }
}


int main(int argc, char const *argv[]){
    pthread_t p, c;
    pthread_mutex_init(&lock, 0);
    pthread_cond_init(&cond_c, 0);
    pthread_cond_init(&cond_p, 0);
    pthread_create(&c, 0, consumer, 0);
    pthread_create(&p, 0, producer, 0);
    pthread_join(p, 0);
    pthread_join(c, 0);

    return 0;

}
