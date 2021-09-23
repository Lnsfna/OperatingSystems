#include <stdio.h>

#define MAX_NUM_OF_PROCESSES 100


struct process{
    int AT;
    int BT;
    int CT;
    int TAT;
    int WT;

    int remaining_time;
    int pr_time;

};


int main(){
    int n,quantum;
    float TAT_total = 0;
    float WT_total = 0;
    struct process p[MAX_NUM_OF_PROCESSES];
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    printf("Enter the quantum: ");
    scanf("%d",&quantum);

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
        p[i].CT = -1;
        p[i].remaining_time = p[i].BT;

    }
    int flag = 1;
    int time = 0;
    while (flag){
        flag = 0;
        for(int i = 0; i < n; i++){
            if(p[i].CT != -1){
                continue;
            }
            else{
                p[i].WT += time - p[i].pr_time;
                if(p[i].remaining_time > quantum){
                    flag = 1;
                    p[i].remaining_time -= quantum;
                    time += quantum;
                    p[i].pr_time = time;
                } else{
                    time += p[i].remaining_time;

                    p[i].remaining_time = 0;
                    p[i].CT = time;
                    p[i].TAT = p[i].CT - p[i].AT;
                    TAT_total += (float)p[i].TAT;
                    WT_total +=(float) p[i].WT;
                }

            }
        }

    }
    printf("P#\tAT\tBT\tCT\tTAT\tWT");
    for(int i = 0; i < n; i++){
        printf("\nP%d\t%d\t%d\t%d\t%d\t%d",i+1,p[i].AT,p[i].BT,p[i].CT,p[i].TAT,p[i].WT);
    }
    printf("\nAverage Turnaround time = %f\n", TAT_total / n);
    printf("Average Waiting time = %f", WT_total / n);
    return 0;
}
