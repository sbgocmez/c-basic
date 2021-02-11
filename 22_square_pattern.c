#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("square pattern of n numbers, n: ");
    scanf("%d", &n);
    printf("\n****************\n");
    int tim = 2 * n - 1;

    int j = n;
    while (tim > 0)
    {

        for (int k = n; k > j; k--)
        {
            printf("%d ", k);
        }
        for (int m = tim; m > 0; m--)
        {
            printf("%d ", j);
        }
        for (int k = j + 1; k <= n; k++)
        {
            printf("%d ", k);
        }
        printf("\n");
        j--;
        tim = tim - 2;
    }
    tim = 2 * n - 1;
    int r = 1;
    j = 1;
    while (r < tim)
    {

        for (int k = n; k > j; k--)
        {
            printf("%d ", k);
        }

        for (int m = r + 1; m > 1; m--)
        {
            printf("%d ", j + 1);
        }
        for (int k = j + 1; k <= n; k++)
        {
            printf("%d ", k);
        }

        printf("\n");
        r = r + 2;
        j++;
    }
}