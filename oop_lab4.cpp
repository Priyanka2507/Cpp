#include<bits/stdc++.h>
#include<string>
using namespace std;


class car{
    int model_no;
    char name[20];
    int price;
    int insurance;

    public:
    
    int cal_insurance(){
        insurance = price * 0.010;
        return insurance;
    }
    void getdata(){
        cout<<"\nEnter Model no. : ";
        cin>>model_no;
        cout<<"\nEnter Name : ";
        cin>>name;
        cout<<"\nEnter price : ";
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
    
    int cal_discount(){
        discount = amount * 0.10;
        return discount;
    }

    void getdata(){
        cout<<"\nEnter Policy no. : ";
        cin>>policy_no;
        cout<<"\nEnter Name of policy : ";
        cin>>name_policy;
        cout<<"\nEnter amount to be paid : ";
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

class service_station{
    char name[20];
    char location[10];
    int bill;
    int discount;

    public:

    void getdata(){
        cout<<"\n Enter service station name : ";
        cin>>name;
        cout<<"\n Enter location : ";
        cin>>location;
        cout<<"\n Enter Average bill amount : ";
        cin>>bill;
    }
    int cal_dis(){
        discount = bill*0.1;
        return discount;
    }
    void printdata(){
        cal_dis();
        cout<<"\n Name : "<<name;
        cout<<"\n Location : "<<location;
        cout<<"\n Average bill amount : "<<bill;
        cout<<"\n Discount"<<discount; 
    }
};

class person_data{

    int car_ins;
    int ins_discount;
    int service_amt;
    int exp;

    public:
    void cal_exp(car c1,insurance_policy i1 , service_station s1){
        car_ins = c1.cal_insurance();
        ins_discount = i1.cal_discount();
        service_amt = s1.cal_dis();

        exp = car_ins + ins_discount + service_amt;
    }
    void printdata(){
        cout<<"\n Total expenditure : "<<exp;
    }


};

int main(){

    car c1;
    insurance_policy i1;
    service_station s1;
    person_data p;

    c1.getdata();
    s1.getdata();
    i1.getdata();
    c1.printdata();
    s1.printdata();
    i1.printdata();

    p.cal_exp(c1,i1,s1);
    p.printdata();


    return 0;
}