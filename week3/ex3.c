#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};
struct linked_list {
    struct node *head;
    int size;
};
void insert_head(struct linked_list* l, int data){
    if(l->size == 0){
        struct node * n = malloc(sizeof(struct node));
        n->data = data;
        l->head = n;
    }
    else{
        struct node * n = malloc(sizeof(struct node));
        n->data = data;
        n->next = l->head;
        l->head = n;
    }
    l->size++;

}

void insert_node(struct linked_list* l, int data, int privitem) {
    if (l->size > 0) {
        struct node *p,*n;
        p = l->head;
        n = p->next;
        while (p->data != privitem) {
            p = n;
            n = n->next;
        }
        struct node *a = malloc(sizeof(struct node));
        a->data = data;
        a->next = n;
        p->next = a;
        l->size++;
    }
    else{
        printf("Error!");
    }
}

void print_list(struct linked_list* l){
    struct node *n;
    n = l->head;
    for(int i = 0; i < l->size-1; i++){
        printf("%d -> ", n->data);
        n = n->next;
    }
    printf("%d\n", n->data);

}

void delete_node(struct linked_list* l, int data){
    struct node *p,*n,*a;
    if(data != l->head->data){
        p = l->head;
        n = p->next;
        a = n->next;
        while(n->data != data){
            p = n;
            n = n->next;
            a = a->next;
        }
        p->next = a;
    }
    else{
        l->head = l->head->next;
    }
    l->size--;
}

int main(){
    struct linked_list list;
    list.size = 0;

    //Here I demonstrate how the program works. You can also test on your own values,but please note that the program only accepts integer values.

    insert_head(&list,1);
    insert_node(&list,2,1);
    print_list(&list);
    insert_node(&list,3,1);
    print_list(&list);
    delete_node(&list, 3);
    print_list(&list);
    delete_node(&list, 1);
    print_list(&list);
    insert_head(&list,4);
    print_list(&list);

    return 0;
}








