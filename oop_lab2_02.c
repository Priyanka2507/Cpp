#include<stdio.h>
#include<string.h>

struct address
{
    char add[50];
};
struct bank_employee
{
    char name[50];
    int empid;
    int salary;
    int totalsalary;
    char city_of_work[20];
    struct address a; 
    
};

struct bank_branch
{
    int branchid;
    char branch_city[20];
    int bonus;
    struct address a;
};

int main()
{
    struct bank_branch bb[5];
    struct bank_employee be[5];
    int i;

    for(i=0 ;i<5;i++){
        printf("Name : ");
        scanf("%s",&be[i].name);
        printf("Employee ID : ");
        scanf("%d",&be[i].empid);
        printf("Salary :");
        scanf("%d",&be[i].salary);
        printf("City of work : ");
        scanf("%s",&be[i].city_of_work);
    }
    for(i=0;i<5;i++){
        printf("Branch ID : ");
        scanf("%d",&bb[i].branchid);
        printf("Branch city : ");
        scanf("%s",&bb[i].branch_city);
        printf("Bonus : ");
        scanf("%d",&bb[i].bonus);
    }

    for(i=0;i<5;i++){
        be[i].totalsalary = be[i].salary + bb[i].bonus;
        strcpy(bb[i].a.add,be[i].city_of_work);
        printf("Employee Name : %s\n",be[i].name);
        printf("Employee ID : %d\n",be[i].empid);
        printf(" Total Salary : %d\n",be[i].totalsalary);
        printf("Branch Address : %s\n",&bb[i].a.add);
    }

    return 0;
}