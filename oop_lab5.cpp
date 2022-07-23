#include<bits/stdc++.h>
using namespace std;

class student{
    int rollno ;
    int marks;
    float percentage;

    public:
    //default constructor
    student(){
        cout<<"\nDefault Constructor";
        rollno = 0;
        marks = 0;
        percentage = 0;
    }
    //Copy Constructor
    student(const student &s1){
        cout<<"\nCopy Constructor";
        rollno = s1.rollno;
        marks = s1.marks;
    }
    //Parameterized Constructor
    student(int r , int m){
        cout<<"\nParamerterized Constructor";
        rollno = r;
        marks = m;
    }
    //Overloading Parameterized constructor
    student(int m){
        cout<<"\nOverloading Parameterized constructor";
        marks = m;
        percentage = (m/50)*100;
    }

    void printdata(){
        cout<<"\n Roll No. : "<<rollno;
        cout<<"\n Marks : "<<marks;
        cout<<"\n Percentage : "<<percentage;
    }

    ~student(){
        cout<<"\nDestructor";
    }

};

int main(){
    student s1;
    student s3(99,45);
    student s2(s3);
    student s4(42);
    s1.printdata();
    s2.printdata();
    s3.printdata();
    s4.printdata();
    return 0;
}