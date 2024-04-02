#include <iostream>
#include <cmath>

class Vec3D { // Оголошення класу Vector3D для роботи з тривимірними векторами
private:
    double x, y, z; // оголошення змфінних типу дабль
public:
    Vec3D() : x(0.0), y(0.0), z(0.0) {} // ініціалізуємо всі координати нулями
    Vec3D(double x_val, double y_val, double z_val) : x(x_val), y(y_val), z(z_val) {}

    Vec3D operator+(const Vec3D& o) const {
        return Vec3D(x + o.x, y + o.y, z + o.z); // Повертає новий вектор зі сумою координат
    }
    Vec3D operator-(const Vec3D& o) const {
        return Vec3D(x - o.x, y - o.y, z - o.z); // Повертає новий вектор з різницею координат
    }
    double dot(const Vec3D& o) const { // функція для обчислення скалярного добутку векторів
        return x * o.x + y * o.y + z * o.z; // Повертає результат скалярного добутку
    }

    double len() const { // функція для обчислення довжини вектора
        return std::sqrt(x * x + y * y + z * z); // Повертає довжину вектора
    }

    double cosAngle(const Vec3D& o) const {
        return dot(o) / (len() * o.len()); // Повертає косинус кута
    }

    void print() const { // функція для виведення координат вектора
        std::cout << "(" << x << ", " << y << ", " << z << ")" << std::endl; // Виводить координати вектора у форматі (x, y, z)
    }
};

int main() {
    setlocale(LC_ALL, "Russian"); // щоб кирилицю ввиодило
    Vec3D v1(3.0, 3.0, 5.0); // Створення першого вектора
    Vec3D v2(1.0, 8.0, 9.0); // Створення другого вектора 

    std::cout << "Вектор 1: "; // Виведення інформації про перший вектор
    v1.print();
    std::cout << "Вектор 2: "; // Виведення інформації про другий вектор
    v2.print();

    Vec3D sum = v1 + v2; // Обчислення суми векторів
    std::cout << "Сума векторів: ";
    sum.print();

    Vec3D diff = v1 - v2;
    std::cout << "Різниця векторів: ";
    diff.print();

    double dot = v1.dot(v2);
    std::cout << "Скалярний добуток векторів: " << dot << std::endl;

    double len = v1.len();
    std::cout << "Довжина вектора 1: " << len << std::endl;

    double cos_angle = v1.cosAngle(v2);
    std::cout << "Косинус кута між векторами: " << cos_angle << std::endl;

    return 0;
}
