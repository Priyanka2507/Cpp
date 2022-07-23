#include <bits/stdc++.h>
using namespace std;

void getStair(int n, string path)
{
    if (n < 0)
        return;
    if (n == 0)
    {
        cout << path << endl;
        return;
    }
    getStair(n - 1, path + "1");
    getStair(n - 2, path + "2");
    getStair(n - 3, path + "3");
    return;
}

int main()
{
    int n;
    cin >> n;
    getStair(n, "");
    return 0;
}