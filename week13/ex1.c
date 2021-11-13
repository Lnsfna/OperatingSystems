#include <stdio.h>

#define M 5
#define N 3

int main(){
    int E[N];
    int A[N];
    int C[M][N];
    int R[M][N];
    int D[M] = {0};

    FILE* f = fopen("input_dl.txt", "r");;
    for (int i = 0; i < N; i++){
        fscanf(f, "%i", &E[i]);
    }
    for (int i = 0; i < N; i++){
        fscanf(f, "%i", &A[i]);
    }
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            fscanf(f, "%i", &C[i][j]);
        }
    }
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            fscanf(f, "%i", &R[i][j]);
        }
    }
    fclose(f);

    int flag = 1;
    while (flag){
        flag = 0;
        for (int i = 0; i < M; i++) {
            if (!D[i]) {
                int indicator = 1;
                for (int j = 0; j < N; j++) {
                    if (A[j] + C[i][j] < R[i][j])
                        indicator = 0;
                }
                if (indicator) {
                    flag = 1;
                    D[i] = 1;
                    for (int j = 0; j < N; j++) {
                        A[j] += C[i][j];
                    }
                }
            }
        }
    }

    flag = 0;
    for (int i = 0; i < M; i++){
        if (!D[i]){
            printf("Deadlock in process #%i\n", i);
            flag = 1;
        }
    }
    if(!flag){
        printf("There are no deadlocks\n");
    }


    return 0;
}
