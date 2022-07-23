#include<iostream>
using namespace std;

class node{
    public:
    int d;
    node* l;
    node* r;
     
    node(int data){
        d = data;
        r = NULL;
        l = NULL;
    }

};

bool isBST(node *root , int min , int max){
    if(root == NULL)
        return true;

    if(root->d < min || root->d > max )
        return false;

    return (isBST(root->l , min , root->d -1) && isBST(root->r , root->d +1 , max));    
}

int main(){
    int a ;
    cin>>a;
    node *root = new node(a);
    cin>>a;
    root->l = new node(a);
    cin>>a;
    root->r = new node(a);
    cin>>a;
    root->l->l = new node(a);
    cin>>a;
    root->l->r = new node(a);
    cin>>a;
    root->r->l = new node(a);
    cin>>a;
    root->r->r = new node(a);
    
    if(isBST(root , INT_MIN , INT_MAX))
        cout<<"Given tree is a binary search tree "<<endl;
    else 
        cout<<"Given tree is not a binary search tree" << endl;

    return 0;
}