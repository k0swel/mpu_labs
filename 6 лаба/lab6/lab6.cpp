#include <iostream>
#include <map>
#include <list>
#include <string>
#include <chrono>
#include <thread>
#include <limits>
#include <windows.h>
#undef max
using std::string;
using std::cin;
using std::map;
using std::cout;
using std::endl;

void task_map() {
	std::cout << "\t\tМЕНЮ\t\t\n";
	std::cout << "1)\tВвести предложение\t\n";
	std::cout << "2)\tПроцентное соотношение каждого слова в предложении\t\n";
	std::cout << "3)\tВыход\t\n";

	int choice = 0;
	cin >> choice;
	cin.ignore(); // убираем из ввода символ перехода строки.

	std::list<char> special_symbols = { '|', '/', '-', '\\' }; // для прогресс бара. 3 пункт меню.
	string sentence;
	string word;
	map<std::string, int> words;
	while (choice == 1 or choice == 2 or choice == 3) {
		int count_of_words = 0;
		switch (choice) {
		case 1:
			words.clear();
			std::cout << "Введите ваше предложение:";
			getline(cin, sentence); // запрашиваем у пользователя текст до \n
			sentence += '\n';
			for (auto symbol : sentence) {
				if (strchr("?\"!., \n", symbol) == nullptr)
					word += symbol;

				if (!word.empty() and strchr("\"?!,. \n", symbol) and words.find(word) == words.end()) { // если конец предложения и слова нет в map.
					words[word] = 1;
					count_of_words++;
					word.clear();
					continue;
				}

				if (!word.empty() and strchr("\"?!, .\n", symbol) and words.find(word) != words.end()) { // если конец предложения и слово в map.
					words[word] = ++words[word];
					count_of_words++;
					word.clear();
					continue;
				}
			}
			break;
		case 2:
			if (count_of_words == 0) {
				std::cout << "Введите какой-то текст!\n";
				break;
			}
			cout << "Всего слов в предложении: " << count_of_words << endl;
			for (auto el : words) {
				std::cout << "Слово \x1b[33m" << el.first << "\x1b[0m: " << static_cast<double>(el.second) * 100 / count_of_words << "%. Встречается " << el.second << " раз." << endl;
			}
			break;
		case 3:
			for (int i = 1; i <= 4; i++) {
				std::cout << "\rВыхожу из программы: " << special_symbols.front();
				special_symbols.pop_front();
				std::this_thread::sleep_for(std::chrono::seconds(1));
			}
			exit(3);
		}
		std::cout << "Выберите действие: ";
		cin >> choice;
		while (!(choice >= 1 and choice <= 3)) {
			std::cout << "Введите выбор корректно: ";
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // убираем из ввода символ перехода строки.
			cin >> choice;
		}
	}
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	task_map();
}

