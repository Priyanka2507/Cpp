#include<stdio.h>
#include<string.h>

//To print alternate characters of your name
int main(){
    char name[20];
    printf("Enter your name :");
    int i ;
    gets(name);
    for(i=0; name[i]!='\0';i+=2){
        printf("%c",name[i]);
    }
    return 0;
}