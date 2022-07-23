#include<stdio.h>

struct stack{
    int a[10];
    int top;
};


void print_stack(struct stack *s){
    int x = s->top;
    while(x!=-1){
        printf("%d",s->a[x]);
        x--;
    }
    
}

void push(int v , struct stack *s){
    if(s->top!=9){
        s->top++;
        s->a[s->top] = v;
        printf("\n %d pushed in stack",v);
    }
    else{
        printf("\n Stack overflow");
    }
}

void pop(struct stack *s){
    if(s->top!=-1){
        printf("\n %d is poped from stack",s->a[s->top]);
        s->top --;
    }
    else
    {
        printf("\n Stack is empty");
    }
}
int main(){

    struct stack stck;
    struct stack *s = &stck;
    
    s->top = -1;
    int i,b =0;
    do
    {
        printf("\n 1. Push element in stack.");
        printf("\n 2. Pop element from stack.");
        printf("\n 3. Print stack.");
        printf("\n 4. Exit.");
        scanf("%d",&i);
        if(i==1){
            scanf("%d",&b);
            push(b,s);
        }
        if(i==2){
            pop(s);
        }
        if(i==3){
            printf("\n");
            print_stack(s);
        }
    } while (i!=4);
    
    return 0;
}