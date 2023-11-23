#include "Student.h"

void Student::addGrade(const string& subject, int grade)
{
	grades.insert({ subject, grade });
}

ostream& operator<<(ostream& out, const Student& student)
{
    out << student.name << "|" << student.group_num << "|";
    for (const auto& grade : student.grades)
    {
        out << grade.first << "|" << grade.second << "|";
    }

    return out << endl;
}

istream& operator>>(istream& is, Student& student)
{
    getline(is, student.name, '|');
    is >> student.group_num;
    is.ignore(1, '|');

    string subject;
    int grade;

    while (is >> subject >> grade)
    {
        student.grades.insert({ subject, grade });
    }

    is.ignore(1, '\n');
    return is;
}
