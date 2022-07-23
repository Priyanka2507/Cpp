#include <iostream>
#include<stack>
using namespace std;


bool isPalin(string a){
        stack<char> st;
        bool ans = true;
        int n = a.size();
        for(int j=0;j<n;j++){
            st.push(a[j]);
        }
        int i=0;
        while(!st.empty()){
            if(a[i]!=st.top()){
                ans = false;
                break;
            }
            st.pop();
            i++;
        }
        return ans;
    }

int main(){
    string s;
    cin>>s;
    cout<<isPalin(s);
    return 0;
}