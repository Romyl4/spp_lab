#include <iostream>

using namespace std;

int main() {
    int h;
    cout << "Введіть висоту піраміди: ";
    cin >> h;

    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= h - i; ++j) {
            cout << " ";

        }

        for (int j = 1; j <= i; ++j) {
            cout << "*";
        }

        for (int j = i + 1; j <= 2 * i - 1; ++j) {
            cout << i - 1;
        }

        cout << endl;
    }

    return 0;
}
