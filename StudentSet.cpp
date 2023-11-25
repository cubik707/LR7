#include "StudentSet.h"

StudentSet* StudentSet::instance = nullptr;

StudentSet* StudentSet::getInstance()
{
    if (!instance)
    {
        instance = new StudentSet();
    }
    return instance;
}

StudentSet::~StudentSet()
{
    if (instance)
    {
        delete instance;
        instance = nullptr;
    }
}

set<Student> StudentSet::getStudents()
{
    return students;
}

void StudentSet::readFromFile()
{
    ifstream file;
    try
    {
        file.open("students.txt");

        if (file.bad())
        {
            throw runtime_error("Ошибка в открытии файла.");
        }
        if (file.good())
        {
            fillSetFromFile(file);
        }

        file.close();
    }
    catch (const runtime_error& e)
    {
        cout << e.what() << endl;
        exit(0);
    }
}

void StudentSet::fillSetFromFile(ifstream& file)
{
    students.clear();

    Student student;
    while (file >> student)
    {
        students.insert(student);
    }
}

void StudentSet::writeInFile()
{
    ofstream file;
    try
    {
        file.open("students.txt", ios::out | ios::trunc);

        if (file.bad())
        {
            throw runtime_error("Ошибка в открытии файла для записи.");
        }

        for (const auto& student : students)
        {
            file << student;
        }

        file.close();
    }
    catch (const runtime_error& e)
    {
        cerr << e.what() << endl;
        exit(0);
    }
}
//
//bool StudentSet::hasStudent(const string& studentName)
//{
//    Student dummyStudent(studentName, 0);
//    return students.find(dummyStudent) != students.end();
//}

Student StudentSet::searchByName(const string& studentName)
{
    Student dummyStudent(studentName, 0);
    auto it = students.find(dummyStudent);
    return (it != students.end()) ? *it : Student(); // Если не найдено, возвращаем пустой объект Student
}

Student StudentSet::searchByGroupNum(int studentGroupNum)
{
    for (const auto& student : students)
    {
        if (student.getGroupNum() == studentGroupNum)
        {
            return student;
        }
    }
    return Student(); // Если не найдено, возвращаем пустой объект Student
}


void StudentSet::addStudent(const Student& student)
{
    students.insert(student);
}

void StudentSet::removeStudent(const Student& student)
{
    students.erase(student);
}


void StudentSet::printTableFields(int length)
{
    printLine(length);
    cout << setw(5) << "| №" << setw(18) << "| Имя";
    cout << setw(10) << "| Группа" << "| Предмет | Оценки |" << endl;
    printLine(length);
}

void StudentSet::printStudentSet()
{
    int length = 42, i = 1;

    printTableFields(length);
    for (auto& student : students) {
        cout << left << setw(5) << "| " + to_string(i++);
        student.print();
        cout << endl;
    }     
}

void StudentSet::printContainerItem(int length, int index)
{
    int length = 42, i = 1;

    printTableFields(length);
    auto it = students.begin();
    advance(it, index);
    cout << left << setw(5) << "| " + to_string(i++);
    it->print();
    cout << endl;
}
