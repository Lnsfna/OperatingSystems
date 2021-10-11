#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>

#define N 10
int main(){
    int bytes = 1024 * 1024;
    for(int i = 0; i < N; i++){
        int *data = (int *) malloc(bytes * 10);
        printf("10MB were allocated\n");
        memset(data, 0, bytes*10/sizeof (int));
        struct rusage usage;
        getrusage(RUSAGE_SELF, &usage);
        printf("CPU time: %ld.%061d sec system,\n maximum resident set size %ld,\n integral shared memory size %ld,\n "
               "integral unshared data size %ld,\n integral unshared stack size %ld\n",

               usage.ru_stime.tv_sec, usage.ru_stime.tv_usec,

               usage.ru_maxrss, usage.ru_ixrss, usage. ru_idrss, usage.ru_isrss);


        sleep(1);
    }
}
