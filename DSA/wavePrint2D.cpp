#include<iostream>
using namespace std;

int main(){
    int a[3][4] = { 1, 2, 3, 4, 
                    5, 6, 7, 8,
                    9, 10, 11, 12};

    int n = 4 , m = 3;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i%2==0){
                cout<<a[j][i]<<endl;
            }
            else
            {
                cout<<a[m-j-1][i]<<endl;
            }
            
        }
    }
    return 0;
}