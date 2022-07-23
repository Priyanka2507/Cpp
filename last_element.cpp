#include<iostream>
using namespace std;

int findM(int *a, int m , int i){
	if(i==-1 || a[i]==m){
		return i;
	}
	int ans = findM(a,m,i-1);
	return ans;
}

int main() {
	int n,m;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	cin>>m;
	cout<<findM(a,m,n-1);
	return 0;
}