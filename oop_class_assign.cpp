#include<iostream>
using namespace std;

template <typename T>
T find_min(T x, T y){
    return (x>y)?y:x;
}
template <typename A>
void swap_num(A &x ,A &y){
    A temp = x;
    x = y;
    y = temp;
}
int main(){
    cout<<"MINIMUM : "<<endl;
    cout<<find_min<int>(4,7)<<endl;
    cout<<find_min<char>('a','f')<<endl;
    cout<<find_min<float>(8.9,3.4)<<endl;
    cout<<"SWAPPING : "<<endl;
    char x = 's' , y  = 't';
    cout<<"x = "<<x<<" y = "<<y<<endl;
    swap_num<char>(x,y);
    cout<<"x = "<<x<<" y = "<<y<<endl;
    int a = 10 , b = 20;
    cout<<"x = "<<a<<" y = "<<b<<endl;
    swap_num<int>(a,b);
    cout<<"x = "<<a<<" y = "<<b<<endl;

    return 0;
}