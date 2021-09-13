#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("To stop write exit\n");
    char user_input[255], answer[255];
    while (1) {

        scanf("%s", user_input);
        if (!strcmp(user_input, "exit")) {
            return 0;
        }
        int res = system(user_input);
        if (res == 1) {
            return 1;
        }
         answer[0] = '\0';
        printf("\n%s\n", answer);
        }
    }




