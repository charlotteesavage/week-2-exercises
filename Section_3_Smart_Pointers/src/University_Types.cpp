#include <memory>
#include <iostream>
#include <string>
#include "University_Types.h"

using namespace std;

Student::Student(const std::string &n) : name(n), id(max_id++) {}

Student::~Student()
{
    cout << "Student " << name << " destroyed." << endl;
}

int Student::getId() const
{
    return id;
}

// Static variables need to be initialised outside their class declaration
int Student::max_id = 0;

Department::Department(const std::string &n) : name(n) {}

Department::~Department()
{
    cout << "Department " << name << " destroyed." << endl;
}