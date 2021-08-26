#include <stdio.h>

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
int main(){
    int x,y;
    printf("Enter x:\n");
    scanf("%d", &x);
    printf("Enter y:\n");
    scanf("%d", &y);
    swap(&x,&y);
    printf("Value of x after swapping: %d\nValue of y after swapping: %d", x,y);





    return 0;
}