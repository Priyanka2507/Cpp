#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <vector>
using namespace std;

int solve(int l, int r, int x)
{

    int ans = 0, v1 = 0, v2 = 0;
   long long  int t1 = 0, t2 = 0;
    //vector<int> t1 = findt1(r);
    for (int i = l; i <= r; i++)
    {
        t1 = pow(2, ceil(log(i) / log(2)));
        if ((i % x) == 0)
        {
            t2 = (i / x) * x;
        }
        else
        {
            t2 = ((i / x) + 1) * x;
        }
        if (t1 < t2)
        {
            v1++;
        }
        if (t1 > t2)
        {
            v2++;
        }
    }
    if (v1 > v2)
    {
        ans = 1;
    }
    else if (v2 > v1)
    {
        ans = 2;
    }
    return ans;
}

int main()
{
    int t, l, r, x = 0;
    cin >> t;
    while (t--)
    {
        cin >> l >> r >> x;
        cout << solve(l, r, x);
    }
    return 0;
}
