#include<iostream>
using namespace std;

struct Node { 
    int data; 
    struct Node* next; 
};

Node* p = NULL;
Node* reverseR(Node* c){
    if(c==NULL){
        return p;
    }
    Node* n = c->next;
    c->next = p;
    p = c;
    p = reverseR(n);
    return p; 
}

/*
public ListNode reverseList(ListNode head) {
    if (head == null || head.next == null) return head;
    ListNode p = reverseList(head.next);
    head.next.next = head;
    head.next = null;
    return p;
}
*/

void printAltNodes(Node* head){
    if(head==NULL){
        return;
    }
    cout<<head->data<<" ";
    printAltNodes(head->next->next);
}

Node* findMid(Node* fast , Node* slow){
    if(fast==NULL || fast->next == NULL){
        return slow;
    }
    slow = findMid(fast->next->next , slow->next);
    return slow;
}

void alternateSplit(Node* a, Node* b){
    if(a==NULL || b==NULL){
        return;
    }
    if(a->next!=NULL)
        a->next = a->next->next;
    if(b->next!=NULL)
        b->next = b->next->next;
    alternateSplit(a->next , b->next);
}

Node* newhead = NULL;
Node* reverseB(Node* c){
    if(c->next==NULL || c==NULL){
        newhead = c;
        return c;
    }
    Node* temp = reverseB(c->next);
    temp->next = c;
    return c;
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

void reversePrint(struct Node* head){
    if(head==NULL){
        return;
    }
    reversePrint(head->next);
    cout<<head->data<<" ";
    return;
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
    
    //head = reverseR(head);
    //head = reverseB(head); 
   
    printf("\n Linked List: "); 
    printList(head); 
    Node* temp  = head->next;

    Node*  mid = findMid(head,head);
    cout<<"\n MID : "<<mid->data<<" ";
    
    printf("\nReverse Linked List: ");
    reversePrint(head);
   
    printf("\nAlternate Nodes of Linked List: ");
    printAltNodes(head);

    alternateSplit(head , head->next);

    printf("\nAlternate Linked List: ");
    printList(head);
    printf("\nAlternate Linked List: ");
    printList(temp);

    return 0; 
} 