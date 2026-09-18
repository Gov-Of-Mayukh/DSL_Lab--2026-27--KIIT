#include<stdio.h>
#include<stdlib.h>

struct Node{
    int INFO;
    struct Node *NEXT;
};

struct Node * insertEND(struct Node *Head, int data){
    struct Node *ptr, *new;
    ptr = Head;
    new = (struct Node *)malloc(sizeof(struct Node));
    new->INFO = data;
    new->NEXT = NULL;

    while(ptr != NULL)
        ptr = ptr->NEXT;
    ptr->NEXT = new;

    return Head;
}

void main(){
    struct Node *Head, *ptr, *new;
    int n, data, i;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("\nEnter Element 1: ");
    scanf("%d", &data);
    new = (struct Node *)malloc(sizeof(struct Node));
    new->INFO = data;
    new->NEXT = NULL;
    Head = new;
    ptr = Head;

    i = 1;
    while(i<n){
        printf("\nEnter Element %d: ", i+1);
        scanf("%d", &data);
        new = (struct Node *)malloc(sizeof(struct Node));
        new->INFO = data;
        new->NEXT = NULL;

        ptr->NEXT = new;
        ptr = ptr->NEXT;
        i++;
    }

    ptr = Head;
    printf("\nThe SLL is: ");
    while(ptr!=NULL){
        printf("%d ", ptr->INFO);
        ptr = ptr->NEXT;
    }

    printf("\nEnter Element to add to last: ");
    scanf("%d", &data);
    Head = insertEND(Head, data);
    ptr = Head;
    printf("\nThe SLL is: ");
    while(ptr!=NULL){
        printf("%d ", ptr->INFO);
        ptr = ptr->NEXT;
    }
    printf("\n\n");
}

