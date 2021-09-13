#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main(){
    int pid = fork();
    int n = 3;
    if (pid > 0){
	for(int i = 0; i < n; i++){
        printf("Hello from parent [%d - %d]\n", pid,n);
	} 
    }
    else if(pid == 0){
	for(int i = 0; i < n; i++){
        	printf("Hello from child [%d - %d]\n", pid,n);
        }
    }
    else{
        return -1;
    }
    return 0;
}

