#include <stdio.h>

int main()
{
    int a[20][20], sparse[50][3], transpose[50][3];
    int rows, cols, i, j, k = 1, t = 1;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter matrix elements:\n");
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            scanf("%d", &a[i][j]);

            if(a[i][j] != 0)
            {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = a[i][j];
                k++;
            }
        }
    }

    sparse[0][0] = rows;
    sparse[0][1] = cols;
    sparse[0][2] = k - 1;

    transpose[0][0] = cols;
    transpose[0][1] = rows;
    transpose[0][2] = k - 1;

    for(i = 0; i < cols; i++)
    {
        for(j = 1; j < k; j++)
        {
            if(sparse[j][1] == i)
            {
                transpose[t][0] = sparse[j][1];
                transpose[t][1] = sparse[j][0];
                transpose[t][2] = sparse[j][2];
                t++;
            }
        }
    }

    printf("\nOriginal Sparse Matrix (3-Tuple):\n");
    for(i = 0; i < k; i++)
        printf("%d\t%d\t%d\n", sparse[i][0], sparse[i][1], sparse[i][2]);

    printf("\nTranspose Sparse Matrix (3-Tuple):\n");
    for(i = 0; i < t; i++)
        printf("%d\t%d\t%d\n", transpose[i][0], transpose[i][1], transpose[i][2]);

    return 0;
}
