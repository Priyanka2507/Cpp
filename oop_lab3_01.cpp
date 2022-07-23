#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class employee{
    int age;
    char name[20];
    int empid;
    long salary;
    int exp;
    int bonus;

    public:

    void setdata(){
        cout<<"\n Enter name : ";
        gets(name);
        cout<<"\n Enter age : ";
        cin>>age;
        cout<<" Enter empid : ";
        cin>>empid;
        cout<<"\n Enter salary : ";
        cin>>salary;
        cout<<"\n Enter experience : ";
        cin>>exp;
    }
    void printdata(){
        puts(name);
        cout<<"\n Age"<<age;
        cout<<"\n EmpID"<<empid;
        cout<<"\n Salary"<<salary;
        cout<<"\n Experience"<<exp;
    }

    void assign_bonus(){
        bonus = exp*2000;
    }
    void print_bonus(){
        cout<<"\n Bonus : "<<bonus;
    }
};

int main(){

    employee e1;
    e1.setdata();
    e1.printdata();
    e1.assign_bonus();
    e1.print_bonus();
    return 0;
}