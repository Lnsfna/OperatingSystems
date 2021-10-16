#include <stdio.h>
#define NUM_BITS 8
#define N 10         // 10 or 50 or 100

struct page{
    int id;
    int counter;
};
int execute(struct page* pages, int n){
    int flag = 0;
    int minId = 0;
    int minCounter = (1 << NUM_BITS) - 1;

    for (int i = 0; i < N; i++){
        if (pages[i].id == -1){
            if (flag)
                continue;

            flag = 1;
            pages[i].id = n;
            pages[i].counter |= 1 << (NUM_BITS - 1);
        } else{
            pages[i].counter >>= 1;
        }


        if (minCounter > pages[i].counter){
            minCounter = pages[i].counter;
            minId = i;
        }

        if (pages[i].id == n){
            flag = 1;
            pages[i].counter |= 1 << (NUM_BITS - 1);
        }
    }

    if (flag)
        return 1; 

    pages[minId].id = n;
    pages[minId].counter |= 1 << (NUM_BITS - 1);
    return 0; 
}

void print_pages(struct page* pages){
    for (int i = 0; i < N; i++){
        printf("id: %d\tcounter: %d\n", pages[i].id, pages[i].counter);
    }
}

void init(struct page *page){
    for (int i = 0; i < N; i++){
        page[i].counter = 0;
        page[i].id = -1;
    }
}

int main(){
    struct page pages[N];

    init(pages);
    print_pages(pages);
    FILE* file = fopen("/Users/alinasafina/Desktop/Lab 09 input.txt", "r");

    int n;
    int hits = 0;
    int misses = 0;

    while (fscanf(file, "%d", &n) == 1){
        if (execute(pages, n))
            hits++;
        else
            misses++;
        printf("Page #%d:\n", n);
        print_pages(pages);
        printf("\n");
    }
    fclose(file);
    printf("hits: %d, misses: %d, ration: %f\n", hits, misses, (float) hits / (float) misses);
    
    return 0;
}
