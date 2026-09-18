#include<stdio.h>
#include<stdlib.h>

void smex(int n1, int n2){
    if(n1>n2){
        printf("%d is greater than %d", n1, n2);
    }
    else if(n1<n2){
        printf("%d is less than %d", n1, n2);
    }
    else{
        printf("Both are the same");
    }
}

void main(){
    int n1, n2;
    printf("Enter two integer numbers: ");
    scanf("%d%d", &n1, &n2);
//    system("clear");
    smex(n1, n2);
    printf("\n\n");
    getchar();
}
