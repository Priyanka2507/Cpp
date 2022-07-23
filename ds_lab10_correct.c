#include<stdio.h>

struct queue{
    int front , rear;
    int a[100];
};

struct stack{
    int x[100];
    int top;
};

int isfull(struct queue *q){
    if(q->rear ==99){
        return 1;
    }
    else
    {
        return 0;
    }
    
}
int isempty(struct queue *q){
    if(q->front > q->rear){
        return 1;
    }
    else
    {
        return 0;
    }
    
}

void enqueue(struct queue *q,int v){
    if(isfull(q)){
        printf("\nQueue is full");
        return;
    }
    q->a[q->rear++]=v;
    printf("\n%d added to queue",v);
    
}

void dequeue(struct queue *q){
    if(isempty(q)){
        printf("\nQueue is empty");
        return;
    }
    printf("\n%d is removed from queue ",q->a[q->front]);
    q->front++;
}

void print_queue(struct queue *q){
    int i = q->front;
    while(i<q->rear){
        printf("%d\t",q->a[i]);
        i++;
    }
}
void push(int v , struct stack *s){
    if(s->top!=9){
        s->top++;
        s->x[s->top] = v;
        printf("\n %d pushed in stack",v);
    }
    else{
        printf("\n Stack overflow");
    }
}

void pop(struct stack *s){
    if(s->top!=-1){
        printf("\n %d is poped from stack",s->x[s->top]);
        s->top --;
    }
    else
    {
        printf("\n Stack is empty");
    }
}

void reverse(struct queue *q , int k ){
    if(k>q->rear){
        printf("\nInvalid");
        return;
    }
    struct stack stck;
    struct stack *s = &stck;
    int ele,i;
    for(i=0;i<k;i++){
        ele = q->a[q->front];
        push(ele,s);
        dequeue(q);       
    }

    while(s->top!=-1){
        ele =s->x[s->top];
        enqueue(q,ele);
        pop(s);
    }
    int n = 7;
    for (i = 0; i < (n - k); i++){
		int ele =q->a[q->front];
        dequeue(q);
		enqueue(q,ele);
	}
}
int main(){

    struct queue que;
    struct queue *q = &que;
    q->front = 0;
    q->rear = 0;
    int i,b,k;
    do
    {
        printf("\n 1. Add element in queue.");
        printf("\n 2. Remove element from queue.");
        printf("\n 3. Print queue.");
        printf("\n 4. Reverse k first elements.");
        printf("\n 5. Exit.");
        scanf("%d",&i);
        if(i==1){
            scanf("%d",&b);
            enqueue(q,b);
        }
        if(i==2){
            dequeue(q);
        }
        if(i==3){
            printf("\n");
            print_queue(q);
        }
        if(i==4){
            printf("Enter k less than 7");
            scanf("%d",&k);
            reverse(q,k);
        }
    } while (i!=5);


    return 0;
}
