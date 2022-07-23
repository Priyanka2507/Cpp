#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int s, int e)
{
    // Your code here
    int pivot = arr[s];
    int p = s;
    int q = e;
    while (p < q)
    {
        while (arr[p] <= pivot && p < q)
            p++;
        while (arr[q] >= pivot && p < q)
            q--;
        if (p < q)
            swap(arr[p], arr[q]);
    }
    swap(pivot, arr[p]);
    return p;
}

void quickSort(int arr[], int s, int e)
{
    // code here
    int pi = partition(arr, s, e);
    quickSort(arr, s, pi);
    quickSort(arr, pi + 1, e);
}
int main()
{
    int arr[8] = {2, 4, 5, 1, 8, 3, 9, 0};
    quickSort(arr, 0, 7);
    for (auto i : arr)
    {
        cout << i << " , ";
    }
    return 0;
}