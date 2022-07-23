#include<stdio.h>
int main(){
int a[100];
int n , i, key =0;
int s,e,f=0;
printf("Enter no. of elements:");
scanf("%d",&n);
printf("Enter no. to find :");
scanf("%d",&key);
printf("Enter sorted elements:");
for (i = 0;i<n;i++){
    scanf("%d",&a[i]);
}
s=0;
e=n;
while(s<=e){
f = (s+e)/2;
if(key == a[f]){
    printf("key %d is present at index %d",a[f],f+1);
    break;
}
else if(key<a[f]){
    e = f;
    }
else if(key>a[f]){
    s = f;
}
else{
    printf("Element not present");
}
}


return 0;
}