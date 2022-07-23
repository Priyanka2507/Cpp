#include <iostream>
using namespace std;

int main()
{
    int a[4][4] = {1, 2, 3, 4, 
                   5, 6, 7, 8, 
                   9, 10, 11, 12,
                   13, 14, 15, 16};
    int col = 4, row = 4;
    int b;

    for(int i=0;i<row;i++){
        for(int j=0;j<(col/2);j++){
            b  = a[i][j];
            a[i][j] = a[i][col-j-1];
            a[i][col-j-1] = b;        
        }
    }

    for(int i=0;i<row;i++){
        for(int j=0;j<i;j++){
            b=a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = b;
        }
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}