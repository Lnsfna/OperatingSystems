#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    printf("Enter the number of elements in array: ");
    scanf("%d",&n);

    int *arr = malloc(n * sizeof(int));
    for(int i = 0; i < n; i++){
        arr[i] = i;
    }
    for(int i = 0; i < n; i++){
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    free(arr);
    return 0;
}
