#include <bits/stdc++.h>
using namespace std;

// Printing all LCS

void printlcs(string s1, string s2)
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
}

int main()
{
    string s1, s2;
    cout << "Enter 2 strings : ";
    cin >> s1 >> s2;
    printlcs(s1, s2);
    return 0;
}