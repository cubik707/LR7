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

set<Student>& StudentSet::getStudents()
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
    if (!file.eof() && file.fail())
    {
        throw runtime_error("Ошибка в чтении строки.");
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

Student StudentSet::searchByName(const string& studentName)
{
    auto it = find_if(students.begin(), students.end(), [&studentName](const Student& student) {
        return student.getName() == studentName;
        });
    return (it != students.end()) ? *it : Student(); // Если не найдено, возвращаем пустой объект Student
}

set<Student> StudentSet::searchByGroupNum(int studentGroupNum)
{
    set<Student> matchingStudent;
    for (const auto& student : students)
    {
        if (student.getGroupNum() == studentGroupNum)
        {   
            matchingStudent.insert(student);
            
        }
    }
    return matchingStudent;
}


void StudentSet::addStudent(const Student& student)
{
    students.insert(student);
}

void StudentSet::removeStudent(const Student& student)
{
    students.erase(student);
}

void StudentSet::editStudentName(Student student, const string& name)
{
    Student existingStudent = searchByName(name);
    // Удаляем старого студента из набора
    students.erase(existingStudent);
    // Добавляем отредактированного студента в набор
    students.insert(student);

    cout << "Студент успешно отредактирован!" << endl;
}

void StudentSet::printStudentSet()
{
    int length = 137, i = 1;
    printLine(length);
    for (auto& student : students) {
        cout << left << setw(5) << "| " + to_string(i++);
        student.print();
    }    
    printLine(length);
}
