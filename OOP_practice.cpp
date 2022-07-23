#include<bits/stdc++.h>
using namespace std;

class calculate{
    int n , p;
    long power;
    public:
    void setter(){
        cout<<"\n Enter n : ";
        cin>>n;
        cout<<"\n Enter p : ";
        cin>>p;
    }
    int get_n(){
        return n ;
    }
    int get_p(){
        return p;
    }
    void display(){
        cout<<"\n n^p = "<<power;
    }
    int longPower(){
        try{
            if(p==0 || n==0)
                throw 0;
            else
            if(n< 0 || p<0)
                throw -1;
            else
                power  = pow(n,p);
            display();
        }
        catch(int i){
            if(i==0)
                cout<<"\n n or p should not be zero.";
            if(i==-1)
                cout<<"\n n or p should not be negative";  
        }
    }
};

int main(){
    calculate c1;
    c1.setter();
    c1.longPower();
    return 0;
}