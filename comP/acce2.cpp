#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

bool pr[1000005];
void isPrime(int R)
{   
    memset(pr, true, sizeof(pr));
    for (int p = 2; p * p <= R; p++)
    {
        if (pr[p] == true)
        {
            for (int i = p * p; i <= R; i += p)
            {
                pr[i] = false;
            }
        }
    }
}
vector<int> divisors(int n)
{   
    vector<int> v;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (n / i == i)
            {
                v.push_back(i);
            }
            else
            {
                v.push_back(i);
                v.push_back(n / i);
            }
        }
    }
    return v;
}

long long int strange_sum(int L, int R)
{
    // Write your code here
    isPrime(R);
    long long int ans[R] = {0};
    long long int f[R] = {0};
    for (int i = 2; i <= R; i++)
    {
        if (pr[i] == true)
        {
            ans[i] = 1;
            f[i] = 1;
        }
        else
        {
            ans[i] = 0;
            vector<int> v = divisors(i);
            for (int j = 0; j < v.size(); j++)
            {
                if(v[j]!=i)
                    ans[i] += f[v[j]];
            }
            f[i] = v[2]*f[i/v[2]]+(i/v[2])*f[v[2]];
            ans[i] += f[i] ;
        }
    }
    long long int res;
    for(int i=L;i<=R;i++){
        res +=ans[i];
    }
    return res;
}

int main(){
    int l,r;
    cin>>l>>r;
    cout<<strange_sum(l,r);
}

