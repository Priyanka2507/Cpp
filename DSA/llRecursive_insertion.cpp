#include<iostream>
using namespace std;


class Node{
    public:
    int data;
    Node* next;
    Node(int d){
        data = d;
        next = NULL;
    }
};

Node* insertNode(Node * head , int data){
    if(head==NULL){
        Node* node = new Node(data);
        return node;
    }
    head->next = insertNode(head->next,data);
    return head;
}

void display(Node* head){
    if(head==NULL){
        return ;
    }
    cout<<head->data<<" ";
    display(head->next);
}

int main(){
    Node* head;
    head = insertNode(head,1);
    head = insertNode(head,2);
    head = insertNode(head,3);
    head = insertNode(head,4);

    display(head);
    return 0 ;
}