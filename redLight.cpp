#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<string, int> mp;
    mp["Yellow"] = 2;
    mp["Green"] = 4;
    mp["Red"] = 6;
    while (true)
    {
        for (auto i : mp)
        {
            string key = i.first;
            int j = 0;
            while (j < i.second)
            {
                cout << key << endl;
                j++;
            }
        }
    }
    return 0;
}