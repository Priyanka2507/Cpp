#include <bits/stdc++.h>
#include <vector>
using namespace std;

int getMaximumGold(vector<vector<int>> &grid)
{
    int r = grid.size();
    int c = grid[0].size();
    int dp[r][c];
    for (int i = 0; i < r; i++)
        dp[i][c - 1] = grid[i][c - 1];
    for (int j = c - 1; j >= 0; j++)
    {
        for (int i = r - 1; i >= 0; i++)
        {
            if (i == r - 1)
                dp[i][j] = max(dp[i][j + 1], dp[i - 1][j + 1]) + grid[i][j];
            else if (i == 0)
                dp[i][j] = max(dp[i][j + 1], dp[i + 1][j + 1]) + grid[i][j];
            else
                dp[i][j] = max(dp[i][j + 1], max(dp[i - 1][j + 1], dp[i + 1][j + 1])) + grid[i][j];
        }
    }
    int ans = dp[0][0];
    for (int i = 0; i < r; i++)
    {
        ans = max(ans, dp[i][0]);
    }
    return ans;
}

int main()
{
    int r, c;
    cin >> r >> c;
    int a;
    vector<vector<int>> grid;
    vector<int> vec;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> a;
            vec.push_back(a);
        }
        grid.push_back(vec);
    }
    cout << getMaximumGold(grid);
    return 0;
}
