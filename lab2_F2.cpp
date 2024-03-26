#include <iostream>

using namespace std;

template <typename T>
T factorial(T n) {
    T result = 1;
    for (T j = 1; j <= n; ++j) {
        result *= j;
    }
    return result;
}

int main() {

    setlocale(LC_ALL, "rus");
    int n;
    long long factorial_n, factorial_neg_n;

    cout << "Введіть n: ";
    cin >> n;

    factorial_n = factorial(n);
    factorial_neg_n = factorial(n);

    cout << n << "!! = " << factorial_n << endl;
    cout << "(-1)^" << n << "+1" << " * " << n << "!! = " << (-1) * factorial_neg_n << endl;

    return 0;
}
