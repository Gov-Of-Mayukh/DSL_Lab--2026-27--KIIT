#include<stdio.h>

void main(){
    int row, col;
    printf("\nEnter the number of rows and columns: ");
    scanf("%d %d", &row, &col);

    if(row == col){
        int shw[row][col];
        for(int i=0; i<row; i++){
            printf("\nFor Row %d\n", i+1);
            for(int j=0; j<col; j++){
                printf("Enter Element %d: ", j+1);
                scanf("%d",&shw[i][j]);
            }
        }

        printf("\n\tThe Array is\n");
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++)
                printf("%2d ", shw[i][j]);
            printf("\n");
        }

        printf("\n");

        printf("\n\tThe Upper and Lower diagonal elements are:\n");
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(i!=j)
                    printf("%2d ", shw[i][j]);
                else
                    printf("   ");
            }
            printf("\n");
        }
    }
    else
        printf("\nNot a square matrix!");

    printf("\n\n");
}
