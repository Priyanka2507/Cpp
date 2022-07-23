#include<iostream>
using namespace std;

class num{
    int n; 
    static int cnt;  //static member variable
    public:
    num(){
        cnt++;
        n = cnt;
    }
    int getdata(){
        return n;
    }
};

void swap(int a , int b){
    int temp = a;
    a=b;
    b=temp;
}

int num :: cnt = 0;

int main(){
    int x =0;
    cout<<"Enter number of elements : ";
    cin>>x;
    num a[x];
    int i=0;
    for(i=0;i<x;i++){
        cout<<a[i].getdata()<<" ";
    }
    for(i=0;i<x;i+=2){
        swap(a[i],a[i+1]);
    }
    cout<<"\n";
    for(i=0;i<x;i++){
        cout<<a[i].getdata()<<" ";
    }
    return 0;
}
