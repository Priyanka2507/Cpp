void print(list* head){
    if(head==NULL) return;
    while(head!=NULL){
        cout<<head->data<<endl;
        head =  head->next;
    }
}

void removeDuplicate(list* head){
    if(head==NULL) return;
    while(head!=NULL){
        if(head->next->data==head->data){
            head->next = head->next->next;
        }
        head = head->next;
    }
}

list* reverse(list* head){
    if(head==NULL || head->next==NULL){
        list* new_head = head;
         return new_head;
    }
    head  = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
}

void levelOrderBT(node* root){
    if(root==NULL) return;
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        while(temp!=NULL){
            cout<<temp->data;
            q.push(temp->left);
            q.push(temp->right);
            temp = q.front();
            q.pop();
        }
        q.push(NULL);
        cout<<endl;
    }
}

void kthLevel(node* root,int l,int currentlevel){
    if(root==NULL){
        return;
    }
    if(currentlevel==l)
        cout<<root->data;
    else
    {
        kthLevel(root->left,l,currentlevel+1);
        kthLevel(root->right,l,currentlevel+1);
    }
}
void levelOrderBT(node* root){
    if(root==NULL){
        return;
    }
    int k = height(root);
    int i = 0;
    while(i<=k){
        kthLevel(root,i,0);
    }
}

