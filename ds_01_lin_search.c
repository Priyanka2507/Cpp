#include<stdio.h>
int main(){
int a[100];
int n , i, key =0;
printf("Enter no. of elements:");
scanf("%d",&n);
printf("Enter no. to find :");
scanf("%d",&key);
printf("Enter the elements:");
for (i = 0;i<n;i++){
    scanf("%d",&a[i]);
}

for(i=0;i<n;i++){
    if(key == a[i]){
        printf("key %d is present at index %d",a[i],i+1);
        break;
    }
}
return 0;
}

