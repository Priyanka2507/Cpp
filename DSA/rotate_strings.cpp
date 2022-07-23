#include<iostream>
#include<queue>
#include<string>

using namespace std;

int main(){
    string s1 = "Hello";
    queue<char> q;
    for(int j = 0 ;s1[j]!='\0';j++){
        q.push(s1[j]);
    } 
    while (!q.empty())
    {
        cout << '\t' << q.front();
        q.pop();
    }

    return 0;
}