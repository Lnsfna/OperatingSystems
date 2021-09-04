#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(int *x, int *y){
    int t = *x;
    *x = *y;
    *y = t;
}
void bubble_sort(int arr[], int size){
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - 1 - i; j ++){
            if(arr[j] > arr[j+1]){
                swap(&arr[j], &arr[j+1]);
            }
        }
    }

}
int main(){
    int size;
    char n;
    char in[1000];
    printf("Enter the size of array:\n");
    scanf("%d",&size);
    int arr[size];
    scanf("%c", &n); //catching \n symbol
    printf("Enter the array:\n");
    fgets(in,1000,stdin);
    char* a = strtok(in," ");
    int i = 0;
    while(a != NULL){
        arr[i++] = atoi(a);
        a = strtok(NULL, " ");
    }
    bubble_sort(arr,size);
    for(int j = 0; j < size; j++){
        printf("%d ", arr[j]);
    }

    return 0;
}