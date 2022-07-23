#include<bits/stdc++.h>
#include<string>
using namespace std;


class car{
    int model_no;
    char name[20];
    int price;
    int insurance;

    public:
    
    void cal_insurance(){
        insurance = price * 0.010;
    }
    void getdata(){
        cout<<"Enter Model no. : ";
        cin>>model_no;
        cout<<"Enter Name : ";
        cin>>name;
        cout<<"Enter price : ";
        cin>>price;
    }

    void printdata(){
        // Calculating insurance
        cal_insurance();
        cout<<" \n Model NO. : "<<model_no;
        cout<<" \n Name : "<<name;
        cout<<"\n Price : "<<price;
        cout<<" \n Insurance : "<<insurance;
        cout<<"\n";

    }
};


class insurance_policy {
    int policy_no;
    char name_policy[20];
    int amount;
    int discount;

    public:
    
    void cal_discount(){
        discount = amount * 0.10;
    }

    void getdata(){
        cout<<"Enter Policy no. : ";
        cin>>policy_no;
        cout<<"Enter Name of policy : ";
        cin>>name_policy;
        cout<<"Enter amount to be paid : ";
        cin>>amount;
    }

    void printdata(){
        // Calculating Discount
        cal_discount();
        cout<<"\n Policy No. : "<<policy_no;
        cout<<"\n Name of Policy : ";
        puts(name_policy);
        cout<<" \n Amount to be paid : "<<amount;
        cout<<"\n Discount : "<<discount;
        cout<<"\n";
    }
};

int main(){

    car c1;
    car c2;
    insurance_policy i1;
    insurance_policy i2;
    c1.getdata();
    c1.printdata();
    c2.getdata();
    c2.printdata();

    i1.getdata();
    i1.printdata();
    i2.getdata();
    i2.printdata();


    return 0;
}