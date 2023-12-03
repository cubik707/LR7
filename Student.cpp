#include "Student.h"


void Student::addGrade(const string& subject, int grade)
{
	grades.insert({ subject, grade });
}

void Student::print() const
{
    cout.setf(ios::left);
    cout << "| " << setw(31) << name;
    cout << "| " << setw(8) << group_num;
    cout << "|";

    // Выводим уникальные предметы и все оценки по каждому предмету
    for (auto it = grades.begin(); it != grades.end();)
    {
        cout << it->first << " : ";

        // Выводим все оценки по текущему предмету
        auto range = grades.equal_range(it->first);
        for (auto innerIt = range.first; innerIt != range.second; ++innerIt)
        {
            cout << innerIt->second << " ";
        }

        // Переходим к следующему предмету
        it = range.second;
        if (it != grades.end())
        {
            cout << ", ";
        }
    }
    cout << endl;
    cout.unsetf(ios::left);
}


bool Student::operator<(const Student& other) const
{
    return name < other.name || (name == other.name && group_num < other.group_num);
}

bool Student::operator==(const Student& other) const
{
    return name == other.name;
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

    student.grades.clear();
    string subject;
    int grade;
    string gradesLine;
    getline(is, gradesLine);

    istringstream gradesStream(gradesLine);

    while (gradesStream >> subject >> grade)
    {
        student.grades.insert({ subject, grade });
    }
    return is;
}
