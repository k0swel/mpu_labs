// console_app.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Graham.h"
#include "is_palindrom.h"
int main() {
	system("chcp 1251");
	setlocale(LC_ALL, "ru_RU.UTF-8");
	int choice;
	std::cout << "Выберите действие, которое вы хотите (1 - палиндром, 2 - какой-то алгоритм): ";
	std::cin >> choice;
	if (choice == 1) {
		std::cin.ignore();
		std::cout << "Введите текст, который вы хотите проверить на палиндром: ";
		std::string text;
		std::getline(std::cin, text);
		while (text != "!") {
			if (is_palindrom(text)) std::cout << "\x1b[32mВведенное слово является палиндромом\x1b[0m\n";
			else std::cout << "\x1b[31mВведенное слово НЕ палиндром\x1b[0m\n";
			std::cin >> text;
		}
	}
	else if (choice == 2) {
		Graham();
	}
	system("pause");
}
