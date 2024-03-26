#include <iostream>

using namespace std;

int factorial(int n) {
    int result = 1;
    for (int j = 1; j <= n; ++j) {
        result *= j;
    }
    return result;
}

int main() {
    setlocale(LC_ALL, "rus");
    int n, factorial_n, factorial_neg_n;

    cout << "Введіть n: ";
    cin >> n;

    factorial_n = factorial(n);
    factorial_neg_n = factorial(n);

    cout << n << "!! = " << factorial_n << endl;
    cout << "(-1)^" << n << "+1" << " * " << n << "!! = " << (-1) * factorial_neg_n << endl;

    return 0;
}
