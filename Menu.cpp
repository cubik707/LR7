#include "Menu.h"

void Menu::showMenu()
{
	while (true)
	{
		cout << left << "����: " << endl;
		cout << "1 - ����� ������" << endl;
		cout << "2 - �������� ������" << endl;
		cout << "3 - ������� ������" << endl;
		cout << "4 - ������������� ������" << endl;
		cout << "5 - �����" << endl;
		cout << "6 - ����������" << endl;
		cout << "0 - �����" << endl;
		int choice = Validator::getIntVar(0, 6);
		switch (choice) {
		case 1:
			StudentSet::getInstance()->printStudentSet();
			break;
		case 2:
			addStudent();
			break;
		case 3:
			removeStudent();
			break;
		case 4:
			
			break;
		case 5:
			
			break;
		case 6:
			
			break;
		case 0:
			return;
		}
	}
}

void Menu::addStudent()
{
	string name;
	int group_num;

	cout << "������� ��� ��������: ";
	name = Validator::getValidStr();
	Validator::convert(name);

	cout << "������� ����� ������: ";
	group_num = Validator::getIntVar(0, 999999);

	Student student(name, group_num);

	int choice;
	do {
		string subject;
		int grade;

		cout << "������� �������: ";
		subject = Validator::getValidStr();
		Validator::convert(subject);

		cout << "������� ������: ";
		grade = Validator::getIntVar(0, 10);

		student.addGrade(subject, grade);

		cout << "������ �������� ��� ������? (0 - ��� /1 - ��): ";
		choice = Validator::getIntVar(0, 1);
	} while (choice == 1);

	StudentSet::getInstance()->addStudent(student);

	cout << "������� ������� ��������!" << endl;
}

void Menu::removeStudent()
{
	cout << "������� ��� ��������, �������� �� ������ �������: ";
	string name = Validator::getValidStr();
	Validator::convert(name);

	Student studentToDelete = StudentSet::getInstance()->searchByName(name);

	if (studentToDelete.getName() != "") {
		StudentSet::getInstance()->removeStudent(studentToDelete);
		cout << "������� ������� ������!" << endl;
	}
	else {
		cout << "������ �������� ��� � ���� ������!" << endl;
	}

}
