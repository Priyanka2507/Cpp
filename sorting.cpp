#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void insertion(int arr[],int n){
    for(int i=1;i<n;i++){
        int j = i-1;
        int key = arr[i];
        while(arr[j]> key && j>=0){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void selection(int arr[] ,int n){
    for(int i=0;i<n;i++){
        int minE = INT_MAX, minIdx = 0 ;
        for(int j=i+1;j<n;j++){
            if(arr[j]<minE){
                minE = arr[j];
                minIdx = j;
            }
            if(arr[i]>arr[minIdx])
                swap(arr[i],arr[minIdx]);
        }
    }
}

void bubble(int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j])
                swap(arr[i],arr[j]);
        }
    }
}

void merge(int arr[],int s,int mid,int e){
    int sortedArr[e-s+1];
    int i=s,j=mid+1,k=0;
    while(i<=mid && j<=e){
        if(arr[i] < arr[j]){
            sortedArr[k++] = arr[i++];
        }else{
            sortedArr[k++] = arr[j++];
        }
    }
    while(i<=mid){
        sortedArr[k++] = arr[i++];
    }
    while(j<=e){
        sortedArr[k++] = arr[j++];
    }
    for(int l=s;l<=e;l++){
        arr[l] = sortedArr[l-s];
    }
}

void mergeSort(int arr[],int s,int e){
    if(s >= e)
        return;
    int mid = (s+e)/2;
    mergeSort(arr,s,mid);
    mergeSort(arr,mid+1,e);
    merge(arr,s,mid,e);
}

int partition(int arr[],int s,int e){
    int rnd = rand()%(e-s+1);
    swap(arr[s+rnd],arr[e]);
    int pivot = arr[e];
    int i=s,j=e;
    while(i<j){
        while(arr[i]<=pivot && i<e) i++;
        while(arr[j]>=pivot && j>s) j--;
        if(i<j) swap(arr[i],arr[j]);
    }
    swap(arr[i],arr[e]);
    return i;
}
void quickSort(int arr[],int s,int e){
    if(s>=e) return;
    int pi = partition(arr,s,e);
    quickSort(arr,s,pi-1);
    quickSort(arr,pi+1,e);
}

void maxHeapify(int arr[],int i,int n)
    {
        int l = 2*i+1;
        int r = 2*i+2;
        int largest = i;
        if (l <= n && arr[l] > arr[i])
            largest = l;
        if (r <= n && arr[r] > arr[largest])
            largest = r;

        if (largest != i)
        {
            swap(arr[i], arr[largest]);
            maxHeapify(arr,largest,n);
        }
    }
    void buildHeap(int arr[],int n)
    {
        for (int i = (n / 2 - 1); i >= 0; i--)
        {
            maxHeapify(arr,i,n);
        }
    }
    void heapSort(int arr[],int n)
    {
        buildHeap(arr,n);
        for (int i = n - 1; i >= 0; i--)
        {
            swap(arr[i], arr[0]);
            maxHeapify(arr,0,i-1);
        }
    }

int main() {
    int n=0;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    heapSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" , ";
    }
    cout<<endl;
    cout<<"Hello World!";
}
