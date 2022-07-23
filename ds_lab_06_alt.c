#include <stdio.h>

int main()
{
    int a[100][100];
    int n, m, i, j, r;
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

    printf("Enter row no. to be deleted : ");
    scanf("%d", &r);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (i >= r)
            {
                a[i][j] = a[i + 1][j];
            }
        }
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