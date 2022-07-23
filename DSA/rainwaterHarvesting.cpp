#include <bits/stdc++.h>
using namespace std;

int main()
{
    int ans = 0, n, a[100];
    cin >> n;
    // for(int i=0;i<n;i++){
    //     cin>>a[i];
    // }
    int count = 0;
    for (int i = n; i > 0; i /= 2)
    {
        for (int j = 0; j < i; j++)
        {
            count += 1;
            cout << count;
        }
        cout << endl;
    }
    cout << ans << endl;
    return 0;
}