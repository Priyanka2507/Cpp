#include<iostream>
using namespace std;

class ll{
    int data;
    ll* next;
    public:

    ll(int d){
        data = d;
        next = NULL;
    }

    void insert_beg(int d , ll* &head){
        ll* temp = new ll(d);
        if(head == NULL){
            head = temp;
        }
        temp->next = head;
        head = temp;
        return;
    }

    void insert_end(int d , ll* &head){
        if(head == NULL){
            head = new ll(d);
            return;
        }

        ll* tail = head;
        while(tail->next!=NULL){
            tail = tail->next;
        }
        tail->next = new ll(d);
        return;
    }

    void insert_mid(int d , ll* &head , int p){
        if(head == NULL){
            cout<<"\n Empty list";
            return;
        }
        if(p == 0){
            (*head).insert_beg(d,head);
            return;
        }
        else {
            ll* temp = new ll(d);
            ll* node = head;
            p--;
            while(p>0){
                node = node->next;
                p--;
            }
            temp->next = node;
            node->next = temp;
        }
        return;
    }

    void display(ll* head){
        if(head == NULL){
            cout<<"\n Empty list";
        }
        ll* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }


};

int main(){
    ll* head;
    int d ;
    cin>>d;
    (*head).insert_beg(d,head);
    cin>>d;
    (*head).insert_beg(d,head);
    cin>>d;
    (*head).insert_beg(d,head);
    cin>>d;
    (*head).insert_mid(d,head,1);

    (*head).display(head);
    return 0 ;
}