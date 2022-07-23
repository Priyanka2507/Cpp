#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, art[100], exec[100];
    cout << "Enter Number of Processes: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Arrival Time of process " << i << ": ";
        cin >> art[i];
        cout << "Execution Time of process " << i << ": ";
        cin >> exec[i];
    }
    int t = 0;
    int turn[100], wait[100];
    float total_wait = 0, total_turn = 0;
    for (int i = 0; i < n; i++)
    {
        wait[i] = t - art[i];
        t += exec[i];
        turn[i] = t;
        total_wait += wait[i];
        total_turn += turn[i];
    }
    cout << "\nPN\t|AT\t|ET\t|TT\t|WT\n";

    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << "\t" << art[i] << "\t" << exec[i] << "\t" << turn[i] << "\t" << wait[i] << "\n";
    }
    cout << "\nAverage Waiting time " << (total_wait / n);
    cout << "\nAverage Turn-Around time:" << (total_turn / n) << "\n";
}
