#include<iostream>
#include<fstream>
using namespace std;
int main(){
	ifstream file;
	file.open("textFile.txt");
	int num=0,alp=0,space=0,special=0;
	while(!file.eof()) {
		char t = file.get();
		if(isalpha(t)){
		alp++;
		} 
		else if(isdigit(t)){
		 num++;}
		else if(t==' ') {
		space++;}
		else {
		special++;}
	}
	file.close();
	cout<<"Numbers\t\t"<<num<<"\t: Alphabet\t\t"<<alp<<"\t: Space\t\t"<<space<<"\t: Special\t\t"<<special;
	return 0;
}
