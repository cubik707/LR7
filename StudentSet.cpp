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
//
//bool StudentSet::hasStudent(const string& studentName)
//{
//    Student dummyStudent(studentName, 0);
//    return students.find(dummyStudent) != students.end();
//}

Student StudentSet::searchByName(const string& studentName)
{
    auto it = find_if(students.begin(), students.end(), [&studentName](const Student& student) {
        return student.getName() == studentName;
        });
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

void StudentSet::editStudentName(Student student, const string& name)
{
    Student existingStudent = searchByName(name);
    // Удаляем старого студента из набора
    students.erase(existingStudent);
    // Добавляем отредактированного студента в набор
    students.insert(student);

    cout << "Студент успешно отредактирован!" << endl;
}


//void StudentSet::printTableFields(int length)
//{
//    printLine(length);
//    cout << setw(5) << "| №" << setw(18) << "| Имя";
//    cout << setw(10) << "| Группа" << "| Предмет | Оценки |" << endl;
//    printLine(length);
//}

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

void StudentSet::printContainerItem(int index)
{
    int length = 137, i = 1;

    printLine(length);
    auto it = students.begin();
    advance(it, index);
    cout << left << setw(5) << "| " + to_string(i++);
    it->print();
    printLine(length);
}
