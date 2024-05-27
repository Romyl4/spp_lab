#include "headers.h"

// Реалізація методів класу Point
Point::Point(double x, double y) : x(x), y(y) {}

void Point::move(double dx, double dy) {
    x += dx;
    y += dy;
}

void Point::resize(double factor) {
    std::cerr << "Resize not applicable for Point." << std::endl;
}

void Point::setColor(const std::string& color) {
    std::cerr << "SetColor not applicable for Point." << std::endl;
}

void Point::rotate(double angle) {
    std::cerr << "Rotate not applicable for Point." << std::endl;
}

void Point::display() const {
    std::cout << "Point(" << x << ", " << y << ")" << std::endl;
}

// Реалізація методів класу Circle
Circle::Circle(double x, double y, double radius, const std::string& color)
    : Point(x, y), radius(radius), color(color) {}

void Circle::resize(double factor) {
    radius *= factor;
}

void Circle::setColor(const std::string& color) {
    this->color = color;
}

void Circle::rotate(double angle) {
    std::cerr << "Rotate not applicable for Circle." << std::endl;
}

void Circle::display() const {
    std::cout << "Circle at (" << x << ", " << y << ") with radius " << radius << " and color " << color << std::endl;
}

// Реалізація методів класу Sphere
Sphere::Sphere(double x, double y, double radius, const std::string& color)
    : Point(x, y), radius(radius), color(color) {}

void Sphere::resize(double factor) {
    radius *= factor;
}

void Sphere::setColor(const std::string& color) {
    this->color = color;
}

void Sphere::rotate(double angle) {
    std::cerr << "Rotate not applicable for Sphere." << std::endl;
}

void Sphere::display() const {
    std::cout << "Sphere at (" << x << ", " << y << ") with radius " << radius << " and color " << color << std::endl;
}

void menu() {
    std::cout << "1. Create Point" << std::endl;
    std::cout << "2. Create Circle" << std::endl;
    std::cout << "3. Create Sphere" << std::endl;
    std::cout << "4. Move Object" << std::endl;
    std::cout << "5. Resize Object" << std::endl;
    std::cout << "6. Change Color" << std::endl;
    std::cout << "7. Rotate Object" << std::endl;
    std::cout << "8. Display Object" << std::endl;
    std::cout << "9. Exit" << std::endl;
}

int main() {
    Point* obj = nullptr;
    int choice;
    double x, y, radius, dx, dy, factor, angle;
    std::string color;

    while (true) {
        menu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter coordinates (x y): ";
            std::cin >> x >> y;
            obj = new Point(x, y);
            break;
        case 2:
            std::cout << "Enter coordinates (x y), radius, and color: ";
            std::cin >> x >> y >> radius >> color;
            obj = new Circle(x, y, radius, color);
            break;
        case 3:
            std::cout << "Enter coordinates (x y), radius, and color: ";
            std::cin >> x >> y >> radius >> color;
            obj = new Sphere(x, y, radius, color);
            break;
        case 4:
            if (obj) {
                std::cout << "Enter move offsets (dx dy): ";
                std::cin >> dx >> dy;
                obj->move(dx, dy);
            }
            else {
                std::cerr << "No object created." << std::endl;
            }
            break;
        case 5:
            if (obj) {
                std::cout << "Enter resize factor: ";
                std::cin >> factor;
                obj->resize(factor);
            }
            else {
                std::cerr << "No object created." << std::endl;
            }
            break;
        case 6:
            if (obj) {
                std::cout << "Enter new color: ";
                std::cin >> color;
                obj->setColor(color);
            }
            else {
                std::cerr << "No object created." << std::endl;
            }
            break;
        case 7:
            if (obj) {
                std::cout << "Enter rotation angle: ";
                std::cin >> angle;
                obj->rotate(angle);
            }
            else {
                std::cerr << "No object created." << std::endl;
            }
            break;
        case 8:
            if (obj) {
                obj->display();
            }
            else {
                std::cerr << "No object created." << std::endl;
            }
            break;
        case 9:
            delete obj;
            return 0;
        default:
            std::cerr << "Invalid choice." << std::endl;
        }
    }

    return 0;
}
