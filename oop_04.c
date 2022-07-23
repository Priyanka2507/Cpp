#include<stdio.h>

//To modify the above 3 rd program to take data of 5 students and print it using array of object concept.
struct student
{
    /* data */
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
    }

    for(i=0;i<5;i++){
        printf("\nName : %s\n", s[i].name);
        printf("Roll no. : %d\n",s[i].rollno);
    }

    return 0 ;
}