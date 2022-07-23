#include<iostream>
using namespace std;

struct Node { 
    int data; 
    struct Node* next; 
}; 

Node* deleteNode(Node* head , int k){
    if(head==NULL || k==0){
        return head;
    }
    if(k==1){
        Node* node = head->next;
        return node;
    }
    if(k==2){
        Node* node = head->next;
        head->next = node->next;
        delete node;
        return head;
    }
    head->next = deleteNode(head->next , k-1);
    return head; 
}

void push(struct Node **head_ref, int new_data) 
{ 
    struct Node *new_node = new Node; 
    new_node->data = new_data; 
    new_node->next = *head_ref; 
    *head_ref = new_node; 
}

/* Utility function to print a linked list */
void printList(struct Node *head) 
{ 
    while (head!=NULL) 
    { 
        cout << head->data << " "; 
        head = head->next; 
    } 
    printf("\n"); 
} 
   
/* Driver program to test above functions */
int main() 
{ 
    struct Node *head = NULL; 
   
    /* Create following linked list 
      12->15->10->11->5->6->2->3 */
    push(&head,3); 
    push(&head,2); 
    push(&head,6); 
    push(&head,5); 
    push(&head,11); 
    push(&head,10); 
    push(&head,15); 
    push(&head,12); 
    
    int k = 6; 
    head = deleteNode(head, 6); 
   
    printf("\nModified Linked List: "); 
    printList(head); 
   
    return 0; 
} 