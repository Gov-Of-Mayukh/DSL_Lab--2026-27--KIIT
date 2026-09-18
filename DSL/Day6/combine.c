#include<stdio.h>
#include<stdlib.h>

struct Node{
    int INFO;
    sturct Node *NEXT;
}*Head;

void combine(struct Node *head1, struct Node *head2){
    struct Node *Head3, *new, *ptr;
    int count = 0;
    new = (struct Node *)malloc(sizeof(struct Node));
    new->INFO = head1->INFO + head2->INFO;
    new->NEXT = NULL;
    Head3 = new;
    ptr = new;

    head1 = head1->NEXT->NEXT;
    head2 = head2->NEXT->NEXT;

    while(head1!=NULL || head2!=NULL){
        new = (struct Node *)malloc(sizeof(struct Node));
        new->INFO = head1->INFO + head2->INFO;
        new->NEXT = NULL;

        ptr->NEXT = new;
        ptr = ptr->NEXT;

        head1 = head1->NEXT->NEXT;
        head2 = head2->NEXT->NEXT;
    }
}
