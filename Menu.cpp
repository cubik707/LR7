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
		subject = Validator::getValidStr();
		Validator::convert(subject);

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
	string name = Validator::getValidStr();
	Validator::convert(name);

	Student studentToDelete = StudentSet::getInstance()->searchByName(name);

	if (studentToDelete.getName() != "") {
		StudentSet::getInstance()->removeStudent(studentToDelete);
		cout << "Студент успешно удален!" << endl;
	}
	else {
		cout << "Такого студента нет в базе данных!" << endl;
	}

}
