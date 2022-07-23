#include<bits/stdc++.h>
using namespace std;

class society;
class containment;
class zone{
    int z_num;
    string z_name;
    int num_of_cases_registered;
    string status;
    public : 
    void setdata(){
        cout<<"Enter Zone number " << endl;
        cin>>z_num;
        cout<<"Enter Zone name " << endl;
        cin>>z_name;
        cout<<"Enter number of cases registered";
        cin>>num_of_cases_registered;
    }
    void alot_status(){
        if(num_of_cases_registered<=20)
            status = "Green";
        else
        if(20<num_of_cases_registered<=60)
            status = "Orange";
        else
        if(num_of_cases_registered > 60)
            status = "Red";       
    }

    void printdata(){
        cout<<"Zone Details "<<endl;
        cout<<"Zone Name : "<<z_name<<endl;
        cout<<"Zone No : "<<z_num<<endl;
        cout<<"Zone status : "<<status<<endl;
        cout<<"No of cases Registered : "<<num_of_cases_registered<<endl;
    }

    friend void check_status(zone , society);
    friend class containment;

};

class containment{
    int budget;
    int tests_conducted;
    string start_date;
    string tentative_end_date;
    public : 
    void setdata(){
        cout<<"\tNumber of Tests Conducted : ";
        cin>> tests_conducted;
        cout<<"\tStart Date : ";
        cin>>start_date;
        cout<<"\tTentative End Date: ";
        cin>>tentative_end_date;
    }

    void cal_budget(zone z){
        budget =  z.num_of_cases_registered * 15000; 
    }

    void show_details()
    {
        cout<<"Containment Details : "<<endl;
        cout<<"Start Date : "<<start_date<<" "<<"End Date : "<<tentative_end_date<<endl;
        cout<<"Budget : "<<budget<<endl;
        cout<<"Tests Conducted : "<<tests_conducted<<endl;
    }

    void print(society &s);
};

class society{
    string name;
    int id;
    int z_num_of_soc;
    int num_flats;
    int num_affected_flats;
    public :
    void setdata(){
        cout<<"Enter name of society " <<endl;
        cin>>name;
        cout<<"Enter id "<<endl;
        cin>>id;
        cout<<"Enter Zone number of society "<<endl;
        cin>>z_num_of_soc; 
        cout<<"Enter total number of flats "<<endl;
        cin>>num_flats;
        cout<<"Enter no. of affected flats "<<endl;
        cin>>num_affected_flats;
    }

    void cal_ratio(){
        float ratio;
        ratio = num_flats/num_affected_flats; 
        cout<< "Ratio : " << ratio <<endl;
    }

    friend void check_status(zone , society);
    friend void containment::print(society& S);  
};

void check_status(zone z , society s){
    int ans = s.num_affected_flats * 3 ;
    if(ans < (1/8*z.num_of_cases_registered))
        cout<<"Society is safe"<<endl;
    else 
        cout<<"Society is unsafe"<<endl;
}

void containment::print(society& S){
    cout<<"Society Details"<<endl;
    cout<<"Society Name :"<<S.name<<endl;
    cout<<"Society Id : "<<S.id<<endl;
    cout<<"Total No of Flats in Society : "<<S.num_flats<<endl;
    cout<<"Total No of Flats Affected in Society : "<<S.num_affected_flats<<endl;
}

int main(){
    zone z1;
    z1.setdata();
    z1.alot_status();
    society s1;
    s1.setdata();
    s1.cal_ratio();
    containment c1;
    c1.setdata();
    c1.cal_budget(z1);

    cout<<"Details : "<<endl;
    z1.printdata();
    c1.print(s1);
    c1.show_details();


    cout<<"Check Status";
    check_status(z1,s1);
    return 0;
}