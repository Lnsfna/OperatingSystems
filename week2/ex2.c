#include <stdio.h>
#include <string.h>

int main(){
    char str[1000], c;
    printf("Enter a string:\n");
    fgets(str,1000,stdin);
    int n;
    n = strlen(str);
    for(int i = 0; i < n/2; i++){
        c = str[i];
        str[i] = str[n-1-i];
        str[n-1-i] = c;
    }
    printf("Reversed string: %s",str);



    return 0;
}

