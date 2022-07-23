#include <iostream>
#include<stack>
using namespace std;

int main() {
	//code
	int t ;
	cin>>t;
	while(t--){
	    string s1,s2;
	    cin>>s1;
	    stack<char> st;
	    int n = s1.length();
	    for(int i =0 ;i<n ;i++){
	        if(s1[i]=='.'){
	           while(!st.empty()){
	               s2 = s2 + st.top();
	               st.pop();
	           }
	           s2 = s2 +".";
	        }
	        else{
	            st.push(s1[i]);
	        }
	    }
	    while(!st.empty()){
	               s2 = s2 + st.top();
	               st.pop();
	    }
	    cout<<s2<<endl;
	}
	return 0;
}