#include<stdio.h>

void main(){
    int n, ins, lo=0, ch;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int shw[n];
    printf("\n");

    for(int i=0; i<n; i++){
        printf("Enter Element %d: ", i+1);
        scanf("%d", &shw[i]);
    }

    printf("\nArray created.\n");
    for(int i=0; i<n; i++)
        printf("%d ", shw[i]);


    while(1==1){
        printf("\n\n\tMenu\n1. Insert an element.\n2. Delete an element.\n3. Search an element.\n4. Exit");
        printf("\nEnter Choice: ");
        scanf("%d",&ch);

        if(ch == 1){
            printf("\nEnter element to be inserted: ");
            scanf("%d", &ins);
            printf("\nEnter location index: ");
            scanf("%d",&lo);
            if(lo<n){
                shw[lo] = ins;

                printf("\nUpdated. New array:\n");
                for(int i=0; i<n; i++)
                    printf("%d", shw[i]);
            }

            else
                printf("\nIndex Fault!");
        }

        if(ch == 2){
            printf("\nEnter element to be deleted: ");
            scanf("%d", &ins);

            for(int i=0; i<n; i++){
                if(shw[i] == ins)
                     shw[i] = 0;
                     lo = 1;
            }

            if(!lo)
                printf("\nNo element found!");
            else{
                printf("\nUpdated. New array:\n");
                for(int i=0; i<n; i++)
                    printf("%d", shw[i]);
            }
        }

        if(ch == 3){
            printf("\nEnter element to search: ");
            scanf("%d", &ins);

            for(int i=0; i<n; i++){
                if(shw[i] == ins){
                    printf("\n%d is found at %d index.", ins, i);
                    lo = 1;
                }
            }
            if(lo == 0)
                 printf("\nElement not found!");
        }

        if(ch == 4)
            break;
    }
    printf("\n\n");
}

