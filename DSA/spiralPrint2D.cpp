#include<iostream>
using namespace std;

int main()
{
    int a[3][4] = {1, 2, 3, 4,
                   5, 6, 7, 8,
                   9, 10, 11, 12};
    int col = 4, row = 3;
    int fr = 0, fc = 0, lr = row - 1, lc = col - 1;
    int i = 0, j = 0;

    while (fr <= lr && fc <= lc)
    {
        for (j = fc; j <= lc; j++)
            cout << a[fr][j] << " , ";
        fr++;
        for (i = fr; i <= lr; i++)
            cout << a[i][lc] << " , ";
        lc--;
        if (lr > fr)
        {
            for (j = lc; j >= fc; j--)
                cout << a[lr][j] << " , ";
            lr--;
        }
        if (lc > fc)
        {
            for (i = lr; i >= fr; i--)
                cout << a[i][fc] << " , ";
            fc++;
        }
    }
    return 0;
}
