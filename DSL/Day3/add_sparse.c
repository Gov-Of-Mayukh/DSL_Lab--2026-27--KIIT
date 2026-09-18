#include <stdio.h>

int main()
{
    int a[20][20], b[20][20], s1[50][3], s2[50][3], sum[100][3];
    int rows, cols, i, j;
    int k1 = 1, k2 = 1, k3 = 1;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter first matrix:\n");
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            scanf("%d", &a[i][j]);

            if(a[i][j] != 0)
            {
                s1[k1][0] = i;
                s1[k1][1] = j;
                s1[k1][2] = a[i][j];
                k1++;
            }
        }
    }

    printf("Enter second matrix:\n");
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            scanf("%d", &b[i][j]);

            if(b[i][j] != 0)
            {
                s2[k2][0] = i;
                s2[k2][1] = j;
                s2[k2][2] = b[i][j];
                k2++;
            }
        }
    }

    s1[0][0] = rows;
    s1[0][1] = cols;
    s1[0][2] = k1 - 1;

    s2[0][0] = rows;
    s2[0][1] = cols;
    s2[0][2] = k2 - 1;

    i = 1;
    j = 1;

    while(i < k1 && j < k2)
    {
        if(s1[i][0] == s2[j][0] && s1[i][1] == s2[j][1])
        {
            if(s1[i][2] + s2[j][2] != 0)
            {
                sum[k3][0] = s1[i][0];
                sum[k3][1] = s1[i][1];
                sum[k3][2] = s1[i][2] + s2[j][2];
                k3++;
            }
            i++;
            j++;
        }
        else if(s1[i][0] < s2[j][0] ||
               (s1[i][0] == s2[j][0] && s1[i][1] < s2[j][1]))
        {
            sum[k3][0] = s1[i][0];
            sum[k3][1] = s1[i][1];
            sum[k3][2] = s1[i][2];
            k3++;
            i++;
        }
        else
        {
            sum[k3][0] = s2[j][0];
            sum[k3][1] = s2[j][1];
            sum[k3][2] = s2[j][2];
            k3++;
            j++;
        }
    }

    while(i < k1)
    {
        sum[k3][0] = s1[i][0];
        sum[k3][1] = s1[i][1];
        sum[k3][2] = s1[i][2];
        k3++;
        i++;
    }

    while(j < k2)
    {
        sum[k3][0] = s2[j][0];
        sum[k3][1] = s2[j][1];
        sum[k3][2] = s2[j][2];
        k3++;
        j++;
    }

    sum[0][0] = rows;
    sum[0][1] = cols;
    sum[0][2] = k3 - 1;

    printf("\nFirst Sparse Matrix:\n");
    for(i = 0; i < k1; i++)
        printf("%d\t%d\t%d\n", s1[i][0], s1[i][1], s1[i][2]);

    printf("\nSecond Sparse Matrix:\n");
    for(i = 0; i < k2; i++)
        printf("%d\t%d\t%d\n", s2[i][0], s2[i][1], s2[i][2]);

    printf("\nAddition of Sparse Matrices:\n");
    for(i = 0; i < k3; i++)
        printf("%d\t%d\t%d\n", sum[i][0], sum[i][1], sum[i][2]);

    return 0;
}
