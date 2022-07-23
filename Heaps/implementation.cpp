#include <bits/stdc++.h>
using namespace std;

class heap
{
public:
    vector<int> h;
    int hSize;
    int size()
    {
        return h.size();
    }
    int parent(int i)
    {
        return (i - 1) / 2;
    }
    int leftChild(int i)
    {
        return 2 * i + 1;
    }
    int rightChild(int i)
    {
        return 2 * i + 2;
    }
    int top()
    {
        if (size() != 0)
            return h[0];
        else
            return -1;
    }
    void display()
    {
        int i = 0;
        while (i < size())
        {
            cout << h[i] << " ,";
            i++;
        }
    }
    void max_heapify(int i)
    {
        // space and time complexity : O(logn)
        int largest = i;
        int l = leftChild(i);
        int r = rightChild(i);
        if (l < size() && h[l] > h[i])
            largest = l;
        if (r < size() && h[r] > h[largest])
            largest = r;
        if (largest != i)
        {
            int a = h[largest];
            h[largest] = h[i];
            h[i] = a;
            max_heapify(largest);
        }
    }
    void build_max_heap(vector<int> arr)
    {
        // space : O(logn) time : O(n)
        for (auto i : arr)
        {
            h.push_back(i);
        }
        int n = size();
        n = (n / 2) - 1;
        for (int i = n; i >= 0; i--)
        {
            max_heapify(i);
        }
    }
    int extract_max()
    {
        // remove max and heapify
        // space and time : O(logn)
        int maxEl = top();
        h[0] = h[size() - 1];
        h.pop_back();
        max_heapify(0);
        return maxEl;
    }
    void incKey(int value, int i)
    {
        // increase value of a node
        // update and percolate up till parent > child || node becomes root
        // time :O(logn) space : O(1)
        if (value < h[i])
            cout << "\nWrong Operation\n";
        else
        {
            h[i] = value;
            while (i > 0 && h[i] > h[parent(i)])
            {
                int a = h[i];
                h[i] = h[parent(i)];
                h[parent(i)] = a;
                i = parent(i);
            }
        }
    }
    void decKey(int value, int i)
    {
        // update value and max_heapify // percolate down
        // time : O(logn) space : O(logn)
        if (h[i] < value)
            cout << "\n Wrong Operation\n";
        else
        {
            h[i] = value;
            max_heapify(i);
        }
    }
    void insert(int val)
    {
        // time :O(logn) space : O(1)
        h.push_back(val);
        int i = size();
        while (i > 0 && h[i] > h[parent(i)])
        {
            int a = h[i];
            h[i] = h[parent(i)];
            h[parent(i)] = a;
            i = parent(i);
        }
    }
    void delKey(int i)
    {
        // swap with last element and heapify
        // time and space : O(logn)
        if (size() == 0)
        {
            cout << "\nEmpty Heap\n";
            return;
        }
        int a = h[i];
        h[i] = h[size() - 1];
        h[size() - 1] = a;
        h.pop_back();
        max_heapify(i);
    }
};

void heapify(int i, vector<int> &h, int n)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && h[l] > h[i])
        largest = l;
    if (r < n && h[r] > h[largest])
        largest = r;
    if (largest != i)
    {
        int a = h[largest];
        h[largest] = h[i];
        h[i] = a;
        heapify(largest, h, n);
    }
}
void heapSort(vector<int> &arr)
{
    // time : O(nlogn) space : O(logn)
    // swap h[0](max el) and last , reduce size by 1 and heapify
    int n = arr.size();
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        // O(n)
        heapify(i, arr, n);
    }
    // O(nlogn)
    for (int i = n - 1; i > 0; --i) // O(n)
    {
        // O(logn)
        int a = arr[0];
        arr[0] = arr[i];
        arr[i] = a;
        heapify(0, arr, i);
    }

    // To find Kth largest or smallest element
    // Use heaps complexity : O(n + klogn) : n for build heap
    // klogn : pop k elements and heapify each time
}

int main()
{
    heap h;
    vector<int> arr = {10, 0, 3, 5, 2, 1, 7, 4, 9, 8, 6};
    h.build_max_heap(arr);
    h.display();
    h.insert(22);
    cout << "\n";
    h.display();

    // heapSort(arr);
    // for (auto i : arr)
    // {
    //     cout << i << " , ";
    // }
    return 0;
}