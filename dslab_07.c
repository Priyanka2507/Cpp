#include<stdio.h>


struct stack{
    int a[100];
    int top1;
    int top2;
};

void print_stack(struct stack *s ){
    int x = s->top1;
    int y = s->top2;
    printf("\n Satck 1 : ");
    while(x!=-1){
        printf("%d\t",s->a[x]);
        x--;
    }
    printf("\n Stack 2 : ");
    while(y != 9 && y>9){
        printf("%d\t",s->a[y]);
        y--;
    }
}

void push(int v , struct stack *s , int c){
    if(c==1){
        if(s->top1!=9){
            s->top1++;
            s->a[s->top1] = v;
            printf("\n %d pushed in stack 1",v);
        }
        else{
            printf("\n Stack overflow");
        }
    }
    if(c==2){
        if(s->top2!=19){
            s->top2++;
           s->a[s->top2] = v;
            printf("\n %d pushed in stack 2",v);
        }
        else{
            printf("\n Stack overflow");
        }
    }
}

int main(){

    struct stack stck;
    struct stack *s= &stck;

    s->top1 = -1;
    s->top2 = 9;    
    
    push(1,s,1);
    push(2,s,1);
    push(3,s,1);
    push(4,s,1);
    push(11,s,2);
    push(12,s,2);
    push(13,s,2);
    push(14,s,2);

    print_stack(s);

    return 0;
}