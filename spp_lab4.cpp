#include <iostream>
#include <string>

using namespace std;

class Transport {
protected:
    string model;
    int year;

public:
    Transport(string model, int year) : model(model), year(year) {}

    void turn() {
        setlocale(LC_CTYPE, "ukr");
        cout << "Поворот транспорту\n";
    }

    void go() {
        setlocale(LC_CTYPE, "ukr");
        cout << "Транспорт їде\n";
    }
};

class Bicycle : public Transport {
public:
    Bicycle(string model, int year) : Transport(model, year) {}

    void turn() {
        setlocale(LC_CTYPE, "ukr");
        cout << "Поворот велосипеда\n";
    }

    void go() {
        setlocale(LC_CTYPE, "ukr");
        cout << "Велосипед їде\n";
    }
};

int main() {
    setlocale(LC_CTYPE, "ukr");
    Bicycle bike("Bike", 2024);

    bike.turn();
    bike.go();

    return 0;
}
