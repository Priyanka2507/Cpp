#include<stdio.h>
#define SIZE 100

struct dequeue{
    int a[SIZE];
    int front , rear ;
};

int isfull(struct dequeue *q){
    if(q->rear ==SIZE){
        return 1;
    }
    else
    {
        return 0;
    }
    
}

void enqueue(struct dequeue *q,char v){
    if(isfull(q)){
        printf("\nQueue is full");
        return;
    }
    if(q->front ==-1){
        q->front = 0;
    }
    q->a[++q->rear]=v;
    printf("%c added to queue\n",v);
}

char dequeue_front(struct dequeue *q){
    return q->a[q->front++];    
}

char dequeue_end(struct dequeue *q){
    return q->a[q->rear--];
}


void print_queue(struct dequeue *q){
    int i = q->front;
    while(i<=q->rear){
        printf("%c\t",q->a[i]);
        i++;
    }
}

void isPalindrome(struct dequeue *q){
    int ans ;
    while(q->front <= q->rear){
        if(dequeue_front(q)!=dequeue_end(q)){
            ans = 0;
            break;}
        else{
            ans = 1;}
    }
    if(ans==1){
        printf("\nGiven string is a Palindrome");
    }
    else{
        printf("\nGiven string is not a Palindrome");
    }
    
}

int main(){
    int i;
    char j[100];
    struct dequeue deque;
    struct dequeue *q = &deque;
    q->front = -1;
    q->rear = -1; 
    printf("\n Enter string : ");
    scanf("%s",&j);
    for(i=0;j[i]!='\0';i++){
        enqueue(q,j[i]);
    }
    print_queue(q);
    isPalindrome(q);
    return 0;
}