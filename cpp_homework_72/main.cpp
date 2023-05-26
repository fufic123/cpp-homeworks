#include <iostream>
#include <set>

template<typename T>
class Point {
private:
    T x;
    T y;

public:
    Point(T x, T y) : x(x), y(y) {}

    T getX() const {
        return x;
    }

    T getY() const {
        return y;
    }

    bool operator<(const Point& other) const {
        if (x < other.x)
            return true;
        else if (x == other.x && y < other.y)
            return true;
        return false;
    }
};

int main() {
    std::set<Point<int>> pointSet;

    // Добавление элементов в множество
    pointSet.insert(Point<int>(1, 2));
    pointSet.insert(Point<int>(3, 4));
    pointSet.insert(Point<int>(5, 6));
    pointSet.insert(Point<int>(7, 8));
    pointSet.insert(Point<int>(9, 10));

    // Вывод элементов множества на экран
    std::cout << "Элементы множества Point:\n";
    for (const auto& point : pointSet) {
        std::cout << "X: " << point.getX() << ", Y: " << point.getY() << std::endl;
    }

    // Поиск одного из элементов множества
    Point<int> searchPoint(5, 6);
    auto it = pointSet.find(searchPoint);
    if (it != pointSet.end()) {
        std::cout << "Найден элемент: X: " << it->getX() << ", Y: " << it->getY() << std::endl;
    } else {
        std::cout << "Элемент не найден." << std::endl;
    }

    return 0;
}
