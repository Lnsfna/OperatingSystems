#include <stdio.h>
#include <limits.h>
#include <float.h>


int main(){
    int a;
    float b;
    double c;

    a = INT_MAX;
    b = FLT_MAX;
    c = DBL_MAX;

    printf("Integer = %d\n",a);
    printf("Float = %f\n",b);
    printf("Double = %f\n",c);
    printf("Size of integer = %lu\n",sizeof(a));
    printf("Size of float = %lu\n",sizeof(b));
    printf("Size of double = %lu",sizeof(c));

    return 0;
}

