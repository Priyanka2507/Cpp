#include<bits/stdc++.h>
using namespace std;

class item{
    char name[20];
    const int price; //const variable
    public:
    item(int x):price(x){
        cout<<"\nConstructor";
    } 
    void setdata(){
        cin>>name;
    }

    int getdata() const { //const function
        cout<<"\nreturning price";
        return price;
    } 
    void printdata(){
        cout<<"\nprice:"<<price;
        cout<<"\nname:"<<name;
    }
};

int main(){

    const int* a; //pointer to const 
    int b = 10; 
    int* const w = &b; // const pointer
    item i1(30);
    const item i2(40); //const class object 
    i1.setdata();
    i1.printdata();

    return 0;
}