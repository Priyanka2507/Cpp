#include<iostream>
using namespace std;

int power(int a, int n){
    if(n==0){
        return 1;
    }
    int ans = a*power(a,n-1);
    return ans;
}

int mul(int a , int b){
    if(b==0){
        return 0;
    }
    int ans =0;
    ans = ans+a +mul(a,b-1);
    return ans;
}

bool isSorted(int *a,int n){
    if(n==0 || n==1){
        return true;
    }
    if(a[0]<=a[1] && isSorted(a+1,n-1)){
        return true;
    }
    return false;
}

int linearSearch(int *a,int key,int n){
    if(n==0){
        return -1;
    }
    if(a[0]==key){
        return 0;
    }
    int i = linearSearch(a+1,key,n-1);
    if(i==-1){
        return -1;
    }
    return i+1;
}

int lastOccurence(int *a , int key , int n){
    if(n==0){
        return -1;
    }
    int i = lastOccurence(a+1,key,n-1);

    if(i==-1){
        if(a[0]==key)
            return 0;
        else
            return -1;
    }
    return i+1;
}

void printAllOcc(int *a , int key , int n){
    if(n==0)
        return;

    printAllOcc(a+1,key,n-1);
    if(a[0]==key){
        cout<<a[0]<<endl;
    }
    return;
}

int fastPower(int a , int n){
    if(n==1){
        return a;
    }
    int smallPower = fastPower(a,n/2);
    if(n&1)
        return a*smallPower*smallPower;
    else
        return smallPower*smallPower;
}

void extractDigit(int n){
    if(n==0){
        return;
    }
    extractDigit(n/10);
    int digit = n%10; //bottom up approach
    cout<<digit<<"  ";
    return;
}

int stringToInteger(char *a ,int n){
    if(n==0){
        return 0; 
    }
    int digit = a[n-1]-'0';
    int ans = stringToInteger(a,n-1);
    return ans*10+digit;
}

void replacePi(char a[],int i){
    if(a[i]=='\0' || a[i+1]=='\0'){ 
        return ;
    }
    if(a[i]=='p'&& a[i+1]=='i'){
        int j = i+2;
        while(a[i]!='\0'){
            j++;
        }
        while(j>=i+2){
            a[j+2] = a[j];
            j--;
        }
        a[i] = '3';
        a[i+1] = '.';
        a[i+2] = '1';
        a[i+3] = '4';
    }
    replacePi(a,i+4);
    int j;
    for(j=0;a[j]!='\0';j++){
        cout<<a[j];
    }
}

int main(){
    int a = 3;
    int n = 8;
    int x[6] = {1,2,2,4,2,6};
    cout<<power(a,n)<<endl;
    cout<<mul(a,n)<<endl;
    cout<<isSorted(x,6)<<endl;
    cout<<linearSearch(x,4,6)+1<<endl;
    cout<<lastOccurence(x,2,6)+1<<endl;
    printAllOcc(x,2,6);
    cout<<fastPower(a,n)<<endl;
    extractDigit(20478);
    cout<<endl;
    //cout<<stringToInteger("12345", 5)<<endl;
    char y[100]  ="pripiyankapiaggpi";
    replacePi(y, 0);
    return 0;
}