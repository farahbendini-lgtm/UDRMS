#include "university.hpp"
#include <stdexcept>
#include <fstream>

University::University()
{
    name = "";
    studentCount = 0;
    dormitoryCount = 0;
}

University::University(string n)
{
    name = n;
    studentCount = 0;
    dormitoryCount = 0;
}

void University::setName(string n)
{
    name = n;
}

string University::getName() const
{
    return name;
}

void University::addStudent(const Student &s)
{
    if(studentCount >= 1000)
    {
        throw runtime_error("Maximum number of students reached");
    }

    students[studentCount] = s;
    studentCount++;
}

void University::removeStudent(int id)
{
    int position = -1;

    for(int i = 0; i < studentCount; i++)
    {
        if(students[i].getId() == id)
        {
            position = i;
            break;
        }
    }

    if(position == -1)
    {
        throw runtime_error("Student not found");
    }

    for(int i = position; i < studentCount - 1; i++)
    {
        students[i] = students[i + 1];
    }

    studentCount--;
}

Student* University::searchStudent(int id)
{
    for(int i = 0; i < studentCount; i++)
    {
        if(students[i].getId() == id)
        {
            return &students[i];
        }
    }

    return nullptr;
}

Student* University::searchStudentByIndex(int index)
{
    if (index < 0 || index >= studentCount) {
        return nullptr;
    }
    return &students[index];
}

int University::getStudentCount() const
{
    return studentCount;
}

void University::addDormitory(const Dormitory &d)
{
    dormitories[dormitoryCount] = d;
    dormitoryCount++;
}

bool University::removeDormitory(const string &n)
{
    int position = -1;
    for(int i = 0; i < dormitoryCount; i++)
    {
        if(dormitories[i].getName() == n)
        {
            position = i;
            break;
        }
    }
    if(position == -1) return false;

    for(int i = position; i < dormitoryCount - 1; i++)
    {
        dormitories[i] = dormitories[i + 1];
    }
    dormitoryCount--;
    return true;
}

int University::getDormitoryCount() const
{
    return dormitoryCount;
}

Dormitory& University::getDormitoryAt(int index)
{
    return dormitories[index];
}

Dormitory* University::findDormitoryByName(const string &n)
{
    for(int i = 0; i < dormitoryCount; i++)
    {
        if(dormitories[i].getName() == n)
        {
            return &dormitories[i];
        }
    }
    return nullptr;
}

void University::displayStudents() const
{
    cout << "\n===== STUDENTS =====\n";

    for(int i = 0; i < studentCount; i++)
    {
        students[i].display();
        cout << endl;
    }
}

void University::displayDormitories() const
{
    cout << "\n===== DORMITORIES =====\n";

    for(int i = 0; i < dormitoryCount; i++)
    {
        dormitories[i].displayDormitory();
        cout << endl;
    }
}
void University::saveStudents() const
{
    ofstream file("students.txt");

    if(!file)
    {
        throw runtime_error("Cannot open students file");
    }

    for(int i = 0; i < studentCount; i++)
    {
        file
            << students[i].getId() << " "
            << students[i].getName() << " "
            << students[i].getYear() << " "
            << students[i].getDormitory() << " "
            << students[i].getRoom()
            << endl;
    }

    file.close();
}
void University::loadStudents()
{
    ifstream file("students.txt");

    if(!file)
    {
        throw runtime_error("Cannot open students file");
    }

    studentCount = 0;

    int id;
    string name;
    int year;
    string dormitory;
    int room;

    while(file >> id >> name >> year >> dormitory >> room)
    {
        students[studentCount] =
            Student(id,name,year,dormitory,room);

        studentCount++;
    }

    file.close();
}
void University::saveDormitories() const
{
    ofstream file("dormitories.txt");

    if(!file)
    {
        throw runtime_error("Cannot open dormitories file");
    }

    for(int i = 0; i < dormitoryCount; i++)
    {
        file
            << dormitories[i].getName() << " "
            << dormitories[i].getCapacity()
            << endl;
    }

    file.close();
}
void University::loadDormitories()
{
    ifstream file("dormitories.txt");

    if(!file)
    {
        throw runtime_error("Cannot open dormitories file");
    }

    dormitoryCount = 0;

    string name;
    int capacity;

    while(file >> name >> capacity)
    {
        dormitories[dormitoryCount] =
            Dormitory(name,capacity);

        dormitoryCount++;
    }

    file.close();
}