#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class car{
    char brand[10];
    int price;
    static int modelNo;    //static data member
    public:
    car(){                //constructor
        cout<<"\n Default Constructor";              
        price = 0;
        modelNo++;        // increment static  data member
    }
    void setData(){
        cout<<"\nEnter name : ";
        cin>>brand;
        cout<<"\nEnter price : ";
        cin>>price;
    }
    int getPrice(){
        return price;
    }
    static int getModelNo(){  //static member function
        return modelNo;                 
    }
    ~car(){
        cout<<"\nDestructor";
    }
};

int car :: modelNo = 0;       // Initialise static data member

static void staticFun(){       //static function
    cout<<"\nStatic Function";
}

int main(){

    car c1;
    c1.setData();
    cout<<"\nPrice : ";
    cout<<c1.getPrice();
    cout<<"\n Model Number :";
    cout<<c1.getModelNo();      //Accessing static function using object


    car c2;
    c2.setData();
    cout<<"\nPrice : ";
    cout<<c2.getPrice();
    cout<<"\n Model Number :"; 
    cout<<c2.getModelNo();      //Accessing static function using object

    static car c3;              //Static class object 
    c3.setData();
    cout<<"\nPrice : ";
    cout<<c3.getPrice();
    cout<<"\n Model Number :"; 
    cout<<c3.getModelNo();

    int count = car :: getModelNo();  // static data member value incremented
    cout<<"\n Count : "<<count;

    staticFun();                 //Accessing static function (not a member function)

    return 0;
}