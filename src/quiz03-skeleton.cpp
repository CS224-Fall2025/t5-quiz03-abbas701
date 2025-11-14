#include <iostream>
using namespace std;
class Employee
{
protected:
    string name;
    double salary;
    static int employeeCount;

public:
    Employee(string n, double s) : name(n), salary(s)
    {
        employeeCount++;
    };
    virtual void displayInfo() = 0;
    static void showTotalEmployees()
    {
        cout << "Total Employees Created: " << employeeCount << endl;
    }
    virtual ~Employee() {}
};
class Staff : public Employee
{
private:
    string department;

public:
    Staff(string n, double s) : Employee(n, s){};
    void displayInfo() override
    {
        cout << "Name: " << name << " (Staff), Salary: " << salary<<endl;
    }
};

class Faculty : public Employee
{
private:
    string department;

public:
    Faculty(string n, double s) : Employee(n, s){};
    void displayInfo() override
    {
        cout << "Name: " << name << " (Faculty), Salary: " << salary<<endl;
    }
};
int Employee::employeeCount = 0;

int main()
{
    int num;
    double salary;
    string position, name;
    cin >> num;
    Employee *test[10];

    for (int i = 0; i < num; i++)
    {
        cin >> name;
        cin >> position;
        cin >> salary;
        if (position == "Staff")
        {
            Staff *staff=new Staff(name, salary);
             test[i] = staff;
        }
        else
        {
            Faculty *faculty=new Faculty(name, salary);
             test[i] = faculty;
        }
    }
    for (int i = 0; i < num; i++)
    {
        test[i]->displayInfo();
    }

    Employee::showTotalEmployees();
    for (int i = 0; i < num; i++)
    {
        delete test[i];
    }
    return 0;
}