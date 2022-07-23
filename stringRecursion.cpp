#include<iostream>
#include <string>
using namespace std;

bool checkPalin(char* a ,int n){
    if(n==0){
        return false;
    }
    if(a[0]==a[n-1] && checkPalin(a+1,n-1)){
        return true;
    }
    return false;
}

int stoin(char* a){
	if(*a==NULL){
		return 0;
	}
	int ans = ans*10 + *a;
    int dig = stoin(a+1);
	return ans;
}

int main() {
	char a[20];
	cin>>a;
	cout<<stoin(a);
	return 0;
}
