#include<stdio.h>

//To print ASCII value of a character entered by user
int main(){
    char c = 0;
    printf("Enter a character :");
    scanf("%c",&c);
    printf("ASCII value is %c is %d",c,c);    
    return 0;
}