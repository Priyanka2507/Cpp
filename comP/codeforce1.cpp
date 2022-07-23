#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, n, a, ans=0, r;
    cin >> t;
    while (t--)
    {
        cin >> n;
        while (a)
        {
            r = a % 10;
            a = a / 10;
            if (a != 0)
            {
                ans += 9;
            }
            if (r > a)
            {
                ans += a;
            }
            else
            {
                ans += a - 1;
            }
        }
        cout << ans << endl;
    }
}
