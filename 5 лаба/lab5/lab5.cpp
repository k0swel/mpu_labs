#include <iostream>
#include "list.cpp"

using namespace std;

struct Student {
    Student(string group_t, string surname_t) : group(group_t), surname(surname_t) {}
    string group;
    string surname;
    Student() {}
};

bool find_el_in_list(List<string>& groups, string group) {
    for (int i = 0; i < groups.get_size(); i++) {
        if (groups[i] == group) {
            return true;
        }
    }
    return false;
}


int main() {
    system("chcp 1251");
    //setlocale(LC_ALL, "rus");
    List<Student> students;
    List<string>groups;
    int choice;

    while (true) {
        std::cout << "\t\t\tМЕНЮ\t\t\t" << std::endl;
        std::cout << "\t\tВыберите действие\t\t" << std::endl;
        std::cout << "1. Добавить студентов в массив" << std::endl;
        std::cout << "2. Вывести студентов в консоль" << std::endl;
        std::cout << "3. Выйти из программы" << std::endl;

        int choice;
        cin >> choice;
        cin.ignore();
        std::string group, surname; // for case 1
        switch (choice) {
        case 1:
            std::cout << "P.S Если вы хотите перестать добавлять студентов, просто введите ""stop ."" " << std::endl;
            std::cout << "Введите студента в следующем формате: <Группа (пробел) Фамилия>" << std::endl;
            cin >> group >> surname;
            while (group != "stop") {
                Student person(group, surname);
                students.push_back(person);
                cin >> group >> surname;
            }
            break;

        case 2:
            std::cout << "Вывожу информацию о студентах в консоль..." << std::endl;

            // сначала добавляем номера групп в лист
            for (int index = 0; index < students.get_size(); index++) {
                if (!find_el_in_list(groups, students[index].group)) {
                    groups.push_back(students[index].group);
                }
            }
            // теперь выводим студентов
            for (int c = 0; c < groups.get_size(); c++) {
                for (int index = 0; index < students.get_size(); index++) {
                    if (students[index].group == groups[c]) {
                        std::cout << students[index].group << " " << students[index].surname << std::endl;
                    }
                }
            }
            break;

        case 3:
            return 0;
        }
    }

    return 0;
}
