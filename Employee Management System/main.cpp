#include<bits/stdc++.h>

using namespace std;

vector < vector <string> > emp;
vector <string> Name;
vector <string> Desig;
vector <string> Age;
vector <string> EmpId;
vector <string> Exp;

map < string, int > hashMap;

int t = 0, n = 0, index;
char y;
string srchEmp, delEmp;

void showMenu();


void createData()
{

    string name, desig, empId, age, exp;

    cout << "EMPLOYEE - " << ++t << ":" << endl << endl;

    cout << "Employee ID - ";
    cin >> empId;
    cout << "Employee Name - ";
    cin >> name;
    cout << "Designation - ";
    cin >> desig;
    cout << "Age - ";
    cin >> age;
    cout << "Experience - ";
    cin >> exp;

    hashMap[empId] = t - 1;

    emp[0].push_back(empId);
    emp[1].push_back(name);
    emp[2].push_back(desig);
    emp[3].push_back(age);
    emp[4].push_back(exp);

    cout << endl;
}


void createChart()
{
    if (Name.size() != 0)
    {
        cout << "Employee Chart Exists  *Press 3 to add new Employee Data" << endl << endl;
        cout << "Want to enter MENU again\nPress Y/N: ";
        cin >> y;
        cout << endl;
        if (y == 'Y' || y == 'y')
            showMenu();
        else
            exit(0);
    }
    else
    {
        int n;
        cout << "ENTER NO. OF EMPLOYEES TO BE INSERTED" << endl;
        cin >> n;
        cout << endl;
        while (n--)
        {
            createData();
        }
        showMenu();
    }
}


void viewChart()
{
    cout << "---------------------------------------------------  EMPLOYEE CHART  ---------------------------------------------------" << endl;
    cout << "S. No.               Employee Id               Name               Designation               Age               Experience"<<endl<<endl;
    for (int i = 0; i < emp[0].size(); i++)
    {
        cout << i+1<<".";
        n = 20;
        for (int i = 0;i < n;i++)
            cout << " ";
        cout << emp[0][i];
        n = 26 - emp[0][i].size();
        for (int i = 0;i < n;i++)
            cout << " ";
        cout << emp[1][i];
        n = 19 - emp[1][i].size();
        for (int i = 0;i < n;i++)
            cout << " ";
        cout << emp[2][i];
        n = 26 - emp[2][i].size();
        for (int i = 0;i < n;i++)
            cout << " ";
        cout << emp[3][i];
        n = 18 - emp[3][i].size();
        for (int i = 0;i < n;i++)
            cout << " ";
        cout << emp[4][i];
        n = 25 - emp[4][i].size();
        for (int i = 0;i < n;i++)
            cout << " ";
        cout << endl;
    }

    showMenu();
}


void newData()
{
    createData();
    showMenu();
}


void searchEmployee()
{
    cout << "Enter Employee Id of the EMPLOYEE you seek : ";
    cin >> srchEmp;
    cout << endl;

    if (hashMap.find(srchEmp) != hashMap.end())
    {
        index = hashMap[srchEmp];

        cout << "Employee ID - " << emp[0][index] << endl;
        cout << "Employee Name - " << emp[1][index] << endl;
        cout << "Designation - "<< emp[2][index] << endl;
        cout << "Age - "<< emp[3][index] << endl;
        cout << "Experience - "<< emp[4][index] << endl;
        cout << endl;
    }
    else
        cout << "Employee with the following ID doesn't exist" << endl;

    cout << "Want to enter MENU again\nPress Y/N: ";
    cin >> y;
    cout << endl;
    if (y == 'Y' || y == 'y')
        showMenu();
    else if (y == 'N' || y == 'n')
        exit(0);
    else
    {
        cout << "You Entered Wrong choice..." << endl;
        exit(0);
    }
}


void deleteData()
{
    cout << "Enter Employee Id to delete details of the Employee : ";
    cin >> delEmp;
    index = hashMap[delEmp];
    if (hashMap.find(delEmp) != hashMap.end())
    {
        for (int j = 0;j < emp.size();j++)
            emp[j].erase(emp[j].begin() + index);
        for (int i = index;i < emp[0].size();i++)
            hashMap[emp[0][i]]--;
        t--;
        cout << "Data Deleted Successfully" << endl;
    }
    else
    {
        cout << "Employee with the following ID doesn't exist" << endl;
    }
    cout << "Want to enter MENU again\nPress Y/N: ";
    cin >> y;
    cout << endl;
    if (y == 'Y' || y == 'y')
        showMenu();
    else if (y == 'N' || y == 'n')
        exit(0);
    else
    {
        cout << "You Entered Wrong choice..." << endl;
        exit(0);
    }

}


void showMenu()
{
    cout << endl;
    cout << "----------------------------------------  EMPLOYEE MANAGEMENT SYSTEM ( E.M.S.)  ----------------------------------------" << endl << endl << endl;
    cout << "1) CREATE EMPLOYEES CHART" << endl;
    cout << "2) VIEW EMPLOYEES CHART" << endl;
    cout << "3) ADD NEW EMPLOYEE" << endl;
    cout << "4) SEARCH EMPLOYEE DETAILS" << endl;
    cout << "5) DELETE EMPLOYEE DATA" << endl;
    cout << "6) EXIT" << endl << endl;

    cout << "ENTER YOUR CHOICE :" << endl;
    int ch;
    cin >> ch;
    cout << endl;

    switch (ch)
    {
    case 1:
        createChart();
        break;
    case 2:
        viewChart();
        break;
    case 3:
        newData();
        break;
    case 4:
        searchEmployee();
        break;
    case 5:
        deleteData();
        break;
    case 6:
        return;
    default:
        cout << "Expected Options are 1/2/3/4/5/6" << endl;
        cout << "Want to enter MENU again\nPress Y/N: ";
        cin >> y;
        cout << endl;
        if (y == 'Y' || y == 'y')
            showMenu();
        else if (y == 'N' || y == 'n')
            exit(0);
        else
        {
            cout << "You Entered Wrong choice..." << endl;
            exit(0);
        }
    }
}


int main()
{

    emp.push_back(EmpId);
    emp.push_back(Name);
    emp.push_back(Desig);
    emp.push_back(Age);
    emp.push_back(Exp);

    showMenu();

    return 0;
}





