#include <iostream>
#include <vector>
#include "Deque.h"
#include <algorithm>
#include "SPoint.h"


using namespace std;

// Детерминант для проверки на правый/левый поворот
double formula(const SPoint& A, const SPoint& B, const SPoint& C) {
    return (B.get_x() - A.get_x()) * (C.get_y() - A.get_y()) -
        (B.get_y() - A.get_y()) * (C.get_x() - A.get_x());
}

void sort_points(vector<SPoint>& points) {
    int n = points.size();

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (points[j].get_x() > points[j + 1].get_x()||
                (points[j].get_x() == points[j + 1].get_x() && points[j].get_y() > points[j + 1].get_y())) {
                swap(points[j], points[j + 1]);
            }
        }
    }
}
void sort_angles(vector<SPoint>& points, SPoint P0) {
    for (int i = 0; i < points.size() - 1; i++) {
        for (int j = 1; j < points.size() - i - 1; j++) {
            if (atan2(points[j + 1].get_y() - P0.get_y(), points[j + 1].get_x() - P0.get_x()) <
                atan2(points[j].get_y() - P0.get_y(), points[j].get_x() - P0.get_x())) {
                SPoint temp = points[j + 1];
                points[j + 1] = points[j];
                points[j] = temp;
            }
        }
    }
}


// Основная функция для построения выпуклой оболочки
void Graham() {
    Deque<SPoint> my_deque;
    short int N;
    std::cout << "Enter the number of points: ";
    std::cin >> N;

    // Ввод точек
    std::vector<SPoint> points;
    for (short int i = 0; i < N; i++) {
        double x, y;
        std::cout << "Enter the X and Y coordinates of the point:";
        std::cin >> x >> y;
        points.push_back(SPoint(x, y));
    }

    sort_points(points);
    SPoint P0 = points[0];
    sort_angles(points, P0);

    std::cout << "Sorted points: ";
    for (auto el : points) {
        std::cout << "( " << el.get_x() << " " << el.get_y() << " ), ";
    }
    std::cout << std::endl;
    my_deque.push_back(P0);

    for (int i = 1; i < points.size(); ++i) {
        while (my_deque.size() >= 2 && formula(my_deque.back()->prev->value, my_deque.back()->value, points[i]) <= 0) {
            my_deque.pop_back(); // Удаляем точки, которые не составляют поворот влево
        }
        my_deque.push_back(points[i]);
    }

    if (my_deque.back()->value != my_deque.front()->value) {
        my_deque.push_back(my_deque.front()->value);
    }

    size_t my_deque_size = my_deque.size();
    for (short int i = 0; i < my_deque_size; i++) {
        std::cout  << "( " << my_deque.front()->value.get_x() << " " << my_deque.front()->value.get_y() << " ) " << " " << std::endl;
        my_deque.pop_front();
    }
}
