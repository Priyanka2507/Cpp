Node *createNode(Node *head) {
    
    Node *newHead = NULL, *newEnd = NULL;
    
    while(head != NULL) {
        
        if(newHead == NULL) {
            newHead = newEnd = new Node(head->data);
        } else {
            newEnd->next = new Node(head->data);
            newEnd = newEnd->next;
        }
        
        newEnd->arb = head->arb;
        
        head = head->next;
    }
    
    if(newHead != NULL) {
        newEnd->next = NULL;
    }
    
    return newHead;
}

Node *copyList(Node *head) {
    
    Node *newHead = createNode(head);
    
    return newHead;
}