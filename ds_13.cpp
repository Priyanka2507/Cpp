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


void nearest_small(struct dequeue *q,int a[],int n){
    
}


int main(){
    int i,n,a[100];
    struct dequeue deque;
    struct dequeue *q = &deque;
    q->front = -1;
    q->rear = -1;
    printf("\nEnter no. of elements : ");
    scanf("%d",&n); 
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    print_queue(q);
    return 0;
}