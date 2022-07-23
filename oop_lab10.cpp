#include<iostream>
using namespace std;

class person{
    protected:   //Protected members of class can be accessed by class members or derived class members
    char name;
    public:
    void setdata(){
        cout<<"\nEnter name: ";
        cin>>name;
    }
    void display(){
        cout<<"\n Name";
        cout<<name;
    }
};

class student:virtual protected person{  // protected mode_of_visibility : public and protected members of base class to protected of derived class 
    int roll;
    public:
    void setdata(){
        cout<<"\n Enter roll number : ";
        cin>>roll;
    }
    void display(){
        cout<<"\n Roll number : ";
        cout<<roll;
    }
};

class employee:virtual private person{  //private mode_of_visibility : public and protected members of base class to private of derived class 
    int id; 
    public:
    void setdata(){
        cout<<"\n Enter id : ";
        cin>>id;
    }
    void display(){
        cout<<"\n Id : ";
        cout<<id;
    }
};

class college_student:public student{  //public mode_of_visibility : public members to public of derived class and protected to protected of derived class
    int college_roll;
    public:
    void setdata(){
        cout<<"\n Enter college roll no : ";
        cin>>college_roll;
    }
    void display(){
        cout<<"\n College roll no : ";
        cout<<college_roll;
    }
};

class college_emp:public employee{
    int college_id;
    public:
    void setdata(){
        cout<<"\n Enter college id : ";
        cin>>college_id;
    }
    void display(){
        cout<<"\n College Id : ";
        cout<<college_id;
    }
};

class college_people:public college_student , public college_emp{
    int num;
    public:
    void setdata(){
        cout<<"\n Enter num : ";
        cin>>num;
    }
    void display(){
        cout<<"\n Num : "; 
        cout<<num;
    }
};

int main(){
    college_people c1;
    c1.setdata();
    c1.college_student::setdata();
    c1.college_emp::setdata();
    c1.student::setdata();
    c1.employee::setdata();

    c1.college_student::display();
    c1.college_emp::display();
    c1.student::display();
    c1.employee::display();
}