#include <iostream>
#include <string.h>
using namespace std;
 
class Student
{
    string name;
    int roll;
 
public:
    Student()
    {
        name = "";
        roll = 0;
    }
    void operator=(const Student &st)
    {
        name = st.name;
        roll = st.roll;
    }
    friend istream &operator>>(istream &is, Student &st);
    friend ostream &operator<<(ostream &os, const Student &st);
};
 
class Classroom
{
    Student s[2];
 
public:
    Student &operator[](int i)
    {
        return s[i];
    }
};
 
std::istream &
operator>>(std::istream &is, Student &st)
{
    cout << "Enter Name: ";
    is >> st.name;
    cout << "Enter Roll Number: ";
    is >> st.roll;
    return is;
}
 
std::ostream &operator<<(std::ostream &os, const Student &st)
{
    os << "Name: " << st.name << endl
       << "Roll Number: " << st.roll << endl;
    return os;
}
 
int main()
{
    Classroom c;
    for (int i = 0; i < 2; i++)
    {
        cout << "Enter student" << i + 1 << endl;
        cin >> c[i];
    }
    cout << c[0];
    cout << c[1];
    cout << "Assigning Student 1 to Student 2\n";
    c[1] = c[0];
    cout << c[0];
    cout << c[1];
    return 0;
}
