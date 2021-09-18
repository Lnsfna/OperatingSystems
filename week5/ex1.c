#include <stdio.h>
#include <pthread.h>

int n = 15;
int turn;
int flag[15];

void *myThread(void *arg){
    while ( (int)arg != turn && !flag[(int)arg]){}
    printf(" >>Hello from myThread #%d\n", arg);
    turn++;
    flag[(int) arg] = 0;
    pthread_exit(NULL);


}

int main(){
    pthread_t thread;
    turn = 0;
    for(int i = 0; i < n; i++){
        flag[i] = 0;
    }
    for(int i = 1; i <= n ; i++) {
        if (pthread_create(&thread, NULL, myThread, i)) {
            printf(" >> ERROR IN CREATING Thread #%d!\n");
            pthread_exit(NULL);
            return 1;
        } else {
            printf("Thread #%d created!\n", i);
            flag[i] = 1;
            while (flag[i]){}


        }
    }
    return 0;
}



