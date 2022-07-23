#include<stdio.h>

int main(){
    int a[100];
    int i , j , n;
    int b =0;
    printf("Enter no. of elements :");
    scanf("%d",&n);
    printf("Enter elements of array :");
    for (i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                b = a[j];
                a[j] = a[j+1];
                a[j+1] = b;
            }
        }
    }

    printf("Sorted Array :");
    for(i = 0;i<n;i++){
        printf("%d \t",a[i]);
    }
    return 0;

}