#include <iostream>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n ;
	    cin>>n;
	    int a[n];
	    for(int i =0 ;i<n ;i++){
	        cin>>a[i];
	    }
	    
	    int i=0,m,cnt=0;
	    int flag=0;
	    int j,max = 0;
	    while(i<n-1){
	        if(a[i]==0){
	            break;
	            flag = -1;
	        }
	        m = a[i];
	        j = i;
	        while(j<i+m){
	            max = a[j];
	            if(max<a[j])
	                max = a[j];
	            j++;
	        }
	        m= max;
            i = i+m;
            cnt++;
	    }
	    if(flag == -1){
	        cout<<"-1"<<endl;
	    }
	    else
	        cout<<cnt<<endl;
	}
	return 0;
}