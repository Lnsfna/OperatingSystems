#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define N 10
int main(){
    int bytes = 1024 * 1024 * 10;
    for(int i = 0; i < N; i++){
        int *data = (int *) malloc(bytes);
        printf("10MB were allocated\n");
        memset(data, 0, bytes/sizeof (int));
        sleep(1);
    }
    // when we use "top -i 1" command while running this code, we can see, that Virtual memory and Resources for process increas each time we allocate 10Mb
    // also swapping memory increases
}
