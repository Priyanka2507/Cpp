#include <bits/stdc++.h>
#include <vector>
using namespace std;

void genPar(int n, vector<string> &ans, int open, int close, string str)
{

    if (str.length() == 2 * n)
    {
        ans.push_back(str);
    }
    if (open < n)
    {
        genPar(n, ans, open + 1, close, str + '(');
    }
    if (close < open)
    {
        genPar(n, ans, open, close + 1, str + ')');
    }
    return;
}

int main()
{
    int n;
    cin >> n;
    vector<string> ans;
    genPar(n, ans, 0, 0, "");
    for (auto i : ans)
    {
        cout << i << endl;
    }
    return 0;
}