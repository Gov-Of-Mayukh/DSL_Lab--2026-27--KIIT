#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *insert(struct node *head, int pos, int data)
{
    struct node *newnode, *temp;
    int i;

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    if(pos == 1)
    {
        newnode->next = head;
        head = newnode;
    }
    else
    {
        temp = head;
        i = 1;

        while(i < pos-1 && temp != NULL)
        {
            temp = temp->next;
            i++;
        }

        if(temp == NULL)
            printf("Invalid position\n");
        else
        {
            newnode->next = temp->next;
            temp->next = newnode;
        }
    }

    return head;
}

struct node *delete(struct node *head, int pos)
{
    struct node *temp, *del;
    int i;

    if(head == NULL)
    {
        printf("List is empty\n");
        return head;
    }

    if(pos == 1)
    {
        del = head;
        head = head->next;
        free(del);
    }
    else
    {
        temp = head;
        i = 1;

        while(i < pos-1 && temp->next != NULL)
        {
            temp = temp->next;
            i++;
        }

        if(temp->next == NULL)
            printf("Invalid position\n");
        else
        {
            del = temp->next;
            temp->next = del->next;
            free(del);
        }
    }

    return head;
}

int count(struct node *head)
{
    int c = 0;

    while(head != NULL)
    {
        c++;
        head = head->next;
    }

    return c;
}

void traverse(struct node *head)
{
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    while(head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }

    printf("\n");
}

int main()
{
    struct node *head = NULL;
    int n, i, data, pos, ch;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    i = 1;
    while(i <= n)
    {
        printf("Enter data: ");
        scanf("%d", &data);
        head = insert(head, i, data);
        i++;
    }

    while(1)
    {
        printf("\n1. Insert\n");
        printf("2. Delete\n");
        printf("3. Count\n");
        printf("4. Traverse\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        if(ch == 1)
        {
            printf("Enter position: ");
            scanf("%d", &pos);
            printf("Enter data: ");
            scanf("%d", &data);
            head = insert(head, pos, data);
        }
        else if(ch == 2)
        {
            printf("Enter position: ");
            scanf("%d", &pos);
            head = delete(head, pos);
        }
        else if(ch == 3)
        {
            printf("Number of nodes = %d\n", count(head));
        }
        else if(ch == 4)
        {
            traverse(head);
        }
        else if(ch == 5)
        {
            break;
        }
        else
        {
            printf("Invalid choice\n");
        }
    }

    return 0;
}
