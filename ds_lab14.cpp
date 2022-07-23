#include<iostream>
#include<list>

using namespace std;

class node{
    public : 
    int d;
    struct node* r;
    struct node* l;
    node(int data){
        d = data;
        r = NULL;
        l = NULL;
    }
};

void insert_back(node*&head , int data){
    if(head == NULL){
        head = new node(data);
        return;
    }
    node *n = new node(data);
    node *temp = head;
    while(temp->r!=NULL){
        temp = temp->r;
    }
    n->l = temp;
    n->r = NULL;
    temp->r = n;
    return;

}

void show(node* head){
    node *temp = head;
    while(temp->r != NULL){
        cout<<temp->d<<"  ";
        temp = temp->r;
    }
    cout<<temp->d;
    return;
}

void find_pairs(node*head , int p ){
    node *tail = head;
    while(tail->r!=NULL){
        tail=tail->r;
    }

    int sum = 0;

    while(head<=tail){
        sum = head->d + tail->d;
        if(sum > p){
            tail = tail->l;
        } 
        else
        if(sum < p){
            head = head -> r;
        }
        else
        if(sum == p){
            cout<<"("<<head->d <<","<<tail->d<<")"<<endl;
            head = head->r;
            tail = tail->l;
        }
    }
}

int main(){

    node *head = NULL;

    int n,a;
    cout<<"\nEnter no. of nodes : ";
    cin>>n;
    cout<<"\nEnter sorted elements ";
    for(int i=0;i<n;i++){
        cin>>a;
        insert_back(head,a);
    }

    int p ;
    cout<<"\nEnter p :";
    cin>>p;

    find_pairs(head , p);

    return 0;
}