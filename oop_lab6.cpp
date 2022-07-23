#include<bits/stdc++.h>
using namespace std;

class student{
    int rollno ;
    int marks;
    static int count; //static data member

    public:
      
    student(){     //default constructor
        cout<<"\nDefault Constructor";
    }
    void getdata(){
        cin>>rollno;
        cin>>marks;
    }
    void count_object(){
        count++;
    }

    void printdata(){
        cout<<"\n Roll No. : "<<rollno;
        cout<<"\n Marks : "<<marks;
    }

    static void show_count(){ // non static member function
        cout<<"Objects Created : "<<count<<endl;
    }

};
int student :: count =0;

int main()
{
    student s1;
    s1.getdata();
    s1.count_object();
    student s2;
    s2.getdata();
    s2.count_object();
    student s3;
    s3.getdata();
    s3.count_object();

    s1.printdata();
    s2.printdata();
    s3.printdata();

    student::show_count(); //calling static member function
    return 0;
}