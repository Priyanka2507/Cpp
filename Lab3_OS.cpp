#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, arr[100], exec[100], no[100];
    cout << "Enter number of Processes: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Arrival Time of process " << i << ": ";
        cin >> arr[i];
        cout << "Execution Time of process " << i << ": ";
        cin >> exec[i];
        no[i] = i;
    }
    int t = 0;
    int turn[100], wait[100];
    float total_wait = 0, total_turn = 0;
    for (int i = 0; i < n; i++)
    {
        wait[i] = t - arr[i];
        t += exec[i];
        turn[i] = t;
        total_wait += wait[i];
        total_turn += turn[i];
        int idx = i + 1;
        while (arr[idx] <= t && idx < n)
        {
            idx++;
        }
        for (int j = i + 1; j < idx - 1; j++)
        {
            for (int k = i + 1; k < idx - 1; k++)
            {
                if (exec[k] > exec[k + 1])
                {
                    swap(exec[k], exec[k + 1]);
                    swap(arr[k], arr[k + 1]);
                    swap(no[k], no[k + 1]);
                }
            }
        }
    }
    cout << "\nPN\t|AT\t|ET\t|TT\t|WT\n";
    for (int i = 0; i < n; i++)
    {
        cout << no[i] << "\t|" << arr[i] << "\t|" << exec[i] << "\t|" << turn[i] << "\t|" << wait[i] << "\n";
    }
    cout << "\nAverage Waiting time: " << (total_wait / n);
    cout << "\nAverage Turn-Around time:" << (total_turn / n) << "\n";
}
