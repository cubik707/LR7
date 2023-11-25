#include "Student.h"

bool Student::hasSubject(const string& subject) const
{
    return grades.find(subject) != grades.end();
}

void Student::addGrade(const string& subject, int grade)
{
	grades.insert({ subject, grade });
}

void Student::print() const
{
    cout.setf(ios::left);
    cout << "| " << setw(18) << name;
    cout << "| " << setw(8) << group_num;

    // ������� ���������� �������� � ��� ������ �� ������� ��������
    for (auto it = grades.begin(); it != grades.end();)
    {
        cout << "| " << it->first << "| ";

        // ������� ��� ������ �� �������� ��������
        auto range = grades.equal_range(it->first);
        for (auto innerIt = range.first; innerIt != range.second; ++innerIt)
        {
            cout << innerIt->second << " ";
        }

        // ��������� � ���������� ��������
        it = range.second;
        cout << "|";
    }

    cout << endl;
    cout.unsetf(ios::left);
}

bool Student::operator<(const Student& other) const
{
    return name < other.name || (name == other.name && group_num < other.group_num);
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

    //is.ignore(1, '\n');
    return is;
}
