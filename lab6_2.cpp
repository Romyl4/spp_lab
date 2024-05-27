#include <iostream>
#include <set>
#include <algorithm>

class Set {
private:
    std::set<int> elements;

public:
    // Конструктор за замовчуванням
    Set() = default;

    // Конструктор з параметрами
    Set(const std::initializer_list<int>& init_list) : elements(init_list) {}

    // Конструктор копії
    Set(const Set& other) : elements(other.elements) {}

    // Оператор присвоювання
    Set& operator=(const Set& other) {
        if (this != &other) {
            elements = other.elements;
        }
        return *this;
    }

    // Оператор порівняння
    bool operator==(const Set& other) const {
        return elements == other.elements;
    }

    bool operator!=(const Set& other) const {
        return !(*this == other);
    }

    // Додавання елемента
    void add(int element) {
        elements.insert(element);
    }

    // Видалення елемента
    void remove(int element) {
        elements.erase(element);
    }

    // Оператор об'єднання множин
    Set operator+(const Set& other) const {
        Set result = *this;
        result.elements.insert(other.elements.begin(), other.elements.end());
        return result;
    }

    // Оператор об'єднання та присвоювання
    Set& operator+=(const Set& other) {
        elements.insert(other.elements.begin(), other.elements.end());
        return *this;
    }

    // Виведення множини
    void print() const {
        std::cout << "{ ";
        for (const int& elem : elements) {
            std::cout << elem << " ";
        }
        std::cout << "}" << std::endl;
    }
};

int main() {
    Set set1 = { 1, 2, 3, 4 };
    Set set2 = { 3, 4, 5, 6 };

    set1.print();
    set2.print();

    Set set3 = set1 + set2;
    set3.print();

    set1 += set2;
    set1.print();

    set1.add(7);
    set1.print();

    set1.remove(3);
    set1.print();

    if (set1 == set2) {
        std::cout << "set1 and set2 are equal" << std::endl;
    }
    else {
        std::cout << "set1 and set2 are not equal" << std::endl;
    }

    return 0;
}
