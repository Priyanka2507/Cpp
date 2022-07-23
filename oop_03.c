#include<stdio.h>

//To create a structure student with certain attributes of your choice (read from user) and print them.
struct student
{
    /* data */
    char name[20];
    int rollno;
    char emailId[50];
};

int main(){

    struct student s1;
    printf("Enter name : ");
    gets(s1.name);
    printf("Enter email ID: ");
    gets(s1.emailId);
    printf("Enter Roll no. : ");
    scanf("%d",&s1.rollno);

    printf("\nName : %s\n", s1.name);
    printf("Roll no. : %d\n",s1.rollno);
    printf("Email ID: %s\n",s1.emailId);

    

    return 0 ;
}