#include <bits/stdc++.h>
using namespace std;

void backtrack(int *S[], int n, int j, int cnt)
{
    for (int i = 0; i < n; i++)
    {
        if (S[i][j] == 0)
        {
            if (i + 1 >= 0)
            {
                S[i + 1][j] = 1;
            }
            if (i - 1 >= 0)
            {
                S[i - 1][j] = 1;
            }
            if (j + 1 >= 0)
            {
                S[i][j + 1] = 1;
            }
            if (j - 1 >= 0)
            {
                S[i][j - 1] = 1;
            }
            backtrack(S, n, j+1, cnt + 1);
            backtrack(S, n, j+1, cnt);
        }
    }
}
int main()
{
    int n, m, q, cnt = 0;
    cin >> n >> m >> q;
    int S[n][m] = {0};
    int *A[n];
    *A = S[0];
    for (int i = 0; i < q; i++)
    {
        int r, c;
        cin >> r >> c;
        S[r][c] = 1;
    }
    backtrack(A, n, 0, cnt);
    cout << cnt;
}