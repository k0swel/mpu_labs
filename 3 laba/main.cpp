#include <iostream>
#include "MyQueue.cpp"
//Напечатать в порядке возрастания первые n натуральных чисел, в разложение которых на простые множители входят только 2, 3 и 5.

// N = 10: 2 3 4 5 6 8 9 10 12 15 

int min(int q2, int q3, int q5) {
    int list_number[3] = { q2, q3, q5 };
    for (int i = 0; i < sizeof(list_number) / sizeof(int) - 1; i++) {
        for (int j = 0; j < (sizeof(list_number) / sizeof(int) - 1) - i; j++) {
            if (list_number[j] > list_number[j + 1]) {
                int temp = list_number[i];
                list_number[j] = list_number[j + 1];
                list_number[j + 1] = temp;
            }
        }
    }
    return list_number[0];
}

void Foo() {
    MyQueue<int> q_2;
    q_2.push_back(2);
    MyQueue<int> q_3;
    q_3.push_back(3);
    MyQueue<int> q_5;
    q_5.push_back(5);

    MyQueue<int> res;
    short int N;
    std::cout << "Введите число N: ";
    std::cin >> N;

    while (res.size() < N) {
        int temp = min(q_2.get_front(), q_3.get_front(), q_5.get_front());
        res.push_back(temp);
        q_2.push_back(2 * temp);
        q_3.push_back(3 * temp);
        q_5.push_back(5 * temp);

        if (q_2.get_front() == temp) {
            q_2.pop_front();
        }

        if (q_3.get_front() == temp) {
            q_3.pop_front();
        }

        if (q_5.get_front() == temp) {
            q_5.pop_front();
        }
    }

    size_t res_size = res.size();
    for (int i = 0; i < res_size; i++) {
        std::cout << res.get_front() << " ";
        res.pop_front();
    }

}


int main()
{
    system("chcp 1251");
    setlocale(LC_ALL, "ru_RU.UTF-8");
    Foo();
    system("pause");
}
