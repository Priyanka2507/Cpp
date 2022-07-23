#include <stdio.h>

int main()
{
    int a[100][100];
    int n, m, i, j, b;
    printf("Enter dimensions of matx : ");
    scanf("%d %d", &n, &m);
    printf("Enter values \n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    // deleting first element
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            a[i][j] = a[i][j + 1];
        }
        a[i][j - 1] = a[i + 1][0];
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}