#include <bits/stdc++.h>
using namespace std;

// finding Longest common subsequence : relative order should be same
// 1+prev : if same else max of either n-1,m or n,m-1

int lcs(string s1, string s2)
{
    int n = s1.length();
    int m = s2.length();
    int dp[n + 1][m + 1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i] == s2[j])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][m];
}

int main()
{
    string s1, s2;
    cout << "Enter 2 strings : ";
    cin >> s1 >> s2;
    cout << lcs(s1, s2);
    return 0;
}