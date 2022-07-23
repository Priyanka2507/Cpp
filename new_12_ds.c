#include<stdio.h>
#define MAXSIZE 100
struct stack{
		int top;
		int a[MAXSIZE];
	};

	struct stack source,helper,destination;

char push(char disk, struct stack *s){
	if(s->top < MAXSIZE -1){
		s->top++;
		s->a[s->top]= disk;
		// printf("ELEMENT PUSHED IS : %c \n",disk);
		return s->a[s->top];
	}
	else{
		printf("OVERFLOW \n");
		return -1;
	}
}
char pop(struct stack *s){
	if(s->top ==-1){
		printf("UNDERFLOW \n");
		return -1;
	} 
	else{
		int element= s->a[s->top];
		s->top--;
		return element;
	}
}

int main (){
	
	source.top==-1;
	helper.top=-1;
	destination.top=-1;

printf("ELEMENT PUSHED IN SOURCE IS :%c \n",push('C',&source));
printf("ELEMENT PUSHED IN SOURCE IS :%c \n",push('B',&source));
printf("ELEMENT PUSHED IN SOURCE IS :%c \n",push('A',&source));
	

	//considering we have 3 disks initially in the source tower
	printf("\n");

	char c=pop(&source);
printf("ELEMENT PUSHED IN DESTINATION IS :%c \n",push(c,&destination));

	c=pop(&source);
printf("ELEMENT PUSHED IN HELPER IS :%c \n",push(c,&helper));

	c=pop(&destination);
printf("ELEMENT PUSHED IN HELPER IS :%c \n",push(c,&helper));


	c=pop(&source);
printf("ELEMENT PUSHED IN DESTINATION IS :%c \n",push(c,&destination));


	c=pop(&helper);
printf("ELEMENT PUSHED IN SOURCE IS :%c \n",push(c,&source));

	c=pop(&helper);
printf("ELEMENT PUSHED IN DESTINATION IS :%c \n",push(c,&destination));

	c=pop(&source);
printf("ELEMENT PUSHED IN DESTINATION IS :%c \n",push(c,&destination));

printf("\n THE DISKS IN THE DESTINATION TOWER ARE : \n");
printf("%c\n",pop(&destination));
printf("%c\n",pop(&destination));
printf("%c\n",pop(&destination));


}