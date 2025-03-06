#include <iostream>
#include <string>
#include <set>
#include <Windows.h>
using namespace std;

class Student {
public:
	string name;
	int rating;

	Student(string name, int rating) {
		this->name = name;
		this->rating = rating;
	}

	bool operator==(const Student& other) const {
		return this->name == other.name;
	}
	
	bool operator<(const Student& other) const {
		return this->name < other.name;
	}
};


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	set<Student> Students;
	
	while (1) {
		printf("Введите ваши действия (1 - Добавить студентов, 2 - Просмотреть результаты тестов)\n");
		int choice;
		cin >> choice;
		cin.ignore();
		string data; // сюда помещаем информацию: имя | рейтинг
		string name; // имя
		int rating; // рейтинг

		switch (choice) {
		case 1:
			printf_s("Введите своё имя и рейтинг. Формат следующий: Имя | Рейтинг\n");
			getline(cin, data);
			while (data != "stop") {	
				try {
					name = data.substr(0, data.find(" | "));
					string rating_string = data.substr(data.find("| ") + 2);
					rating = stoi(rating_string);
					Students.insert(Student(name, rating));
				}
				catch (std::invalid_argument& error) {
					std::cout << "Произошла ошибка. Введите данные еще раз!\n";
				}
				getline(cin, data);
			}
			break;
		case 2:
			for (auto el : Students) {
				std::cout << el.name << " | " << el.rating << std::endl;
			}
			break;
		}
		std::cout << std::endl << std::endl;
	}
}