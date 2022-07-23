#include<stdio.h>

int main(){
    int a[10]={1,2,3,4,5};
    int n = 5;
    int i,b,key;
    b=3;
    key = 4;

    //Traversing 
    for(i=0;i<n;i++){
        printf("%d",a[i]);
    }

    //Insertion at index b
    for(i=n-1;i>b-1;i--){
        a[i+1] = a[i];
    }
    a[b-1] = 9;

    //Deletion at index b
    for(i =b-1;i<n;i++){
        a[i] = a[i+1];
    }

    //Search key
    for(i=0;i<n;i++){
        if(a[i]==key){
            printf("%d is at index %d",key,i+1);
            break;
        }
    }

    //Update at index b
    a[b] = key;

    //printing array
    for(i=0;i<n;i++){
        printf("%d",a[i]);
    }
    return 0 ;
}
