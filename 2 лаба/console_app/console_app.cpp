// console_app.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Graham.h"
#include "is_palindrom.h"
int main() {
	system("chcp 1251"); // настраиваем кодировку консоли
	setlocale(LC_ALL, "Russian"); // задаём русский текст
	int choice;
	std::cout << "\x1b[32mВыберите действие, которое вы хотите (1 - палиндром, 2 - Алгоритм Грэхэма): \x1b[0m";
	std::cin >> choice;
	std::cin.ignore();
	if (choice == 1) {
		std::cout << "\x1b[35mВведите текст, который вы хотите проверить на палиндром: \x1b[0m";
		std::string text;
		std::getline(std::cin, text);
		while (text != "!") {
			if (is_palindrom(text)) std::cout << "\x1b[32mВведенное слово является палиндромом\x1b[0m\n";
			else std::cout << "\x1b[31mВведенное слово НЕ палиндром\x1b[0m\n";
			std::cout << "\x1b[35mВведите текст, который вы хотите проверить на палиндром: \x1b[0m";
			std::getline(std::cin, text);
		}
	}
	else if (choice == 2) {
		Graham();
	}
	system("pause");
}
