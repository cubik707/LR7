#include "Menu.h"

void Menu::showMenu()
{
	while (true)
	{
		cout << left << "Меню: " << endl;
		cout << "1 - Вывод данных" << endl;
		cout << "2 - Добавить данные" << endl;
		cout << "3 - Удалить данные" << endl;
		cout << "4 - Редактировать данные" << endl;
		cout << "5 - Поиск" << endl;
		cout << "6 - Сортировка" << endl;
		cout << "0 - Назад" << endl;
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

	cout << "Введите имя студента: ";
	cin.ignore();
	name = Validator::getValidStr();
	Validator::convert(name);

	cout << "Введите номер группы: ";
	group_num = Validator::getIntVar(0, 999999);

	Student student(name, group_num);

	int choice;
	do {
		string subject;
		int grade;

		cout << "Введите предмет: ";
		cin.ignore();
		subject = Validator::getValidStr();

		cout << "Введите оценку: ";
		grade = Validator::getIntVar(0, 10);

		student.addGrade(subject, grade);

		cout << "Хотите добавить еще оценку? (0 - нет /1 - да): ";
		choice = Validator::getIntVar(0, 1);
	} while (choice == 1);

	StudentSet::getInstance()->addStudent(student);

	cout << "Студент успешно добавлен!" << endl;
}

void Menu::removeStudent()
{
	cout << "Введите имя студента, которого вы хотите удалить: ";
	cin.ignore();
	string name = Validator::convertName();
	

	Student studentToDelete = StudentSet::getInstance()->searchByName(name);

	if (studentToDelete.getName() != "") {
		StudentSet::getInstance()->removeStudent(studentToDelete);
		cout << "Студент успешно удален!" << endl;
	}
	else {
		cout << "Такого студента нет в базе данных!" << endl;
	}

}

void Menu::editStudentName()
{
	cout << "Введите имя студента, которого вы хотите отредактировать: ";
	cin.ignore();
	string name = Validator::convertName();

	Student editedStudent = StudentSet::getInstance()->searchByName(name);

	if (editedStudent.getName() != "") {
		cout << "Текущие данные студента:\n";
		editedStudent.print();

		cout << "Новое имя: ";
		string newName = Validator::convertName();
		editedStudent.setName(newName);

		// Вносим изменения в StudentSet
		StudentSet::getInstance()->editStudentName(editedStudent, name);
		cout << "Новые данные студента: " << endl;
		editedStudent.print();
	}
	else {
		cout << "Такого студента нет в базе данных!" << endl;
	}
}

void Menu::editStudentGroup()
{
	cout << "Введите имя студента, которого вы хотите отредактировать: ";
	cin.ignore();
	string name = Validator::convertName();

	Student editedStudent = StudentSet::getInstance()->searchByName(name);

	if (editedStudent.getName() != "") {
		cout << "Текущие данные студента:\n";
		editedStudent.print();

		cout << "Новый номер группы: ";
		int newGroupNum = Validator::getIntVar(100000, 999999);
		editedStudent.setGroupNum(newGroupNum);

		// Вносим изменения в StudentSet
		StudentSet::getInstance()->editStudentName(editedStudent, name);
		cout << "Новые данные студента: " << endl;
		editedStudent.print();
	}
	else {
		cout << "Такого студента нет в базе данных!" << endl;
	}
	
}

void Menu::editStudentGrade()
{
	cout << "Введите имя студента, которого вы хотите отредактировать: ";
	cin.ignore();
	string name = Validator::convertName();

	Student editedStudent = StudentSet::getInstance()->searchByName(name);

	if (editedStudent.getName() != "") {
		cout << "Текущие данные студента:\n";
		editedStudent.print();

		cout << "Введите предмет, оценки которого вы хотите отредактировать (учитывая регистр): ";
		string subjectToEdit = Validator::getValidStr();

		multimap<string, int>& grades = editedStudent.getGrades();
		bool isSubjectFound = false;
		for (auto it = grades.begin(); it != grades.end(); ++it) {
			if (it->first == subjectToEdit) {
				cout << "Введите новые оценки для предмета " << subjectToEdit << " (предмет и оценка через пробел): ";
				int newGrade = Validator::getIntVar(0, 10);

				// Обновляем оценки для предмета
				it->second = newGrade;
				isSubjectFound = true;
			}
		}
		if (!isSubjectFound) {
			cout << "Предмет не найден!" << endl;
			return;
		}
		// Вносим изменения в StudentSet
		StudentSet::getInstance()->editStudentName(editedStudent, name);
		cout << "Новые данные студента: " << endl;
		editedStudent.print();
	}
	else {
		cout << "Такого студента нет в базе данных!" << endl;
	}
}

void Menu::editStudentMenu()
{
	cout << left << "Что вы хотите изменить? " << endl;
	cout << "1 - Имя" << endl;
	cout << "2 - Номер группы" << endl;
	cout << "3 - Предметы и оценки" << endl;
	cout << "0 - Назад" << endl;
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
		cout << left << "По чему провести посик? " << endl;
		cout << "1 - Имя" << endl;
		cout << "2 - Номер группы" << endl;
		cout << "3 - Название предмета" << endl;
		cout << "0 - Назад" << endl;
		int choice = Validator::getIntVar(0, 3);
		switch (choice) {
		case 1: {
			cout << "Введите имя студента: ";
			cin.ignore();
			string name = Validator::convertName();
			Student student = StudentSet::getInstance()->searchByName(name);
			if (student.getName() != "") {
				cout << "Студент найден!" << endl;
				student.print();
			}
			else {
				cout << "Такого студента нет в базе данных!" << endl;
			}
		}
			break;
		case 2: {
			cout << "Введите номер группы: ";
			int groupNum = Validator::getIntVar(100000, 999999);
			set<Student> students = StudentSet::getInstance()->searchByGroupNum(groupNum);
			if (!students.empty()) {
				cout << "Студенты найдены!" << endl;
				for (auto& student : students) {
					student.print();
				}	
			}
			else {
				cout << "Такого студента нет в базе данных!" << endl;
			}
		}
			break;
		case 3:
		{
			cout << "Введите название предмета: ";
			cin.ignore();
			string subject;
			getline(cin, subject);
			set<Student> students = StudentSet::getInstance()->searchBySubject(subject);
			if (!students.empty()) {
				cout << "Студенты найдены!" << endl;
				for (auto& student : students) {
					student.print();
				}
			}
			else {
				cout << "Таких студентов нет в базе данных!" << endl;
			}
		}
			break;
		case 0:
			return;
		}
	}
}
