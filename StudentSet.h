#pragma once
#include "Student.h"
#include <set>
#include "Validator.h"

class StudentSet
{
private:
    static StudentSet* instance;
    set<Student> students;

    StudentSet() {}
    StudentSet(const StudentSet&) = delete;
    StudentSet& operator=(const StudentSet&) = delete;

public:
    static StudentSet* getInstance();

    ~StudentSet();

    set<Student>& getStudents();

    void readFromFile();
    void fillSetFromFile(ifstream& file);
    void writeInFile();

    Student searchByName(const string& studentName);
    set<Student> searchByGroupNum(int studentGroupNum);

    void addStudent(const Student& student);
    void removeStudent(const Student& student);
    void editStudentName(Student student, const string& name);

    void printStudentSet();

};