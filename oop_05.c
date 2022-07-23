#include<stdio.h>

//To modify the above program further to created a nested structure called address and print the fields from that.
struct address
{
    /* data */
    char add[50];
};

struct student
{
    /* data */
    struct address a;
    char name[20];
    int rollno;
};
int main(){
    struct student s[5];
    int i;
    for(i=0;i<5;i++){
        printf("Enter name : ");
        scanf("%s",&s[i].name);
        printf("Enter Roll no. : ");
        scanf("%d",&s[i].rollno);
        printf("Enter address : ");
        scanf("%s",&s[i].a.add);
    }

    for(i=0;i<5;i++){
        printf("\nName : %s\n", s[i].name);
        printf("Roll no. : %d\n",s[i].rollno);
        printf("Address : %s",s[i].a.add);
    }

    return 0;
}