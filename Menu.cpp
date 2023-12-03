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
			editStudentMenu();
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
	cin.ignore();
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
		cin.ignore();
		subject = Validator::getValidStr();

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
	cin.ignore();
	string name = Validator::convertName();
	

	Student studentToDelete = StudentSet::getInstance()->searchByName(name);

	if (studentToDelete.getName() != "") {
		StudentSet::getInstance()->removeStudent(studentToDelete);
		cout << "������� ������� ������!" << endl;
	}
	else {
		cout << "������ �������� ��� � ���� ������!" << endl;
	}

}

void Menu::editStudentName()
{
	cout << "������� ��� ��������, �������� �� ������ ���������������: ";
	cin.ignore();
	string name = Validator::convertName();

	Student editedStudent = StudentSet::getInstance()->searchByName(name);

	if (editedStudent.getName() != "") {
		cout << "������� ������ ��������:\n";
		editedStudent.print();

		cout << "����� ���: ";
		string newName = Validator::convertName();
		editedStudent.setName(newName);

		// ������ ��������� � StudentSet
		StudentSet::getInstance()->editStudentName(editedStudent, name);
		cout << "����� ������ ��������: " << endl;
		editedStudent.print();
	}
	else {
		cout << "������ �������� ��� � ���� ������!" << endl;
	}
}

void Menu::editStudentGroup()
{
	cout << "������� ��� ��������, �������� �� ������ ���������������: ";
	cin.ignore();
	string name = Validator::convertName();

	Student editedStudent = StudentSet::getInstance()->searchByName(name);

	if (editedStudent.getName() != "") {
		cout << "������� ������ ��������:\n";
		editedStudent.print();

		cout << "����� ����� ������: ";
		int newGroupNum = Validator::getIntVar(100000, 999999);
		editedStudent.setGroupNum(newGroupNum);

		// ������ ��������� � StudentSet
		StudentSet::getInstance()->editStudentName(editedStudent, name);
		cout << "����� ������ ��������: " << endl;
		editedStudent.print();
	}
	else {
		cout << "������ �������� ��� � ���� ������!" << endl;
	}
	
}

void Menu::editStudentGrade()
{
	cout << "������� ��� ��������, �������� �� ������ ���������������: ";
	cin.ignore();
	string name = Validator::convertName();

	Student editedStudent = StudentSet::getInstance()->searchByName(name);

	if (editedStudent.getName() != "") {
		cout << "������� ������ ��������:\n";
		editedStudent.print();

		cout << "������� �������, ������ �������� �� ������ ��������������� (�������� �������): ";
		string subjectToEdit = Validator::getValidStr();

		multimap<string, int>& grades = editedStudent.getGrades();
		bool isSubjectFound = false;
		for (auto it = grades.begin(); it != grades.end(); ++it) {
			if (it->first == subjectToEdit) {
				cout << "������� ����� ������ ��� �������� " << subjectToEdit << " (������� � ������ ����� ������): ";
				int newGrade = Validator::getIntVar(0, 10);

				// ��������� ������ ��� ��������
				it->second = newGrade;
				isSubjectFound = true;
			}
		}
		if (!isSubjectFound) {
			cout << "������� �� ������!" << endl;
			return;
		}
		// ������ ��������� � StudentSet
		StudentSet::getInstance()->editStudentName(editedStudent, name);
		cout << "����� ������ ��������: " << endl;
		editedStudent.print();
	}
	else {
		cout << "������ �������� ��� � ���� ������!" << endl;
	}
}

void Menu::editStudentMenu()
{
	cout << left << "��� �� ������ ��������? " << endl;
	cout << "1 - ���" << endl;
	cout << "2 - ����� ������" << endl;
	cout << "3 - �������� � ������" << endl;
	cout << "0 - �����" << endl;
	int choice = Validator::getIntVar(0, 3);
	switch (choice) {
	case 1:
		editStudentName();
		break;
	case 2:
		editStudentGroup();
		break;
	case 3:
		editStudentGrade();
		break;
	case 0:
		return;
	}
}

void Menu::searchMenu()
{
	while (true)
	{
		cout << left << "�� ���� �������� �����? " << endl;
		cout << "1 - ���" << endl;
		cout << "2 - ����� ������" << endl;
		cout << "3 - �������� ��������" << endl;
		cout << "0 - �����" << endl;
		int choice = Validator::getIntVar(0, 3);
		switch (choice) {
		case 1: {
			cout << "������� ��� ��������: ";
			cin.ignore();
			string name = Validator::convertName();
			Student student = StudentSet::getInstance()->searchByName(name);
			if (student.getName() != "") {
				cout << "������� ������!" << endl;
				student.print();
			}
			else {
				cout << "������ �������� ��� � ���� ������!" << endl;
			}
		}
			break;
		case 2: {
			cout << "������� ����� ������: ";
			int groupNum = Validator::getIntVar(100000, 999999);
			set<Student> students = StudentSet::getInstance()->searchByGroupNum(groupNum);
			if (!students.empty()) {
				cout << "�������� �������!" << endl;
				for (auto& student : students) {
					student.print();
				}	
			}
			else {
				cout << "������ �������� ��� � ���� ������!" << endl;
			}
		}
			break;
		case 3:
		{
			cout << "������� �������� ��������: ";
			cin.ignore();
			string subject;
			getline(cin, subject);
			set<Student> students = StudentSet::getInstance()->searchBySubject(subject);
			if (!students.empty()) {
				cout << "�������� �������!" << endl;
				for (auto& student : students) {
					student.print();
				}
			}
			else {
				cout << "����� ��������� ��� � ���� ������!" << endl;
			}
		}
			break;
		case 0:
			return;
		}
	}
}
