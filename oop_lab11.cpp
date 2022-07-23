#include<bits/stdc++.h>
using namespace std;
class A{
public:
	A(){
		cout<<"Constructor of class A is called\n";
	}
	virtual ~A(){
		cout<<"VIRTUAL destructor of class A is called\n";
	}
};

class B:public A{
public:
	B(){
		cout<<"Constructor of class B is called\n";
	}
	~B(){
		cout<<"Destructor of class B is called\n";
	}
};
class C{
public:
	C(){
		cout<<"Constructor of class C is called\n";
	}
	~C(){
		cout<<"Destructor of class C is called\n";
	}
};
class D:public C{
public:
	D(){
		cout<<"Constructor of class D is called\n";
	}
	~D(){
		cout<<"Destructor of class D is called\n";
	}
};
int main(){
	cout<<"WITH VIRTUAL DESTRUCTOR\n";
	A *a1= new B;
	cout<<"\n";
	delete a1;

	cout<<endl;
	cout<<endl;

	cout<<"WITHOUT USING VIRTUAL DESTRUCTOR\n";
	C *c1 =new D;
	cout<<"\n";
	delete c1;

}
