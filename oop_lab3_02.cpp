#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class student{
    char name[20];
    int age;
    int marks;
    char group;
    char grade;
    char status;
    public:

    void getdata(){
        cout<<"Enter name :";
        gets(name);
        cout<<"\nEnter marks : ";
        cin>>marks;
        cout<<"\nEnter age :";
        cin>>age;
    }
    void alot_group(){
        if('A'<=name[0]<='M'){
            group = 'A';
        }
        else
        {
            group = 'B';
        }
        
    }

    void alot_grade(){
        if(marks>=90)
            grade = 'O';
        else 
        if(80<=marks<=89)
            grade = 'A';
        else 
        if(70<=marks<=79)
            grade = 'B';
        else
        if(60<=marks<=69)
            grade= 'C';
        else
        if(50<=marks<=59)
            grade = 'D';
        else 
        if(33<=marks<=49)
            grade = 'P';
        else 
        if(marks<33)
            grade = 'F';

    }

    void update_status(){
        if(age>=18)
            status = 'E';
        else
            status = 'N';
    }

    void printdata(){
        // assigning  grade
        alot_grade();
        // Assigning  group
        alot_group();
        //Updating Status
        update_status();
        cout<<"\nName :";
        puts(name);
        cout<<"\nMarks : "<<marks;
        cout<<"\nAge :"<<age;
        cout<<"\nGroup :"<<group;
        cout<<"\nGrade : "<<grade;
        cout<<"\nStatus : "<<status;

    }
};

int main(){
    student s1;
    s1.getdata();
    s1.printdata();

    return 0;
}