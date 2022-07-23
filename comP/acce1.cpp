#include<iostream>
#include<vector>
using namespace std;


int main(){
    int n=0;
    cin>>n;
    int b=0;
    vector<int> a;
    for(int i=0;i<n;i++){
        cin>>b;
        a.push_back(b);
    }
    int cnt=0;
    for(int i=1;i<n;i++){
        if(a[i-1]>a[i]){
            a[i] = a[i-1]+1;
            cnt++;
        }
    }
    cout<<cnt;
    }


