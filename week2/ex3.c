#include <stdio.h>

void pyramid(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-1-i; j++){
            printf(" ");
        }
        for(int k = 0; k < 2*i+1; k++){
            printf("*");
        }
        printf("\n");
    }
}
int main(){
    int n;
    printf("Enter the number:\n");
    scanf("%d",&n);
    pyramid(n);
    return 0;
}

