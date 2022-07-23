#include<bits/stdc++.h>
using namespace std;

// using hashmaps

void sort012(int a[], int n)
{
    // coode here 
    int h[3]={0};
    int i,j=0,k=0;
    for( i=0 ;i<n;i++){
        h[a[i]]++;
    }
    for(i=0;i<h[0];i++){
        a[i]=0;
    }
    while(k<h[1]){
        a[i]=1;
        i++;
        k++;
    }
    while(j<h[2]){
        a[i]=2;
        i++;
        j++;
    }
}


// using 3 variables low , mid , high
void sort012(int a[], int n)
{
    int low = 0, high = n-1, mid = 0;

    while(mid <= high){

        if(a[mid]==0)
            swap(a[mid++], a[low++]);
       
        else if(a[mid]==1)
             mid++;

        else
            swap(a[mid], a[high--]);
    }
}