#include<stdio.h>
#define MAX 100
struct queue {
	int ar[MAX];
	int front;
	int rear;
} q;
struct stack {
	int ar[100];
	int top;
} s;
void push(int item)
{
	if (q.rear == MAX - 1)
		printf("Queue Overflow \n");
	else
	{
		if (q.front == - 1)
			q.front = 0;

		q.rear = q.rear + 1;
		q.ar[q.rear] = item;
	}

}


int pop()
{
	if (q.front == - 1 || q.front > q.rear)
	{
		printf("Queue Underflow \n");
		return -1;
	}
	else
	{	int ele = q.ar[q.front];
		printf("Element deleted from queue is : %d \n", q.ar[q.front]);
		q.front = q.front + 1;
		return ele;

	}
}

void display()
{
	int i;
	if (q.front == - 1)
		printf("Queue is empty \n");
	else
	{
		printf("Queue is : \n");
		for (i = q.front; i <= q.rear; i++)
			printf("%d ", q.ar[i]);
		printf("\n");
	}
}
void pushs(int x)
{
	if (s.top == MAX - 1)
	{
		printf("Overflow\n");
	}
	else
	{
		s.top++;
		s.ar[s.top] = x;
	}
}
int pops()
{
	if (s.top == -1)
	{
		printf("Underflow\n");
		return -1;
	}
	else
	{	int ele = s.ar[s.top];
		s.top--;
		//printf("Element is %d \n: ", ele);
		return ele;
	}
}
int main()
{	q.front = -1;
	q.rear = -1;
	s.top = -1;
	int ele;
	ele = pop();
	push(1);
	//display();
	//return 0;
	push(2);
	push(3);
	push(4);
	push(5);
	push(6);
	push(7);
	int k;
	printf("Enter the value of k less then 7\n");
	scanf("%d", &k);
	int i;
	for (i = 0; i < k; i++)
	{
		int ele = pop();
		pushs(ele);
	}
	for (i = 0; i < k; i++)
	{
		int x = pops();
		push(x);
	}
	int n = 7;
	for (i = 0; i < (n - k); i++)
	{
		int ele = pop();
		push(ele);
	}
	printf("Queue After rversing %d elements\n", k);
	display();

}