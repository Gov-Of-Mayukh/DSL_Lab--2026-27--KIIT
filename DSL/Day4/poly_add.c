#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coeff;
    int exp;
    struct node *next;
};

struct node *insert(struct node *head, int coeff, int exp)
{
    struct node *newnode, *temp;

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->coeff = coeff;
    newnode->exp = exp;
    newnode->next = NULL;

    if(head == NULL)
    {
        head = newnode;
    }
    else
    {
        temp = head;

        while(temp->next != NULL)
            temp = temp->next;

        temp->next = newnode;
    }

    return head;
}

struct node *add(struct node *p, struct node *q)
{
    struct node *r = NULL;

    while(p != NULL && q != NULL)
    {
        if(p->exp == q->exp)
        {
            if(p->coeff + q->coeff != 0)
                r = insert(r, p->coeff + q->coeff, p->exp);

            p = p->next;
            q = q->next;
        }
        else if(p->exp > q->exp)
        {
            r = insert(r, p->coeff, p->exp);
            p = p->next;
        }
        else
        {
            r = insert(r, q->coeff, q->exp);
            q = q->next;
        }
    }

    while(p != NULL)
    {
        r = insert(r, p->coeff, p->exp);
        p = p->next;
    }

    while(q != NULL)
    {
        r = insert(r, q->coeff, q->exp);
        q = q->next;
    }

    return r;
}

void display(struct node *head)
{
    while(head != NULL)
    {
        printf("%dx^%d", head->coeff, head->exp);

        if(head->next != NULL)
            printf(" + ");

        head = head->next;
    }

    printf("\n");
}

int main()
{
    struct node *p = NULL, *q = NULL, *r = NULL;
    int n, i, coeff, exp;

    printf("Enter number of terms in first polynomial: ");
    scanf("%d", &n);

    i = 1;
    while(i <= n)
    {
        printf("Enter coefficient and exponent: ");
        scanf("%d%d", &coeff, &exp);
        p = insert(p, coeff, exp);
        i++;
    }

    printf("Enter number of terms in second polynomial: ");
    scanf("%d", &n);

    i = 1;
    while(i <= n)
    {
        printf("Enter coefficient and exponent: ");
        scanf("%d%d", &coeff, &exp);
        q = insert(q, coeff, exp);
        i++;
    }

    printf("\nFirst polynomial: ");
    display(p);

    printf("Second polynomial: ");
    display(q);

    r = add(p, q);

    printf("Addition: ");
    display(r);

    return 0;
}
