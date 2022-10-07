#include <bits/stdc++.h>
#include "STACK_1.h"
using namespace std;

int global_id = 100;

class person
{
    string name;
    int id;
    float salary;

public:
    person()
    {
        name = "";
        id = -1;
        salary = -1.0;
    }

    void set_name(string name)
    {
        this->name = name;
    }
    void set_salary(float salary)
    {
        this->salary = salary;
    }

    person(string name, float salary)
    {
        this->name = name;
        this->id = global_id;
        this->salary = salary;
        global_id++;
    }

    int get_id()
    {
        return id;
    }

    string get_name()
    {
        return name;
    }

    float get_salary()
    {
        return salary;
    }

    void print()
    {
        cout << name << " | " << id << " | " << salary << endl;
    }
};

int main()
{
    MyStack<person> st;
    person a("Sultan Mahamud", 569.56);
    person b("Shikhar Mahamud", 698.54);
    person c("Shakil Mahamud", 256.36);
    st.push(a);
    st.push(b);
    st.push(c);

    while (!st.empty())
    {
        person print_obj;
        print_obj = st.pop();
        print_obj.print();
    }
}