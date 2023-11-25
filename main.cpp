#include "Menu.h"
#include <Windows.h>

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");

	StudentSet::getInstance()->readFromFile();
	Menu menu;
	menu.showMenu();

	return 0;
}