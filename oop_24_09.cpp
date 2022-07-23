#include<iostream>
using namespace std;

class student_IT{
    int package;
    public:
    int getdata(){
        return package;
    }
    void setdata(){
        cout<<"\nEnter salary package offered: ";
        cin>>package;
    }
    friend int diff(student_IT &, student_ME &);
};

class student_ME{
    int intern;
    public:
    int getdata(){
        return intern;
    }
    void setdata(){
        cout<<"\n Enter internship offered: ";
        cin>>intern;
    }
    friend int diff(student_IT & , student_ME &);
};

int diff(student_IT &i , student_ME &m){
    int differ = abs(i.package - m.intern);
    return differ;  
}

int main(){
    student_ME me[5];
    student_IT it[5];
    int i,dif=0;
    for( i=0;i<5;i++){
        it[i].setdata();
    }
    for(i=0;i<5;i++){
        me[i].setdata();
    }
    for(i=0;i<5;i++){
        dif = diff(it[i],me[i]);
        cout<<"\ndiffernce : "<<dif;
    }
    return 0;
}