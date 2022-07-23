#include<iostream>
using namespace std;

template <class T>

class calculator{
    T a,b;
    public:
    calculator(T a, T b){
        a = a;
        b = b;
    }
    void add(){
        cout<<"Sum : "<<a+b<<endl;
    }
    void sub(){
        cout<<"Difference : "<<a-b<<endl;
    }
    void divide(){
        cout<<"Division : "<<a/b<<endl;
    }
    void multiply(){
        cout<<"Multiply : "<<a*b<<endl;
    }
};

int main(){
    calculator<int> c1(15,8);
    c1.add();
    c1.divide();
    c1.sub();
    c1.multiply();

    calculator<float> c2(5.6,7.2);
    c2.add();
    c2.divide();
    c2.sub();
    c2.multiply();

    return 0;
}