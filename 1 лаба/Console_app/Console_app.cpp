#include "Stack.h"
#include "Node.h"
#include <string>
#include <iostream>

bool is_corrent_math_example(std::string& example) {
	short index = 0;
	Stack<char> my_stack;
	while (example[index] != '\0') {
		if (example[index] == '(' or example[index] == '{' or example[index] == '[') {
			my_stack.push(example[index]);
		}
		else if (example[index] == ')' or example[index] == '}' or example[index] == ']') {
			if (example[index] == ')' and my_stack.top() == '(') {
				my_stack.pop();
			}
			else if (example[index] == '}' and my_stack.top() == '{') {
				my_stack.pop();
			}
			else if (example[index] == ']' and my_stack.top() == '[') {
				my_stack.pop();
			}
			else {
				my_stack.clear();
				return false;
			}
		}
		index++;
	}
	if (my_stack.isEmpty())
		return true;
	else {
		my_stack.clear();
		return false;
	}

}

int main()
{
	system("chcp 1251");
	setlocale(LC_ALL, "ru_RU.UTF-8");

	std::string text;
	std::cout << "Пожалуйста, введите математические выражение(допустимы скобки - '{' ; '}' ; '(' ; ') ; '[' ; ']'\n";
	std::getline(std::cin, text);
	while (text != "!") {
		if (is_corrent_math_example(text))
			std::cout << "\x1b[32mВведенное выражение составлено ВЕРНО.\x1b[0m\n" << std::endl;
		else
			std::cout << "\x1b[31mВыражение составлено НЕВЕРНО.\x1b[0m\n" << std::endl;
		std::getline(std::cin, text);
	}
	std::cout << "\x1b[34mВыполнение программы завершено\x1b[0m" << std::endl;
	system("pause");
}


//int main()
//{
//	system("chcp 1251");
//	setlocale(LC_ALL, "ru_RU.UTF-8");
//
//	std::string text;
//	std::cout << "Пожалуйста, введите математические выражение(допустимы скобки - '{' ; '}' ; '(' ; ') ; '[' ; ']'\n";
//	std::getline(std::cin, text);
//	if (is_corrent_math_example(text))
//		std::cout << "\x1b[32myes\x1b[0m\n" << std::endl;
//	else
//		std::cout << "\x1b[31mno\x1b[0m\n" << std::endl;
//	std::cout << "Выполнение программы завершено" << std::endl;
//	system("pause");
//}

