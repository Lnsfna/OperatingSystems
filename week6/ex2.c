#include <stdio.h>

#define MAX_NUM_OF_PROCESSES 100


struct process{
    int AT;
    int BT;
    int CT;
    int TAT;
    int WT;

};

void swap(struct process *a, struct process *b){
    struct process t = *a;
    *a = *b;
    *b = t;
}

void sort(struct process p[], int n){
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            if(p[j+1].BT < p[j].BT){
                swap(&p[j],&p[j+1]);
            }
        }
    }
}
int main(){
    int n;
    float TAT_total = 0;
    float WT_total = 0;
    struct process p[MAX_NUM_OF_PROCESSES];
    printf("Enter the number of processes: ");
    scanf("%d",&n);

    if(n > MAX_NUM_OF_PROCESSES){
        printf("Number of processes is greater than the maximum number of processes (%d)", MAX_NUM_OF_PROCESSES);
        return 0;
    }
    else if(n == 0){
        printf("Number of processes can't be equal to 0");
        return 0;
    }
    for(int i = 0; i < n; i++){
        printf("Arrival time of process [%d]: ",i+1);
        scanf("%d",&p[i].AT);
        printf("Burst time of process [%d]: ",i+1);
        scanf("%d",&p[i].BT);

    }
    sort(p,n);
    for(int i = 0; i < n; i++){
        if(i == 0){
            p[i].WT = 0;
        } else{
            p[i].WT = p[i-1].CT - p[i].AT;
        }
        p[i].CT = p[i].BT + p[i].AT + p[i].WT;
        p[i].TAT = p[i].CT - p[i].AT;
        TAT_total += (float)p[i].TAT;
        WT_total +=(float) p[i].WT;
    }
    printf("P#\tAT\tBT\tCT\tTAT\tWT");
    for(int i = 0; i < n; i++){
        printf("\nP%d\t%d\t%d\t%d\t%d\t%d",i+1,p[i].AT,p[i].BT,p[i].CT,p[i].TAT,p[i].WT);
    }
    printf("\nAverage Turnaround time = %f\n", TAT_total / n);
    printf("Average Waiting time = %f", WT_total / n);
    return 0;
}
