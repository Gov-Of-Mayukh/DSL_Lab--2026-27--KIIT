#include<stdio.h>
#include<stdlib.h>

struct Node{
    int INFO;
    struct Node *NEXT;
};

//5.1
int count(struct Node *Head, int shw){
    int count = 0;
    while(Head!=NULL){
        if(Head->INFO == shw)
            count++;
        Head = Head->NEXT;
    }
    return count;
}

//5.2
void MinMax(struct Node *Head){
    int min = Head->INFO, max = Head->INFO;
    while(Head!=NULL){
        if(Head->INFO > max)
            max = Head->INFO;
        if(Head->INFO < min)
            min = Head->INFO;
        Head = Head->NEXT;
    }
    printf("\nThe Maximum Element is %d and the Minimum Element is %d", max, min);
}

//5.3
void AdjSwap(struct Node *Head){
    struct Node *ptr, *temp;
    int count = 1;
    ptr = Head;
    temp = ptr->NEXT;
    Head = temp;
    while(temp!=NULL){
        if(count%2 == 0){
            temp->NEXT = ptr;
            temp = temp->NEXT;
            ptr = ptr->NEXT;
        }
        count++;
    }
    temp->NEXT = NULL;
    ptr = Head;
    printf("\nThe Swapped LL is: ");
    while(ptr!=NULL){
        printf("%d ", ptr->INFO);
        ptr = ptr->NEXT;
    }
}

void main(){
    int n, data;
    struct Node *Head, *ptr, *new;
    printf("Enter number of Nodes: ");
    scanf("%d", &n);
    printf("\nEnter Element 1: ");
    scanf("%d", &data);
    new = (struct Node *)malloc(sizeof(struct Node));
    new->INFO = data;
    new->NEXT = NULL;
    Head = new;
    ptr = Head;
    int  i = 1;
    while(i<n){
        printf("Enter Element %d: ", i+1);
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

    printf("\nEnter element to count: ");
    scanf("%d", &data);
    printf("\n%d occurs %d times in the SLL", data, count(Head, data));
    MinMax(Head);
//    AdjSwap(Head);
    printf("\n\n");
}
