#include <bits/stdc++.h>
#include <vector>
using namespace std;

void backtrack(int *arr, int n, vector<string> &ans, string str, string *hash, int mx, int i)
{
    if (str.length() == mx)
    {
        ans.push_back(str);
    }
    for (int x = 0; x < n; x++)
    {
        str += hash[arr[x]][i];
        backtrack(arr, n, ans, str, hash, mx, i + 1);
    }
    return;
}

int main()
{
    int arr[100], n;
    vector<string> ans;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    string hash[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    backtrack(arr, n, ans, "", hash, n, 0);
    for (auto i : ans)
    {
        cout << i << endl;
    }
    return 0;
}