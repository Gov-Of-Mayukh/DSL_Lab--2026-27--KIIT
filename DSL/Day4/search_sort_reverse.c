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
    while(head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }

    printf("\n");
}

void search(struct node *head, int data)
{
    int pos = 1, found = 0;

    while(head != NULL)
    {
        if(head->data == data)
        {
            printf("Element found at position %d\n", pos);
            found = 1;
            break;
        }

        head = head->next;
        pos++;
    }

    if(found == 0)
        printf("Element not found\n");
}

void sort(struct node *head)
{
    struct node *i, *j;
    int temp;

    i = head;

    while(i != NULL)
    {
        j = i->next;

        while(j != NULL)
        {
            if(i->data > j->data)
            {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }

            j = j->next;
        }

        i = i->next;
    }
}

struct node *reverse(struct node *head)
{
    struct node *prev = NULL, *cur = head, *next;

    while(cur != NULL)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    return prev;
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
        printf("5. Search\n");
        printf("6. Sort\n");
        printf("7. Reverse\n");
        printf("8. Exit\n");
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
            printf("Enter element to search: ");
            scanf("%d", &data);
            search(head, data);
        }
        else if(ch == 6)
        {
            sort(head);
            printf("List sorted\n");
        }
        else if(ch == 7)
        {
            head = reverse(head);
            printf("List reversed\n");
        }
        else if(ch == 8)
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
