#include <stdio.h>

int main()
{
    int n, x, i, j, sum, min, start, end;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter array elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter X: ");
    scanf("%d", &x);

    min = n + 1;
    start = -1;
    end = -1;

    for(i = 0; i < n; i++)
    {
        sum = 0;

        for(j = i; j < n; j++)
        {
            sum = sum + a[j];

            if(sum > x)
            {
                if(j - i + 1 < min)
                {
                    min = j - i + 1;
                    start = i;
                    end = j;
                }
                break;
            }
        }
    }

    if(start == -1)
    {
        printf("No subarray found");
    }
    else
    {
        printf("Smallest subarray: ");
        for(i = start; i <= end; i++)
            printf("%d ", a[i]);

        printf("\nMinimum length = %d", min);
    }

    return 0;
}
