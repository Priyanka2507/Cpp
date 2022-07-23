#include<iostream>
using namespace std;

//generate subarrays
int main(){
    int a[10];
    int n;
    cin>>n;
    for(int b = 0;b<n;b++){
        cin>>a[b];
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            for(int k=i;k<=j;k++){
                cout<<a[k]<<" ";
            }
            cout<<",";
        }
        cout<<"\n";
    }
    return 0;
}