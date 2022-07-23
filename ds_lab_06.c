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

    a[0][0] = 0;

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