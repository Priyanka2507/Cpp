#include <bits/stdc++.h>
using namespace std;

class heap
{
    vector<int> h;

public:
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
    int top() // max/min element in heap
    {
        if (size() != 0)
            return h[0];
        else
            return -1;
    }
    void swapNodes(int i, int j)
    {
        int temp = h[i];
        h[i] = h[j];
        h[j] = temp;
        return;
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
    void maxHeapify(int i, int n)
    {
        int l = leftChild(i);
        int r = rightChild(i);
        int largest = i;
        if (l <= n && h[l] > h[i])
            largest = l;
        if (r <= n && h[r] > h[largest])
            largest = r;

        if (largest != i)
        {
            swapNodes(i, largest);
            maxHeapify(largest, n);
        }
    }
    void buildHeap(vector<int> arr)
    {
        for (auto i : arr)
        {
            h.push_back(i);
        }
        for (int i = (h.size() / 2 - 1); i >= 0; i--)
        {
            maxHeapify(i, h.size());
        }
    }
    void heapSort(vector<int> arr)
    {
        buildHeap(arr);
        for (int i = h.size() - 1; i >= 0; i--)
        {
            swapNodes(i, 0);
            maxHeapify(0, i - 1);
        }
    }
};

int main()
{
    heap h;
    int a = 0;
    vector<int> arr;
    while (a != -1)
    {
        cin >> a;
        arr.push_back(a);
    }
    h.heapSort(arr);
    h.display();
    return 0;
}