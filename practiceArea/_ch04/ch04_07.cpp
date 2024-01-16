#include <iostream>
using namespace std;

// Fibonacci Polynomail
int fibonacci(int x) {

    if (x == 0) {
        /* code */
        return 0;
    } else if (x == 1) {
        /* code */
        return 1;
    }
    return fibonacci(x - 1) + fibonacci(x - 2);
}

/*
    0 1 2 3 4 5 6 7  8  9
    0 1 1 2 3 5 8 13 21 34
*/

int main() {

    cout << "Please enter fibonacci: ";
    int n;
    cin >> n;
    cout << "Fibonacci(" << n << "): " << fibonacci(n) << endl;
    cout << endl;
    return 0;
}