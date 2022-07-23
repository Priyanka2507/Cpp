#include<iostream>
using namespace std;

class node{
    public:
    int d;
    node *ptr;

    node(int data){
        d = data;
        ptr = NULL;
    }
};

void insert_back(node*&head , int data){
    if(head == NULL){
        head = new node(data);
        return;
    }
    node *n = new node(data);
    node *temp = head;
    while(temp->ptr!=NULL){
        temp = temp->ptr;
    }
    temp ->ptr = n;
    n->ptr = NULL;
    return;

}

void show(node* head){
    node *temp = head;
    while(temp->ptr != NULL){
        cout<<temp->d<<"  ";
        temp = temp->ptr;
    }
    cout<<temp->d;
    return;
}

void find_mp(node*&head){
    if(head ==NULL || head->ptr == NULL){
        cout<<head->d;
        return ;
    }

    node* a = head;
    node* b = head->ptr;

    while(b!=NULL && b->ptr!=NULL){
        b = (b->ptr)->ptr;
        a = a->ptr;
    }
    cout<<a->d;
}

int main(){
    node *head = NULL;
    int data;
    char ans = 'y';
    cout<<"Enter list data : "<<endl;
    while(ans == 'y'){
        cin>>data;
        insert_back(head,data);
        cout<<"\nEnter 'y' if you want to enter more elements : ";
        cin>>ans;
    }

    cout<<"This is list you made : "<<endl;
    show(head);
    cout<<"\n";
    cout<<"Mid point Data: "<<endl;
    find_mp(head);

    return 0;
}