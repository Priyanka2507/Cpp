#include <iostream>
using namespace std;

template <typename T>
class Student
{
    T marks;
    int rollnumber;

public:
    Student();
    Student(T marks, int rollNumber);
    T getMarks();
    int getRollNumber();
    void setMarks(T marks);
    void setRollNumber(int rollNumber);
};

template <typename T>
Student<T>::Student()
{
    this->marks = 0;
    this->rollnumber = 0;
}

template <typename T>
Student<T>::Student(T marks, int rollNumber)
{
    this->marks = marks;
    this->rollnumber = rollNumber;
}

template <typename T>
T Student<T>::getMarks()
{
    return this->marks;
}

template <typename T>
int Student<T>::getRollNumber()
{
    return this->rollnumber;
}

template <typename T>
void Student<T>::setMarks(T marks)
{
    this->marks = marks;
}

template <typename T>
void Student<T>::setRollNumber(int rollNumber)
{
    this->rollnumber = rollNumber;
}

template <typename T>
void sort(Student<T> a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j].getMarks() > a[j + 1].getMarks())
            {
                Student<T> temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main()
{
    Student<int> arr[5];
    int marks, roll;
    for (int i = 0; i < 5; i++)
    {
        cout << "\nEnter Roll number : ";
        cin >> roll;
        arr[i].setRollNumber(roll);
        cout << "\nEnter Marks : ";
        try
        {
            cin >> marks;
            if (marks < 0)
            {
                throw marks;
            }
        }
        catch (...)
        {
            cout << "\nInvalid Marks\n";
            break;
        }
        arr[i].setMarks(marks);
    }
    sort(arr, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i].getRollNumber() << " " << arr[i].getMarks() << endl;
    }
}