#include<stdio.h>
#define MAX 100

struct stack{
    int a[MAX];
    int top;
}A,B,C;

void print_stack(struct stack *s){
    int x = s->top;
    while(x!=-1){
        printf("%d\n",s->a[x]);
        x--;
    }
    
}

void push(int v , struct stack *s , char a){
    if(s->top<9){
        s->top++;
        s->a[s->top] = v;
        printf("\n %d pushed in Pole %c",v,a);
    }
    else
    if(s->top==9){
        printf("\n Stack overflow");
    }
}

void pop(struct stack *s,char a){
    if(s->top!=-1){
        printf("\n %d is poped from Pole %c",s->a[s->top],a);
        s->top --;
    }
    else
    {
        printf("\n Stack is empty");
    }
}


int main(){

    struct stack *poleA = &A;
    poleA->top = -1;
    struct stack *poleB = &B;
    poleB->top = -1;
    struct stack *poleC = &C;
    poleC->top=-1;

    int no_of_disks = 3;
    //Adding 3 disks in poleA
    push(3,poleA,'A');
    push(2,poleA,'A');
    push(1,poleA,'A');
    //Print Stacks
    printf("\nOriginal stack (Pole A) : ");
    print_stack(poleA);

    //Move disks
    pop(poleA,'A');
    push(1,poleC,'C');
    pop(poleA,'A');
    push(2,poleB,'B');
    pop(poleC,'C');
    push(1,poleB,'B');
    pop(poleA,'A');
    push(3,poleC,'C');
    pop(poleB,'B');
    push(1,poleA,'A');
    pop(poleB,'B');
    push(2,poleC,'C');
    pop(poleA,'A');
    push(1,poleC,'C');

    //Print Stacks
    printf("\n New Stack (Pole C) :");
    print_stack(poleB);
    print_stack(poleA);
    print_stack(poleC);
    
    return 0;
}