#include<iostream>
#include<string>
#include<bits/stdc++.h>

using namespace std;

class student{
    char name[20];
    int rollno;
    int marks;
    char p_grade;
    char grade;

    public:
    char collegeid[10];
    int pckg;
    int age;

    void getdata(){
        cout<<"Enter name :";
        cin>>name;
        cout<<"\n Enter roll no. : ";
        cin>>rollno;
        cout<<"\nEnter marks : ";
        cin>>marks;
        cout<<"\nEnter package offered : ";
        cin>>pckg;
        cout<<"\nEnter age :";
        cin>>age;
        cout<<"Enter college id :";
        cin>>collegeid;
    }
    void package_grade(){
        if(pckg > 15){
            p_grade = 'A'; 
        }
        else
        if(10<=pckg <=15){
            p_grade - 'B';
        }        
    }

    void ascii(){
        cout<<name[0];
    }

    void marks_grade(){
        if(marks>=85){
            grade = 'A';

        }
        else
        if(70<=marks<85){
            grade = 'B';
        }
        else 
        if(50<=marks<70){
            grade = 'C';
        }
        
    }
    // Default constructor
    student (){
    name[20] = {0};
    rollno = 0;
    marks = 0;
    pckg = 0;
    age = 0;
    p_grade = 'D';
    grade = 'D';
    collegeid[10] = {0};
    cout<<"Welcome";
    }

    void printdata(){
        // assigning package grade
        package_grade();
        // Assigning marks grade
        marks_grade();
        cout<<"\nname :";
        cout<<name;
        cout<<"\nroll no. : "<<rollno;
        cout<<"\nmarks : "<<marks;
        cout<<"\npackage offered : "<<pckg;
        cout<<"\nage :"<<age;
        cout<<"\ncollege id :"<<collegeid;
        cout<<"\n Grade : "<<grade;
        cout<<"\n Placement grade : "<<p_grade;
        cout<<"\n";

    }


};

class college{
    char name[20];
    char state[10];
    int per_stu_placed;

    public:
    char colg_id[10];
    int sem_fee_btech;

    void getdata(){
        cout<<"\n Enter name of college : ";
        cin>>name;
        cout<<"\n Enter college id : ";
        cin>>colg_id;
        cout<<"\n Enter state : ";
        cin>>state;
        cout<<"\nEnter semester fees  for btech  :";
        cin>>sem_fee_btech;
        cout<<"\nEnter Percentage of students placed : ";
        cin>>per_stu_placed; 
    }

    void remarks_for_collg_print(){
        if(per_stu_placed >=80){
            cout<<"College is good ";

        }
        else 
        cout<<"College is not good";
    }

    // Default constructor
    college(){
    name[20] = {0};
    colg_id[10] = {0};
    state[10] = {0};
    sem_fee_btech = 0;
    per_stu_placed = 0;
    }

    void printdata(){
        cout<<"\nname of college : "<<name;
        cout<<"\ncollege id : "<<colg_id;
        cout<<"\nstate : "<<state;
        cout<<"\nSemester fees  for btech  :";
        cout<<sem_fee_btech;
        cout<<"\nPercentage of students placed : ";
        cout<<per_stu_placed; 
        cout<<"\n";

    }

};

int tax(int pckg , int age , int fee){
    int tax =0;
    tax = ((pckg/age) - (fee*8));
    return tax;
}



int main(){

    student s1;
    student s2;
    college c1;
    college c2;
    int tax1 , tax2 =0;

    s1.getdata();
    s1.ascii();
    s1.printdata();

    c1.getdata();
    c1.remarks_for_collg_print();
    c1.printdata();
    if(strcmp(s1.collegeid,c1.colg_id)){
        tax1 = tax(s1.pckg ,s1.age,c1.sem_fee_btech);
        cout<<"\n Tax to be payed by student 1 :"<<tax1;
    }

    s2.getdata();
    s2.ascii();
    s2.printdata();

    c2.getdata();
    c2.remarks_for_collg_print();
    c2.printdata();
    if(strcmp(s2.collegeid,c2.colg_id)){
        tax2 = tax(s2.pckg ,s2.age,c2.sem_fee_btech);
        cout<<"\n Tax to be payed by student 2 : "<<tax2;
    }

    return 0;
}