#include<stdio.h>

int main(){
    int a[100];
    int n,i,b;
    printf("Enter no. of elements : ");
    scanf("%d",&n);
    printf("Enter values ");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    // Inserting element at mid position of array
    printf("Enter element to insert at mid position : ");
    scanf("%d",&b);
    for(i=n-1;i>n/2;i--){
        a[i] = a[i-1];
    }
    a[n/2] = b;
    for(i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
    return 0;
}