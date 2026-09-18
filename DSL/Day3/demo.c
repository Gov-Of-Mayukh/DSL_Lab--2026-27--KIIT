#include<stdio.h>

void main(){
    int n, max;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int shw[n];
    printf("\nEnter array elements:\n");
    for(int i=0; i<n; i++){
        printf("\nElement %d: ", i+1);
        scanf("%d", &shw[i]);
    }
    max=shw[0];
    printf("\nThe Array is: ");
    for(int i=0; i<n; i++){
        printf("%d ", shw[i]);
        if(shw[i]>max)
            max=shw[i];
    }

    printf("\nThe Highest element of the Array is: %d", max);
    printf("\n\n");
}
